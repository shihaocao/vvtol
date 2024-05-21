#include <state_field_registry.hpp>
#include <task.hpp>
#include <downlink_task.hpp>

#ifdef NATIVE
#include <chrono>
#include "native_only/named_pipe_manager.hpp"
#endif

#include <vector>
#include <atomic>

#include "air_nano_proto/air_nano_proto.hpp"
// #include <pb_common.h>
#include <pb_encode.h>
// #include <nanopb/state_field_registry.pb.h>
#include <state_field_registry.pb.h>

#ifndef NATIVE
#include <HardwareSerial.h>
#endif
#ifdef NATIVE
NamedPipeManager npm("/tmp/vvtol_downlink");
#endif

DownlinkTask::DownlinkTask(StateFields &sfr) : sfr_(sfr)
{
}

void DownlinkTask::setup()
{
#ifndef NATIVE
    log() << "Downlink setup complete" << '\n';
#endif

    // No one uses serial 8 so you can just set it up...?
#ifdef USE_RADIO
    Serial2.begin(57600);
#endif
};

bool encode_float_array(pb_ostream_t *stream, const pb_field_t *field, void *const *arg)
{
    // Retrieve the array passed as 'arg'
    const std::array<float, 3> *array = static_cast<const std::array<float, 3> *>(*arg);

    // Write each float element to the stream
    for (float element : *array)
    {
        if (!pb_encode_tag_for_field(stream, field))
        {
            return false; // Encoding failure: unable to write the tag
        }

        if (!pb_encode_fixed32(stream, &element))
        {
            return false; // Encoding failure: unable to write the float value
        }
    }

    return true; // Encoding successful
}
static bool decode_float_array(pb_istream_t *stream, const pb_field_t *field, void **arg)
{
    return false;
}

static void link_downlink_sfr(SFVector3f &field, bool &has_field, Vector3f *sfr_field_addr)
{
    field.elements.arg = sfr_field_addr;
    field.elements.funcs.encode = encode_float_array;
    has_field = true;
}

void DownlinkTask::execute()
{
    StateFieldRegistry state_field_registry = StateFieldRegistry_init_zero;
    state_field_registry.mcl_control_cycle_num = sfr_.mcl_control_cycle_num;
    // state_field_registry.imu_gyr_vec = sfr_.imu_gyr_vec;
    state_field_registry.time_t_average_cycle_time_us = sfr_.imu_gyr_vec[0];

    // std::array<float, 3> foo = {1, 2, 3};
    state_field_registry.imu_gyr_vec.elements.arg = &sfr_.imu_gyr_vec;
    state_field_registry.imu_gyr_vec.elements.funcs.encode = &encode_float_array;
    state_field_registry.has_imu_gyr_vec = true;

    link_downlink_sfr(state_field_registry.imu_acc_vec_f,
                      state_field_registry.has_imu_acc_vec_f,
                      &sfr_.imu_acc_vec_f);

    AirProto air_proto;

    int status = air_proto.serialize_to_buffer(state_field_registry);
    // log() << "Ser status " << status << '\n';
    // log() << "Ser data:\n";
#ifndef NATIVE
#ifdef USE_RADIO
    // log() << "Use radio\n";
    Serial2.write(air_proto.data(), air_proto.size()); // Write the buffer to the serial port.
#else
    Serial.write(air_proto.data(), air_proto.size()); // Write the buffer to the serial port.
#endif
#endif

#ifdef NATIVE
    npm.writeToPipe(air_proto.data(), air_proto.size());
#endif
    // log() << "End ser data\n";
}