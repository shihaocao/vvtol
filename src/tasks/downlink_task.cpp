#include <state_field_registry.hpp>
#include <task.hpp>
#include <downlink_task.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

#include "air_nano_proto/air_nano_proto.hpp"
// #include <pb_common.h>
#include <pb_encode.h>
// #include <nanopb/state_field_registry.pb.h>
#include <state_field_registry.pb.h>

DownlinkTask::DownlinkTask(StateFields &sfr) : sfr_(sfr)
{
}

void DownlinkTask::setup()
{
#ifndef NATIVE
    log() << "Downlink setup complete" << '\n';
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
void DownlinkTask::execute()
{
    StateFieldRegistry state_field_registry = StateFieldRegistry_init_zero;
    state_field_registry.mcl_control_cycle_num = sfr_.mcl_control_cycle_num;
    // state_field_registry.imu_gyr_vec = sfr_.imu_gyr_vec;
    state_field_registry.time_t_average_cycle_time_us = sfr_.imu_gyr_vec[0];

    // std::array<float, 3> foo = {1, 2, 3};
    state_field_registry.imu_gyr_vec.elements.arg = &sfr_.imu_gyr_vec;
    state_field_registry.imu_gyr_vec.elements.funcs.encode = &encode_float_array;
    // state_field_registry.imu_gyr_vec.elements.funcs.decode = &decode_float_array;
    state_field_registry.has_imu_gyr_vec = true;
    AirProto air_proto;

    int status = air_proto.serialize_to_buffer(state_field_registry);
    log() << "Ser status " << status << '\n';
    log() << "Ser data:\n";
    Serial.write(air_proto.data(), air_proto.size()); // Write the buffer to the serial port.
    log() << "End ser data\n";
}