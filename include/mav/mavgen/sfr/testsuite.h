/** @file
 *    @brief MAVLink comm protocol testsuite generated from sfr.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef SFR_TESTSUITE_H
#define SFR_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_sfr(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_sfr(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_state_field_registry(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_STATE_FIELD_REGISTRY >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_state_field_registry_t packet_in = {
        93372036854775807ULL,93372036854776311ULL,129.0,963498504,963498712,213.0,241.0,269.0,297.0,325.0,353.0,381.0,409.0,437.0,465.0,493.0,521.0,549.0,577.0,605.0,633.0,661.0
    };
    mavlink_state_field_registry_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.last_transition_ccno = packet_in.last_transition_ccno;
        packet1.mcl_control_cycle_num = packet_in.mcl_control_cycle_num;
        packet1.time_t_average_cycle_time_us = packet_in.time_t_average_cycle_time_us;
        packet1.time_t_control_cycle_limit_us = packet_in.time_t_control_cycle_limit_us;
        packet1.time_t_last_cycle_end_us = packet_in.time_t_last_cycle_end_us;
        packet1.imu_linear_acc_vec_f_x = packet_in.imu_linear_acc_vec_f_x;
        packet1.imu_linear_acc_vec_f_y = packet_in.imu_linear_acc_vec_f_y;
        packet1.imu_linear_acc_vec_f_z = packet_in.imu_linear_acc_vec_f_z;
        packet1.imu_acc_vec_f_x = packet_in.imu_acc_vec_f_x;
        packet1.imu_acc_vec_f_y = packet_in.imu_acc_vec_f_y;
        packet1.imu_acc_vec_f_z = packet_in.imu_acc_vec_f_z;
        packet1.imu_gyr_vec_x = packet_in.imu_gyr_vec_x;
        packet1.imu_gyr_vec_y = packet_in.imu_gyr_vec_y;
        packet1.imu_gyr_vec_z = packet_in.imu_gyr_vec_z;
        packet1.imu_euler_vec_x = packet_in.imu_euler_vec_x;
        packet1.imu_euler_vec_y = packet_in.imu_euler_vec_y;
        packet1.imu_euler_vec_z = packet_in.imu_euler_vec_z;
        packet1.imu_euler_vec_w = packet_in.imu_euler_vec_w;
        packet1.imu_quat_x = packet_in.imu_quat_x;
        packet1.imu_quat_y = packet_in.imu_quat_y;
        packet1.imu_quat_z = packet_in.imu_quat_z;
        packet1.imu_quat_w = packet_in.imu_quat_w;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_field_registry_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_state_field_registry_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_field_registry_pack(system_id, component_id, &msg , packet1.time_t_average_cycle_time_us , packet1.time_t_control_cycle_limit_us , packet1.time_t_last_cycle_end_us , packet1.last_transition_ccno , packet1.mcl_control_cycle_num , packet1.imu_linear_acc_vec_f_x , packet1.imu_linear_acc_vec_f_y , packet1.imu_linear_acc_vec_f_z , packet1.imu_acc_vec_f_x , packet1.imu_acc_vec_f_y , packet1.imu_acc_vec_f_z , packet1.imu_gyr_vec_x , packet1.imu_gyr_vec_y , packet1.imu_gyr_vec_z , packet1.imu_euler_vec_x , packet1.imu_euler_vec_y , packet1.imu_euler_vec_z , packet1.imu_euler_vec_w , packet1.imu_quat_x , packet1.imu_quat_y , packet1.imu_quat_z , packet1.imu_quat_w );
    mavlink_msg_state_field_registry_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_field_registry_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_t_average_cycle_time_us , packet1.time_t_control_cycle_limit_us , packet1.time_t_last_cycle_end_us , packet1.last_transition_ccno , packet1.mcl_control_cycle_num , packet1.imu_linear_acc_vec_f_x , packet1.imu_linear_acc_vec_f_y , packet1.imu_linear_acc_vec_f_z , packet1.imu_acc_vec_f_x , packet1.imu_acc_vec_f_y , packet1.imu_acc_vec_f_z , packet1.imu_gyr_vec_x , packet1.imu_gyr_vec_y , packet1.imu_gyr_vec_z , packet1.imu_euler_vec_x , packet1.imu_euler_vec_y , packet1.imu_euler_vec_z , packet1.imu_euler_vec_w , packet1.imu_quat_x , packet1.imu_quat_y , packet1.imu_quat_z , packet1.imu_quat_w );
    mavlink_msg_state_field_registry_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_state_field_registry_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_state_field_registry_send(MAVLINK_COMM_1 , packet1.time_t_average_cycle_time_us , packet1.time_t_control_cycle_limit_us , packet1.time_t_last_cycle_end_us , packet1.last_transition_ccno , packet1.mcl_control_cycle_num , packet1.imu_linear_acc_vec_f_x , packet1.imu_linear_acc_vec_f_y , packet1.imu_linear_acc_vec_f_z , packet1.imu_acc_vec_f_x , packet1.imu_acc_vec_f_y , packet1.imu_acc_vec_f_z , packet1.imu_gyr_vec_x , packet1.imu_gyr_vec_y , packet1.imu_gyr_vec_z , packet1.imu_euler_vec_x , packet1.imu_euler_vec_y , packet1.imu_euler_vec_z , packet1.imu_euler_vec_w , packet1.imu_quat_x , packet1.imu_quat_y , packet1.imu_quat_z , packet1.imu_quat_w );
    mavlink_msg_state_field_registry_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("STATE_FIELD_REGISTRY") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_STATE_FIELD_REGISTRY) != NULL);
#endif
}

static void mavlink_test_sfr(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_state_field_registry(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // SFR_TESTSUITE_H
