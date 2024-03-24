/** @file
 *	@brief MAVLink comm testsuite protocol generated from sfr.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "sfr.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(sfr, STATE_FIELD_REGISTRY)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::sfr::msg::STATE_FIELD_REGISTRY packet_in{};
    packet_in.time_t_average_cycle_time_us = 129.0;
    packet_in.time_t_control_cycle_limit_us = 963498504;
    packet_in.time_t_last_cycle_end_us = 963498712;
    packet_in.last_transition_ccno = 93372036854775807ULL;
    packet_in.mcl_control_cycle_num = 93372036854776311ULL;
    packet_in.imu_linear_acc_vec_f_x = 213.0;
    packet_in.imu_linear_acc_vec_f_y = 241.0;
    packet_in.imu_linear_acc_vec_f_z = 269.0;
    packet_in.imu_acc_vec_f_x = 297.0;
    packet_in.imu_acc_vec_f_y = 325.0;
    packet_in.imu_acc_vec_f_z = 353.0;
    packet_in.imu_gyr_vec_x = 381.0;
    packet_in.imu_gyr_vec_y = 409.0;
    packet_in.imu_gyr_vec_z = 437.0;
    packet_in.imu_euler_vec_x = 465.0;
    packet_in.imu_euler_vec_y = 493.0;
    packet_in.imu_euler_vec_z = 521.0;
    packet_in.imu_euler_vec_w = 549.0;
    packet_in.imu_quat_x = 577.0;
    packet_in.imu_quat_y = 605.0;
    packet_in.imu_quat_z = 633.0;
    packet_in.imu_quat_w = 661.0;

    mavlink::sfr::msg::STATE_FIELD_REGISTRY packet1{};
    mavlink::sfr::msg::STATE_FIELD_REGISTRY packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_t_average_cycle_time_us, packet2.time_t_average_cycle_time_us);
    EXPECT_EQ(packet1.time_t_control_cycle_limit_us, packet2.time_t_control_cycle_limit_us);
    EXPECT_EQ(packet1.time_t_last_cycle_end_us, packet2.time_t_last_cycle_end_us);
    EXPECT_EQ(packet1.last_transition_ccno, packet2.last_transition_ccno);
    EXPECT_EQ(packet1.mcl_control_cycle_num, packet2.mcl_control_cycle_num);
    EXPECT_EQ(packet1.imu_linear_acc_vec_f_x, packet2.imu_linear_acc_vec_f_x);
    EXPECT_EQ(packet1.imu_linear_acc_vec_f_y, packet2.imu_linear_acc_vec_f_y);
    EXPECT_EQ(packet1.imu_linear_acc_vec_f_z, packet2.imu_linear_acc_vec_f_z);
    EXPECT_EQ(packet1.imu_acc_vec_f_x, packet2.imu_acc_vec_f_x);
    EXPECT_EQ(packet1.imu_acc_vec_f_y, packet2.imu_acc_vec_f_y);
    EXPECT_EQ(packet1.imu_acc_vec_f_z, packet2.imu_acc_vec_f_z);
    EXPECT_EQ(packet1.imu_gyr_vec_x, packet2.imu_gyr_vec_x);
    EXPECT_EQ(packet1.imu_gyr_vec_y, packet2.imu_gyr_vec_y);
    EXPECT_EQ(packet1.imu_gyr_vec_z, packet2.imu_gyr_vec_z);
    EXPECT_EQ(packet1.imu_euler_vec_x, packet2.imu_euler_vec_x);
    EXPECT_EQ(packet1.imu_euler_vec_y, packet2.imu_euler_vec_y);
    EXPECT_EQ(packet1.imu_euler_vec_z, packet2.imu_euler_vec_z);
    EXPECT_EQ(packet1.imu_euler_vec_w, packet2.imu_euler_vec_w);
    EXPECT_EQ(packet1.imu_quat_x, packet2.imu_quat_x);
    EXPECT_EQ(packet1.imu_quat_y, packet2.imu_quat_y);
    EXPECT_EQ(packet1.imu_quat_z, packet2.imu_quat_z);
    EXPECT_EQ(packet1.imu_quat_w, packet2.imu_quat_w);
}

#ifdef TEST_INTEROP
TEST(sfr_interop, STATE_FIELD_REGISTRY)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_state_field_registry_t packet_c {
         93372036854775807ULL, 93372036854776311ULL, 129.0, 963498504, 963498712, 213.0, 241.0, 269.0, 297.0, 325.0, 353.0, 381.0, 409.0, 437.0, 465.0, 493.0, 521.0, 549.0, 577.0, 605.0, 633.0, 661.0
    };

    mavlink::sfr::msg::STATE_FIELD_REGISTRY packet_in{};
    packet_in.time_t_average_cycle_time_us = 129.0;
    packet_in.time_t_control_cycle_limit_us = 963498504;
    packet_in.time_t_last_cycle_end_us = 963498712;
    packet_in.last_transition_ccno = 93372036854775807ULL;
    packet_in.mcl_control_cycle_num = 93372036854776311ULL;
    packet_in.imu_linear_acc_vec_f_x = 213.0;
    packet_in.imu_linear_acc_vec_f_y = 241.0;
    packet_in.imu_linear_acc_vec_f_z = 269.0;
    packet_in.imu_acc_vec_f_x = 297.0;
    packet_in.imu_acc_vec_f_y = 325.0;
    packet_in.imu_acc_vec_f_z = 353.0;
    packet_in.imu_gyr_vec_x = 381.0;
    packet_in.imu_gyr_vec_y = 409.0;
    packet_in.imu_gyr_vec_z = 437.0;
    packet_in.imu_euler_vec_x = 465.0;
    packet_in.imu_euler_vec_y = 493.0;
    packet_in.imu_euler_vec_z = 521.0;
    packet_in.imu_euler_vec_w = 549.0;
    packet_in.imu_quat_x = 577.0;
    packet_in.imu_quat_y = 605.0;
    packet_in.imu_quat_z = 633.0;
    packet_in.imu_quat_w = 661.0;

    mavlink::sfr::msg::STATE_FIELD_REGISTRY packet2{};

    mavlink_msg_state_field_registry_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_t_average_cycle_time_us, packet2.time_t_average_cycle_time_us);
    EXPECT_EQ(packet_in.time_t_control_cycle_limit_us, packet2.time_t_control_cycle_limit_us);
    EXPECT_EQ(packet_in.time_t_last_cycle_end_us, packet2.time_t_last_cycle_end_us);
    EXPECT_EQ(packet_in.last_transition_ccno, packet2.last_transition_ccno);
    EXPECT_EQ(packet_in.mcl_control_cycle_num, packet2.mcl_control_cycle_num);
    EXPECT_EQ(packet_in.imu_linear_acc_vec_f_x, packet2.imu_linear_acc_vec_f_x);
    EXPECT_EQ(packet_in.imu_linear_acc_vec_f_y, packet2.imu_linear_acc_vec_f_y);
    EXPECT_EQ(packet_in.imu_linear_acc_vec_f_z, packet2.imu_linear_acc_vec_f_z);
    EXPECT_EQ(packet_in.imu_acc_vec_f_x, packet2.imu_acc_vec_f_x);
    EXPECT_EQ(packet_in.imu_acc_vec_f_y, packet2.imu_acc_vec_f_y);
    EXPECT_EQ(packet_in.imu_acc_vec_f_z, packet2.imu_acc_vec_f_z);
    EXPECT_EQ(packet_in.imu_gyr_vec_x, packet2.imu_gyr_vec_x);
    EXPECT_EQ(packet_in.imu_gyr_vec_y, packet2.imu_gyr_vec_y);
    EXPECT_EQ(packet_in.imu_gyr_vec_z, packet2.imu_gyr_vec_z);
    EXPECT_EQ(packet_in.imu_euler_vec_x, packet2.imu_euler_vec_x);
    EXPECT_EQ(packet_in.imu_euler_vec_y, packet2.imu_euler_vec_y);
    EXPECT_EQ(packet_in.imu_euler_vec_z, packet2.imu_euler_vec_z);
    EXPECT_EQ(packet_in.imu_euler_vec_w, packet2.imu_euler_vec_w);
    EXPECT_EQ(packet_in.imu_quat_x, packet2.imu_quat_x);
    EXPECT_EQ(packet_in.imu_quat_y, packet2.imu_quat_y);
    EXPECT_EQ(packet_in.imu_quat_z, packet2.imu_quat_z);
    EXPECT_EQ(packet_in.imu_quat_w, packet2.imu_quat_w);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
