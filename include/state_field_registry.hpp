#pragma once

#include <stdint.h>

#include <type_defs.hpp>

// Design idea: do not nest structs inside structs, just pass around a flat SFR
// all control logic should read from the SFR
// logic inside control tasks should pull references from the SFR
// if they must they can create a construct to reference the SFR
// but at the global level, this should remain flat

// design idea, dont use any unsigned ints.
// Generally, going negative is much safer than rolling over and going to zero

// enforce namspacing via prefixes
struct StateFieldRegistry
{
    float time_t_average_cucle_time_us = -1;
    int time_t_control_cycle_limit_us = 100000;
    uint32_t time_t_last_cycle_end_us = 0;
    uint64_t last_transition_ccno = 0;
    uint64_t mcl_control_cycle_num = 0;

    MainControl::State mc_state = MainControl::EMPTY;
    MainControl::State target_mc_state = MainControl::EMPTY;

    GncControl::State gnc_state = GncControl::State::EMPTY;
    GncControl::State target_gnc_state = GncControl::State::EMPTY;

    Vector3f imu_linear_acc_vec_f{};
    Vector3f imu_acc_vec_f{};
    Vector3f imu_gyr_vec{};
    Vector4f imu_euler_vec{};
    Vector4d imu_quat{};

    // Vector4f imu_rot_vec_quat{};
    // float imu_rot_vec_accurac = 0;

    // Vector4f imu_game_rot_vec_quat{};

    // Vector4f imu_gyro_int_rot_vec_quat{};
    // Vector3f imu_gyro_int_w_vec{};

    // Vector4f imu_ar_stab_rot_vec_quat{};
};
