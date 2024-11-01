#pragma once

#include <stdint.h>

#include <type_defs.hpp>

#include <lin.hpp>
#include <vvtol_constants.hpp>

// Design idea: do not nest structs inside structs, just pass around a flat SFR
// all control logic should read from the SFR
// logic inside control tasks should pull references from the SFR
// if they must they can create a construct to reference the SFR
// but at the global level, this should remain flat

// design idea, dont use any unsigned ints.
// Generally, going negative is much safer than rolling over and going to zero

// enforce namspacing via prefixes
struct StateFields
{
    int time_t_control_cycle_limit_ms = CONTROL_CYCLE_MS;
    int time_t_control_cycle_limit_us = time_t_control_cycle_limit_ms * 1000;
    float delta_t_s = time_t_control_cycle_limit_ms * S_IN_MS;

    uint32_t time_t_last_cycle_end_us = 0;
    uint64_t last_transition_ccno = 0;

    // MainControl::State mc_state = MainControl::EMPTY;
    // MainControl::State target_mc_state = MainControl::EMPTY;

    // GncControl::State gnc_state = GncControl::State::EMPTY;
    // GncControl::State target_gnc_state = GncControl::State::EMPTY;

    // Vector3f imu_linear_acc_vec_f{};
    // Vector3f imu_acc_vec_f{};
    // Vector4f imu_euler_vec{};
    // Vector4d imu_quat{};

    /*[[[cog
    import cog
    import psrc.sfr_gen.sfr_gen as sfr_gen
    sfr_gen.header_gen_all()
    ]]]*/
    float time_t_average_cycle_time_us{};
    uint32_t mcl_control_cycle_num{};
    uint32_t mcl_now_ts_ms{};
    MainControl::State mc_state{};
    MainControl::State target_mc_state{};
    GncControl::State gnc_state{};
    GncControl::State target_gnc_state{};
    uint32_t packed_imu_state{};
    int32_t fin_py_cmd{};
    int32_t fin_ny_cmd{};
    int32_t fin_px_cmd{};
    int32_t fin_nx_cmd{};
    lin::Vector3f zero_vec{};
    lin::Vector3f imu_linear_acc{};
    lin::Vector3f imu_acc{};
    lin::Vector3f imu_gyr_acc{};
    lin::Vector3f imu_euler_vec{};
    lin::Vector4f imu_quat{};
    lin::Vector4f gnc_orientation_target_quat{};
    lin::Vector3f gnc_orientation_error_deg{};
    lin::Vector3f gnc_global_target_error{};
    lin::Vector3f gnc_global_target_pos{};
    lin::Vector3f state_global_pos{};
    lin::Vector3f state_global_vel{};
    lin::Vector3f state_global_acc{};
    lin::Vector3f state_euler_vec{};
    lin::Vector3f gnc_target_global_acc{};
    lin::Vector4f gnc_global_quat{};
    lin::Vector3f gnc_euler_angles{};
    lin::Vector3f sim_global_linear_pos{};
    lin::Vector3f sim_global_linear_vel{};
    lin::Vector3f sim_global_linear_acc{};
    lin::Vector4f sim_global_quat{};
    lin::Vector3f sim_euler_angles{};
    //[[[end]]]

    // float fin_py_cmd;
    // float fin_ny_cmd;
    // float fin_px_cmd;
    // float fin_nx_cmd;

    float lower_motor_cmd;
};
