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

#include <lin.hpp>
#include <downlink_encoders.tpp>

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
    // state_field_registry.time_t_average_cycle_time_us = sfr_.imu_gyr_vec[0];

    /*[[[cog
    import cog
    import psrc.sfr_gen.sfr_gen as sfr_gen
    sfr_gen.downlink_generate_all_output()
    ]]]*/
    state_field_registry.time_t_average_cycle_time_us = sfr_.time_t_average_cycle_time_us;
    state_field_registry.mcl_control_cycle_num = sfr_.mcl_control_cycle_num;
    state_field_registry.mc_state = sfr_.mc_state;
    state_field_registry.target_mc_state = sfr_.target_mc_state;
    state_field_registry.gnc_state = sfr_.gnc_state;
    state_field_registry.target_gnc_state = sfr_.target_gnc_state;
    state_field_registry.packed_imu_state = sfr_.packed_imu_state;
    lin_link_downlink_sfr(state_field_registry.zero_vec,
                          state_field_registry.has_zero_vec,
                          &sfr_.zero_vec);
    lin_link_downlink_sfr(state_field_registry.imu_linear_acc,
                          state_field_registry.has_imu_linear_acc,
                          &sfr_.imu_linear_acc);
    lin_link_downlink_sfr(state_field_registry.imu_acc,
                          state_field_registry.has_imu_acc,
                          &sfr_.imu_acc);
    lin_link_downlink_sfr(state_field_registry.imu_gyr_acc,
                          state_field_registry.has_imu_gyr_acc,
                          &sfr_.imu_gyr_acc);
    lin_link_downlink_sfr(state_field_registry.imu_euler_vec,
                          state_field_registry.has_imu_euler_vec,
                          &sfr_.imu_euler_vec);
    lin_link_downlink_sfr(state_field_registry.imu_quat,
                          state_field_registry.has_imu_quat,
                          &sfr_.imu_quat);
    lin_link_downlink_sfr(state_field_registry.gnc_global_target_pos,
                          state_field_registry.has_gnc_global_target_pos,
                          &sfr_.gnc_global_target_pos);
    lin_link_downlink_sfr(state_field_registry.state_global_pos,
                          state_field_registry.has_state_global_pos,
                          &sfr_.state_global_pos);
    lin_link_downlink_sfr(state_field_registry.state_global_vel,
                          state_field_registry.has_state_global_vel,
                          &sfr_.state_global_vel);
    lin_link_downlink_sfr(state_field_registry.state_global_acc,
                          state_field_registry.has_state_global_acc,
                          &sfr_.state_global_acc);
    lin_link_downlink_sfr(state_field_registry.state_euler_vec,
                          state_field_registry.has_state_euler_vec,
                          &sfr_.state_euler_vec);
    lin_link_downlink_sfr(state_field_registry.gnc_target_global_acc,
                          state_field_registry.has_gnc_target_global_acc,
                          &sfr_.gnc_target_global_acc);
    lin_link_downlink_sfr(state_field_registry.gnc_global_quat,
                          state_field_registry.has_gnc_global_quat,
                          &sfr_.gnc_global_quat);
    lin_link_downlink_sfr(state_field_registry.gnc_euler_angles,
                          state_field_registry.has_gnc_euler_angles,
                          &sfr_.gnc_euler_angles);
    //[[[end]]]

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