#pragma once
// MESSAGE STATE_FIELD_REGISTRY PACKING

#define MAVLINK_MSG_ID_STATE_FIELD_REGISTRY 110


typedef struct __mavlink_state_field_registry_t {
 uint64_t last_transition_ccno; /*<  Last control cycle number of a state transition*/
 uint64_t mcl_control_cycle_num; /*<  Main control loop cycle number*/
 float time_t_average_cycle_time_us; /*< [us] Average control cycle time in microseconds*/
 int32_t time_t_control_cycle_limit_us; /*< [us] Control cycle limit in microseconds*/
 uint32_t time_t_last_cycle_end_us; /*< [us] Timestamp of last control cycle in microseconds*/
 float imu_linear_acc_vec_f_x; /*<  IMU linear acceleration vector X*/
 float imu_linear_acc_vec_f_y; /*<  IMU linear acceleration vector Y*/
 float imu_linear_acc_vec_f_z; /*<  IMU linear acceleration vector Z*/
 float imu_acc_vec_f_x; /*<  IMU acceleration vector X*/
 float imu_acc_vec_f_y; /*<  IMU acceleration vector Y*/
 float imu_acc_vec_f_z; /*<  IMU acceleration vector Z*/
 float imu_gyr_vec_x; /*<  IMU gyroscope vector X*/
 float imu_gyr_vec_y; /*<  IMU gyroscope vector Y*/
 float imu_gyr_vec_z; /*<  IMU gyroscope vector Z*/
 float imu_euler_vec_x; /*<  IMU Euler angles X*/
 float imu_euler_vec_y; /*<  IMU Euler angles Y*/
 float imu_euler_vec_z; /*<  IMU Euler angles Z*/
 float imu_euler_vec_w; /*<  IMU Euler angles W (optional for Euler, used if needed)*/
 float imu_quat_x; /*<  IMU quaternion X*/
 float imu_quat_y; /*<  IMU quaternion Y*/
 float imu_quat_z; /*<  IMU quaternion Z*/
 float imu_quat_w; /*<  IMU quaternion W*/
} mavlink_state_field_registry_t;

#define MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN 96
#define MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN 96
#define MAVLINK_MSG_ID_110_LEN 96
#define MAVLINK_MSG_ID_110_MIN_LEN 96

#define MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC 22
#define MAVLINK_MSG_ID_110_CRC 22



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_STATE_FIELD_REGISTRY { \
    110, \
    "STATE_FIELD_REGISTRY", \
    22, \
    {  { "time_t_average_cycle_time_us", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_state_field_registry_t, time_t_average_cycle_time_us) }, \
         { "time_t_control_cycle_limit_us", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_state_field_registry_t, time_t_control_cycle_limit_us) }, \
         { "time_t_last_cycle_end_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_state_field_registry_t, time_t_last_cycle_end_us) }, \
         { "last_transition_ccno", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_state_field_registry_t, last_transition_ccno) }, \
         { "mcl_control_cycle_num", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_state_field_registry_t, mcl_control_cycle_num) }, \
         { "imu_linear_acc_vec_f_x", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_state_field_registry_t, imu_linear_acc_vec_f_x) }, \
         { "imu_linear_acc_vec_f_y", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_state_field_registry_t, imu_linear_acc_vec_f_y) }, \
         { "imu_linear_acc_vec_f_z", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_state_field_registry_t, imu_linear_acc_vec_f_z) }, \
         { "imu_acc_vec_f_x", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_state_field_registry_t, imu_acc_vec_f_x) }, \
         { "imu_acc_vec_f_y", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_state_field_registry_t, imu_acc_vec_f_y) }, \
         { "imu_acc_vec_f_z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_state_field_registry_t, imu_acc_vec_f_z) }, \
         { "imu_gyr_vec_x", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_state_field_registry_t, imu_gyr_vec_x) }, \
         { "imu_gyr_vec_y", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_state_field_registry_t, imu_gyr_vec_y) }, \
         { "imu_gyr_vec_z", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_state_field_registry_t, imu_gyr_vec_z) }, \
         { "imu_euler_vec_x", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_state_field_registry_t, imu_euler_vec_x) }, \
         { "imu_euler_vec_y", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_state_field_registry_t, imu_euler_vec_y) }, \
         { "imu_euler_vec_z", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_state_field_registry_t, imu_euler_vec_z) }, \
         { "imu_euler_vec_w", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_state_field_registry_t, imu_euler_vec_w) }, \
         { "imu_quat_x", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_state_field_registry_t, imu_quat_x) }, \
         { "imu_quat_y", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_state_field_registry_t, imu_quat_y) }, \
         { "imu_quat_z", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_state_field_registry_t, imu_quat_z) }, \
         { "imu_quat_w", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_state_field_registry_t, imu_quat_w) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_STATE_FIELD_REGISTRY { \
    "STATE_FIELD_REGISTRY", \
    22, \
    {  { "time_t_average_cycle_time_us", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_state_field_registry_t, time_t_average_cycle_time_us) }, \
         { "time_t_control_cycle_limit_us", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_state_field_registry_t, time_t_control_cycle_limit_us) }, \
         { "time_t_last_cycle_end_us", NULL, MAVLINK_TYPE_UINT32_T, 0, 24, offsetof(mavlink_state_field_registry_t, time_t_last_cycle_end_us) }, \
         { "last_transition_ccno", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_state_field_registry_t, last_transition_ccno) }, \
         { "mcl_control_cycle_num", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_state_field_registry_t, mcl_control_cycle_num) }, \
         { "imu_linear_acc_vec_f_x", NULL, MAVLINK_TYPE_FLOAT, 0, 28, offsetof(mavlink_state_field_registry_t, imu_linear_acc_vec_f_x) }, \
         { "imu_linear_acc_vec_f_y", NULL, MAVLINK_TYPE_FLOAT, 0, 32, offsetof(mavlink_state_field_registry_t, imu_linear_acc_vec_f_y) }, \
         { "imu_linear_acc_vec_f_z", NULL, MAVLINK_TYPE_FLOAT, 0, 36, offsetof(mavlink_state_field_registry_t, imu_linear_acc_vec_f_z) }, \
         { "imu_acc_vec_f_x", NULL, MAVLINK_TYPE_FLOAT, 0, 40, offsetof(mavlink_state_field_registry_t, imu_acc_vec_f_x) }, \
         { "imu_acc_vec_f_y", NULL, MAVLINK_TYPE_FLOAT, 0, 44, offsetof(mavlink_state_field_registry_t, imu_acc_vec_f_y) }, \
         { "imu_acc_vec_f_z", NULL, MAVLINK_TYPE_FLOAT, 0, 48, offsetof(mavlink_state_field_registry_t, imu_acc_vec_f_z) }, \
         { "imu_gyr_vec_x", NULL, MAVLINK_TYPE_FLOAT, 0, 52, offsetof(mavlink_state_field_registry_t, imu_gyr_vec_x) }, \
         { "imu_gyr_vec_y", NULL, MAVLINK_TYPE_FLOAT, 0, 56, offsetof(mavlink_state_field_registry_t, imu_gyr_vec_y) }, \
         { "imu_gyr_vec_z", NULL, MAVLINK_TYPE_FLOAT, 0, 60, offsetof(mavlink_state_field_registry_t, imu_gyr_vec_z) }, \
         { "imu_euler_vec_x", NULL, MAVLINK_TYPE_FLOAT, 0, 64, offsetof(mavlink_state_field_registry_t, imu_euler_vec_x) }, \
         { "imu_euler_vec_y", NULL, MAVLINK_TYPE_FLOAT, 0, 68, offsetof(mavlink_state_field_registry_t, imu_euler_vec_y) }, \
         { "imu_euler_vec_z", NULL, MAVLINK_TYPE_FLOAT, 0, 72, offsetof(mavlink_state_field_registry_t, imu_euler_vec_z) }, \
         { "imu_euler_vec_w", NULL, MAVLINK_TYPE_FLOAT, 0, 76, offsetof(mavlink_state_field_registry_t, imu_euler_vec_w) }, \
         { "imu_quat_x", NULL, MAVLINK_TYPE_FLOAT, 0, 80, offsetof(mavlink_state_field_registry_t, imu_quat_x) }, \
         { "imu_quat_y", NULL, MAVLINK_TYPE_FLOAT, 0, 84, offsetof(mavlink_state_field_registry_t, imu_quat_y) }, \
         { "imu_quat_z", NULL, MAVLINK_TYPE_FLOAT, 0, 88, offsetof(mavlink_state_field_registry_t, imu_quat_z) }, \
         { "imu_quat_w", NULL, MAVLINK_TYPE_FLOAT, 0, 92, offsetof(mavlink_state_field_registry_t, imu_quat_w) }, \
         } \
}
#endif

/**
 * @brief Pack a state_field_registry message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_t_average_cycle_time_us [us] Average control cycle time in microseconds
 * @param time_t_control_cycle_limit_us [us] Control cycle limit in microseconds
 * @param time_t_last_cycle_end_us [us] Timestamp of last control cycle in microseconds
 * @param last_transition_ccno  Last control cycle number of a state transition
 * @param mcl_control_cycle_num  Main control loop cycle number
 * @param imu_linear_acc_vec_f_x  IMU linear acceleration vector X
 * @param imu_linear_acc_vec_f_y  IMU linear acceleration vector Y
 * @param imu_linear_acc_vec_f_z  IMU linear acceleration vector Z
 * @param imu_acc_vec_f_x  IMU acceleration vector X
 * @param imu_acc_vec_f_y  IMU acceleration vector Y
 * @param imu_acc_vec_f_z  IMU acceleration vector Z
 * @param imu_gyr_vec_x  IMU gyroscope vector X
 * @param imu_gyr_vec_y  IMU gyroscope vector Y
 * @param imu_gyr_vec_z  IMU gyroscope vector Z
 * @param imu_euler_vec_x  IMU Euler angles X
 * @param imu_euler_vec_y  IMU Euler angles Y
 * @param imu_euler_vec_z  IMU Euler angles Z
 * @param imu_euler_vec_w  IMU Euler angles W (optional for Euler, used if needed)
 * @param imu_quat_x  IMU quaternion X
 * @param imu_quat_y  IMU quaternion Y
 * @param imu_quat_z  IMU quaternion Z
 * @param imu_quat_w  IMU quaternion W
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_state_field_registry_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               float time_t_average_cycle_time_us, int32_t time_t_control_cycle_limit_us, uint32_t time_t_last_cycle_end_us, uint64_t last_transition_ccno, uint64_t mcl_control_cycle_num, float imu_linear_acc_vec_f_x, float imu_linear_acc_vec_f_y, float imu_linear_acc_vec_f_z, float imu_acc_vec_f_x, float imu_acc_vec_f_y, float imu_acc_vec_f_z, float imu_gyr_vec_x, float imu_gyr_vec_y, float imu_gyr_vec_z, float imu_euler_vec_x, float imu_euler_vec_y, float imu_euler_vec_z, float imu_euler_vec_w, float imu_quat_x, float imu_quat_y, float imu_quat_z, float imu_quat_w)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN];
    _mav_put_uint64_t(buf, 0, last_transition_ccno);
    _mav_put_uint64_t(buf, 8, mcl_control_cycle_num);
    _mav_put_float(buf, 16, time_t_average_cycle_time_us);
    _mav_put_int32_t(buf, 20, time_t_control_cycle_limit_us);
    _mav_put_uint32_t(buf, 24, time_t_last_cycle_end_us);
    _mav_put_float(buf, 28, imu_linear_acc_vec_f_x);
    _mav_put_float(buf, 32, imu_linear_acc_vec_f_y);
    _mav_put_float(buf, 36, imu_linear_acc_vec_f_z);
    _mav_put_float(buf, 40, imu_acc_vec_f_x);
    _mav_put_float(buf, 44, imu_acc_vec_f_y);
    _mav_put_float(buf, 48, imu_acc_vec_f_z);
    _mav_put_float(buf, 52, imu_gyr_vec_x);
    _mav_put_float(buf, 56, imu_gyr_vec_y);
    _mav_put_float(buf, 60, imu_gyr_vec_z);
    _mav_put_float(buf, 64, imu_euler_vec_x);
    _mav_put_float(buf, 68, imu_euler_vec_y);
    _mav_put_float(buf, 72, imu_euler_vec_z);
    _mav_put_float(buf, 76, imu_euler_vec_w);
    _mav_put_float(buf, 80, imu_quat_x);
    _mav_put_float(buf, 84, imu_quat_y);
    _mav_put_float(buf, 88, imu_quat_z);
    _mav_put_float(buf, 92, imu_quat_w);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
#else
    mavlink_state_field_registry_t packet;
    packet.last_transition_ccno = last_transition_ccno;
    packet.mcl_control_cycle_num = mcl_control_cycle_num;
    packet.time_t_average_cycle_time_us = time_t_average_cycle_time_us;
    packet.time_t_control_cycle_limit_us = time_t_control_cycle_limit_us;
    packet.time_t_last_cycle_end_us = time_t_last_cycle_end_us;
    packet.imu_linear_acc_vec_f_x = imu_linear_acc_vec_f_x;
    packet.imu_linear_acc_vec_f_y = imu_linear_acc_vec_f_y;
    packet.imu_linear_acc_vec_f_z = imu_linear_acc_vec_f_z;
    packet.imu_acc_vec_f_x = imu_acc_vec_f_x;
    packet.imu_acc_vec_f_y = imu_acc_vec_f_y;
    packet.imu_acc_vec_f_z = imu_acc_vec_f_z;
    packet.imu_gyr_vec_x = imu_gyr_vec_x;
    packet.imu_gyr_vec_y = imu_gyr_vec_y;
    packet.imu_gyr_vec_z = imu_gyr_vec_z;
    packet.imu_euler_vec_x = imu_euler_vec_x;
    packet.imu_euler_vec_y = imu_euler_vec_y;
    packet.imu_euler_vec_z = imu_euler_vec_z;
    packet.imu_euler_vec_w = imu_euler_vec_w;
    packet.imu_quat_x = imu_quat_x;
    packet.imu_quat_y = imu_quat_y;
    packet.imu_quat_z = imu_quat_z;
    packet.imu_quat_w = imu_quat_w;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STATE_FIELD_REGISTRY;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
}

/**
 * @brief Pack a state_field_registry message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_t_average_cycle_time_us [us] Average control cycle time in microseconds
 * @param time_t_control_cycle_limit_us [us] Control cycle limit in microseconds
 * @param time_t_last_cycle_end_us [us] Timestamp of last control cycle in microseconds
 * @param last_transition_ccno  Last control cycle number of a state transition
 * @param mcl_control_cycle_num  Main control loop cycle number
 * @param imu_linear_acc_vec_f_x  IMU linear acceleration vector X
 * @param imu_linear_acc_vec_f_y  IMU linear acceleration vector Y
 * @param imu_linear_acc_vec_f_z  IMU linear acceleration vector Z
 * @param imu_acc_vec_f_x  IMU acceleration vector X
 * @param imu_acc_vec_f_y  IMU acceleration vector Y
 * @param imu_acc_vec_f_z  IMU acceleration vector Z
 * @param imu_gyr_vec_x  IMU gyroscope vector X
 * @param imu_gyr_vec_y  IMU gyroscope vector Y
 * @param imu_gyr_vec_z  IMU gyroscope vector Z
 * @param imu_euler_vec_x  IMU Euler angles X
 * @param imu_euler_vec_y  IMU Euler angles Y
 * @param imu_euler_vec_z  IMU Euler angles Z
 * @param imu_euler_vec_w  IMU Euler angles W (optional for Euler, used if needed)
 * @param imu_quat_x  IMU quaternion X
 * @param imu_quat_y  IMU quaternion Y
 * @param imu_quat_z  IMU quaternion Z
 * @param imu_quat_w  IMU quaternion W
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_state_field_registry_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               float time_t_average_cycle_time_us, int32_t time_t_control_cycle_limit_us, uint32_t time_t_last_cycle_end_us, uint64_t last_transition_ccno, uint64_t mcl_control_cycle_num, float imu_linear_acc_vec_f_x, float imu_linear_acc_vec_f_y, float imu_linear_acc_vec_f_z, float imu_acc_vec_f_x, float imu_acc_vec_f_y, float imu_acc_vec_f_z, float imu_gyr_vec_x, float imu_gyr_vec_y, float imu_gyr_vec_z, float imu_euler_vec_x, float imu_euler_vec_y, float imu_euler_vec_z, float imu_euler_vec_w, float imu_quat_x, float imu_quat_y, float imu_quat_z, float imu_quat_w)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN];
    _mav_put_uint64_t(buf, 0, last_transition_ccno);
    _mav_put_uint64_t(buf, 8, mcl_control_cycle_num);
    _mav_put_float(buf, 16, time_t_average_cycle_time_us);
    _mav_put_int32_t(buf, 20, time_t_control_cycle_limit_us);
    _mav_put_uint32_t(buf, 24, time_t_last_cycle_end_us);
    _mav_put_float(buf, 28, imu_linear_acc_vec_f_x);
    _mav_put_float(buf, 32, imu_linear_acc_vec_f_y);
    _mav_put_float(buf, 36, imu_linear_acc_vec_f_z);
    _mav_put_float(buf, 40, imu_acc_vec_f_x);
    _mav_put_float(buf, 44, imu_acc_vec_f_y);
    _mav_put_float(buf, 48, imu_acc_vec_f_z);
    _mav_put_float(buf, 52, imu_gyr_vec_x);
    _mav_put_float(buf, 56, imu_gyr_vec_y);
    _mav_put_float(buf, 60, imu_gyr_vec_z);
    _mav_put_float(buf, 64, imu_euler_vec_x);
    _mav_put_float(buf, 68, imu_euler_vec_y);
    _mav_put_float(buf, 72, imu_euler_vec_z);
    _mav_put_float(buf, 76, imu_euler_vec_w);
    _mav_put_float(buf, 80, imu_quat_x);
    _mav_put_float(buf, 84, imu_quat_y);
    _mav_put_float(buf, 88, imu_quat_z);
    _mav_put_float(buf, 92, imu_quat_w);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
#else
    mavlink_state_field_registry_t packet;
    packet.last_transition_ccno = last_transition_ccno;
    packet.mcl_control_cycle_num = mcl_control_cycle_num;
    packet.time_t_average_cycle_time_us = time_t_average_cycle_time_us;
    packet.time_t_control_cycle_limit_us = time_t_control_cycle_limit_us;
    packet.time_t_last_cycle_end_us = time_t_last_cycle_end_us;
    packet.imu_linear_acc_vec_f_x = imu_linear_acc_vec_f_x;
    packet.imu_linear_acc_vec_f_y = imu_linear_acc_vec_f_y;
    packet.imu_linear_acc_vec_f_z = imu_linear_acc_vec_f_z;
    packet.imu_acc_vec_f_x = imu_acc_vec_f_x;
    packet.imu_acc_vec_f_y = imu_acc_vec_f_y;
    packet.imu_acc_vec_f_z = imu_acc_vec_f_z;
    packet.imu_gyr_vec_x = imu_gyr_vec_x;
    packet.imu_gyr_vec_y = imu_gyr_vec_y;
    packet.imu_gyr_vec_z = imu_gyr_vec_z;
    packet.imu_euler_vec_x = imu_euler_vec_x;
    packet.imu_euler_vec_y = imu_euler_vec_y;
    packet.imu_euler_vec_z = imu_euler_vec_z;
    packet.imu_euler_vec_w = imu_euler_vec_w;
    packet.imu_quat_x = imu_quat_x;
    packet.imu_quat_y = imu_quat_y;
    packet.imu_quat_z = imu_quat_z;
    packet.imu_quat_w = imu_quat_w;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STATE_FIELD_REGISTRY;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
#endif
}

/**
 * @brief Pack a state_field_registry message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_t_average_cycle_time_us [us] Average control cycle time in microseconds
 * @param time_t_control_cycle_limit_us [us] Control cycle limit in microseconds
 * @param time_t_last_cycle_end_us [us] Timestamp of last control cycle in microseconds
 * @param last_transition_ccno  Last control cycle number of a state transition
 * @param mcl_control_cycle_num  Main control loop cycle number
 * @param imu_linear_acc_vec_f_x  IMU linear acceleration vector X
 * @param imu_linear_acc_vec_f_y  IMU linear acceleration vector Y
 * @param imu_linear_acc_vec_f_z  IMU linear acceleration vector Z
 * @param imu_acc_vec_f_x  IMU acceleration vector X
 * @param imu_acc_vec_f_y  IMU acceleration vector Y
 * @param imu_acc_vec_f_z  IMU acceleration vector Z
 * @param imu_gyr_vec_x  IMU gyroscope vector X
 * @param imu_gyr_vec_y  IMU gyroscope vector Y
 * @param imu_gyr_vec_z  IMU gyroscope vector Z
 * @param imu_euler_vec_x  IMU Euler angles X
 * @param imu_euler_vec_y  IMU Euler angles Y
 * @param imu_euler_vec_z  IMU Euler angles Z
 * @param imu_euler_vec_w  IMU Euler angles W (optional for Euler, used if needed)
 * @param imu_quat_x  IMU quaternion X
 * @param imu_quat_y  IMU quaternion Y
 * @param imu_quat_z  IMU quaternion Z
 * @param imu_quat_w  IMU quaternion W
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_state_field_registry_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   float time_t_average_cycle_time_us,int32_t time_t_control_cycle_limit_us,uint32_t time_t_last_cycle_end_us,uint64_t last_transition_ccno,uint64_t mcl_control_cycle_num,float imu_linear_acc_vec_f_x,float imu_linear_acc_vec_f_y,float imu_linear_acc_vec_f_z,float imu_acc_vec_f_x,float imu_acc_vec_f_y,float imu_acc_vec_f_z,float imu_gyr_vec_x,float imu_gyr_vec_y,float imu_gyr_vec_z,float imu_euler_vec_x,float imu_euler_vec_y,float imu_euler_vec_z,float imu_euler_vec_w,float imu_quat_x,float imu_quat_y,float imu_quat_z,float imu_quat_w)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN];
    _mav_put_uint64_t(buf, 0, last_transition_ccno);
    _mav_put_uint64_t(buf, 8, mcl_control_cycle_num);
    _mav_put_float(buf, 16, time_t_average_cycle_time_us);
    _mav_put_int32_t(buf, 20, time_t_control_cycle_limit_us);
    _mav_put_uint32_t(buf, 24, time_t_last_cycle_end_us);
    _mav_put_float(buf, 28, imu_linear_acc_vec_f_x);
    _mav_put_float(buf, 32, imu_linear_acc_vec_f_y);
    _mav_put_float(buf, 36, imu_linear_acc_vec_f_z);
    _mav_put_float(buf, 40, imu_acc_vec_f_x);
    _mav_put_float(buf, 44, imu_acc_vec_f_y);
    _mav_put_float(buf, 48, imu_acc_vec_f_z);
    _mav_put_float(buf, 52, imu_gyr_vec_x);
    _mav_put_float(buf, 56, imu_gyr_vec_y);
    _mav_put_float(buf, 60, imu_gyr_vec_z);
    _mav_put_float(buf, 64, imu_euler_vec_x);
    _mav_put_float(buf, 68, imu_euler_vec_y);
    _mav_put_float(buf, 72, imu_euler_vec_z);
    _mav_put_float(buf, 76, imu_euler_vec_w);
    _mav_put_float(buf, 80, imu_quat_x);
    _mav_put_float(buf, 84, imu_quat_y);
    _mav_put_float(buf, 88, imu_quat_z);
    _mav_put_float(buf, 92, imu_quat_w);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
#else
    mavlink_state_field_registry_t packet;
    packet.last_transition_ccno = last_transition_ccno;
    packet.mcl_control_cycle_num = mcl_control_cycle_num;
    packet.time_t_average_cycle_time_us = time_t_average_cycle_time_us;
    packet.time_t_control_cycle_limit_us = time_t_control_cycle_limit_us;
    packet.time_t_last_cycle_end_us = time_t_last_cycle_end_us;
    packet.imu_linear_acc_vec_f_x = imu_linear_acc_vec_f_x;
    packet.imu_linear_acc_vec_f_y = imu_linear_acc_vec_f_y;
    packet.imu_linear_acc_vec_f_z = imu_linear_acc_vec_f_z;
    packet.imu_acc_vec_f_x = imu_acc_vec_f_x;
    packet.imu_acc_vec_f_y = imu_acc_vec_f_y;
    packet.imu_acc_vec_f_z = imu_acc_vec_f_z;
    packet.imu_gyr_vec_x = imu_gyr_vec_x;
    packet.imu_gyr_vec_y = imu_gyr_vec_y;
    packet.imu_gyr_vec_z = imu_gyr_vec_z;
    packet.imu_euler_vec_x = imu_euler_vec_x;
    packet.imu_euler_vec_y = imu_euler_vec_y;
    packet.imu_euler_vec_z = imu_euler_vec_z;
    packet.imu_euler_vec_w = imu_euler_vec_w;
    packet.imu_quat_x = imu_quat_x;
    packet.imu_quat_y = imu_quat_y;
    packet.imu_quat_z = imu_quat_z;
    packet.imu_quat_w = imu_quat_w;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_STATE_FIELD_REGISTRY;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
}

/**
 * @brief Encode a state_field_registry struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param state_field_registry C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_state_field_registry_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_state_field_registry_t* state_field_registry)
{
    return mavlink_msg_state_field_registry_pack(system_id, component_id, msg, state_field_registry->time_t_average_cycle_time_us, state_field_registry->time_t_control_cycle_limit_us, state_field_registry->time_t_last_cycle_end_us, state_field_registry->last_transition_ccno, state_field_registry->mcl_control_cycle_num, state_field_registry->imu_linear_acc_vec_f_x, state_field_registry->imu_linear_acc_vec_f_y, state_field_registry->imu_linear_acc_vec_f_z, state_field_registry->imu_acc_vec_f_x, state_field_registry->imu_acc_vec_f_y, state_field_registry->imu_acc_vec_f_z, state_field_registry->imu_gyr_vec_x, state_field_registry->imu_gyr_vec_y, state_field_registry->imu_gyr_vec_z, state_field_registry->imu_euler_vec_x, state_field_registry->imu_euler_vec_y, state_field_registry->imu_euler_vec_z, state_field_registry->imu_euler_vec_w, state_field_registry->imu_quat_x, state_field_registry->imu_quat_y, state_field_registry->imu_quat_z, state_field_registry->imu_quat_w);
}

/**
 * @brief Encode a state_field_registry struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param state_field_registry C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_state_field_registry_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_state_field_registry_t* state_field_registry)
{
    return mavlink_msg_state_field_registry_pack_chan(system_id, component_id, chan, msg, state_field_registry->time_t_average_cycle_time_us, state_field_registry->time_t_control_cycle_limit_us, state_field_registry->time_t_last_cycle_end_us, state_field_registry->last_transition_ccno, state_field_registry->mcl_control_cycle_num, state_field_registry->imu_linear_acc_vec_f_x, state_field_registry->imu_linear_acc_vec_f_y, state_field_registry->imu_linear_acc_vec_f_z, state_field_registry->imu_acc_vec_f_x, state_field_registry->imu_acc_vec_f_y, state_field_registry->imu_acc_vec_f_z, state_field_registry->imu_gyr_vec_x, state_field_registry->imu_gyr_vec_y, state_field_registry->imu_gyr_vec_z, state_field_registry->imu_euler_vec_x, state_field_registry->imu_euler_vec_y, state_field_registry->imu_euler_vec_z, state_field_registry->imu_euler_vec_w, state_field_registry->imu_quat_x, state_field_registry->imu_quat_y, state_field_registry->imu_quat_z, state_field_registry->imu_quat_w);
}

/**
 * @brief Encode a state_field_registry struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param state_field_registry C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_state_field_registry_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_state_field_registry_t* state_field_registry)
{
    return mavlink_msg_state_field_registry_pack_status(system_id, component_id, _status, msg,  state_field_registry->time_t_average_cycle_time_us, state_field_registry->time_t_control_cycle_limit_us, state_field_registry->time_t_last_cycle_end_us, state_field_registry->last_transition_ccno, state_field_registry->mcl_control_cycle_num, state_field_registry->imu_linear_acc_vec_f_x, state_field_registry->imu_linear_acc_vec_f_y, state_field_registry->imu_linear_acc_vec_f_z, state_field_registry->imu_acc_vec_f_x, state_field_registry->imu_acc_vec_f_y, state_field_registry->imu_acc_vec_f_z, state_field_registry->imu_gyr_vec_x, state_field_registry->imu_gyr_vec_y, state_field_registry->imu_gyr_vec_z, state_field_registry->imu_euler_vec_x, state_field_registry->imu_euler_vec_y, state_field_registry->imu_euler_vec_z, state_field_registry->imu_euler_vec_w, state_field_registry->imu_quat_x, state_field_registry->imu_quat_y, state_field_registry->imu_quat_z, state_field_registry->imu_quat_w);
}

/**
 * @brief Send a state_field_registry message
 * @param chan MAVLink channel to send the message
 *
 * @param time_t_average_cycle_time_us [us] Average control cycle time in microseconds
 * @param time_t_control_cycle_limit_us [us] Control cycle limit in microseconds
 * @param time_t_last_cycle_end_us [us] Timestamp of last control cycle in microseconds
 * @param last_transition_ccno  Last control cycle number of a state transition
 * @param mcl_control_cycle_num  Main control loop cycle number
 * @param imu_linear_acc_vec_f_x  IMU linear acceleration vector X
 * @param imu_linear_acc_vec_f_y  IMU linear acceleration vector Y
 * @param imu_linear_acc_vec_f_z  IMU linear acceleration vector Z
 * @param imu_acc_vec_f_x  IMU acceleration vector X
 * @param imu_acc_vec_f_y  IMU acceleration vector Y
 * @param imu_acc_vec_f_z  IMU acceleration vector Z
 * @param imu_gyr_vec_x  IMU gyroscope vector X
 * @param imu_gyr_vec_y  IMU gyroscope vector Y
 * @param imu_gyr_vec_z  IMU gyroscope vector Z
 * @param imu_euler_vec_x  IMU Euler angles X
 * @param imu_euler_vec_y  IMU Euler angles Y
 * @param imu_euler_vec_z  IMU Euler angles Z
 * @param imu_euler_vec_w  IMU Euler angles W (optional for Euler, used if needed)
 * @param imu_quat_x  IMU quaternion X
 * @param imu_quat_y  IMU quaternion Y
 * @param imu_quat_z  IMU quaternion Z
 * @param imu_quat_w  IMU quaternion W
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_state_field_registry_send(mavlink_channel_t chan, float time_t_average_cycle_time_us, int32_t time_t_control_cycle_limit_us, uint32_t time_t_last_cycle_end_us, uint64_t last_transition_ccno, uint64_t mcl_control_cycle_num, float imu_linear_acc_vec_f_x, float imu_linear_acc_vec_f_y, float imu_linear_acc_vec_f_z, float imu_acc_vec_f_x, float imu_acc_vec_f_y, float imu_acc_vec_f_z, float imu_gyr_vec_x, float imu_gyr_vec_y, float imu_gyr_vec_z, float imu_euler_vec_x, float imu_euler_vec_y, float imu_euler_vec_z, float imu_euler_vec_w, float imu_quat_x, float imu_quat_y, float imu_quat_z, float imu_quat_w)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN];
    _mav_put_uint64_t(buf, 0, last_transition_ccno);
    _mav_put_uint64_t(buf, 8, mcl_control_cycle_num);
    _mav_put_float(buf, 16, time_t_average_cycle_time_us);
    _mav_put_int32_t(buf, 20, time_t_control_cycle_limit_us);
    _mav_put_uint32_t(buf, 24, time_t_last_cycle_end_us);
    _mav_put_float(buf, 28, imu_linear_acc_vec_f_x);
    _mav_put_float(buf, 32, imu_linear_acc_vec_f_y);
    _mav_put_float(buf, 36, imu_linear_acc_vec_f_z);
    _mav_put_float(buf, 40, imu_acc_vec_f_x);
    _mav_put_float(buf, 44, imu_acc_vec_f_y);
    _mav_put_float(buf, 48, imu_acc_vec_f_z);
    _mav_put_float(buf, 52, imu_gyr_vec_x);
    _mav_put_float(buf, 56, imu_gyr_vec_y);
    _mav_put_float(buf, 60, imu_gyr_vec_z);
    _mav_put_float(buf, 64, imu_euler_vec_x);
    _mav_put_float(buf, 68, imu_euler_vec_y);
    _mav_put_float(buf, 72, imu_euler_vec_z);
    _mav_put_float(buf, 76, imu_euler_vec_w);
    _mav_put_float(buf, 80, imu_quat_x);
    _mav_put_float(buf, 84, imu_quat_y);
    _mav_put_float(buf, 88, imu_quat_z);
    _mav_put_float(buf, 92, imu_quat_w);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY, buf, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
#else
    mavlink_state_field_registry_t packet;
    packet.last_transition_ccno = last_transition_ccno;
    packet.mcl_control_cycle_num = mcl_control_cycle_num;
    packet.time_t_average_cycle_time_us = time_t_average_cycle_time_us;
    packet.time_t_control_cycle_limit_us = time_t_control_cycle_limit_us;
    packet.time_t_last_cycle_end_us = time_t_last_cycle_end_us;
    packet.imu_linear_acc_vec_f_x = imu_linear_acc_vec_f_x;
    packet.imu_linear_acc_vec_f_y = imu_linear_acc_vec_f_y;
    packet.imu_linear_acc_vec_f_z = imu_linear_acc_vec_f_z;
    packet.imu_acc_vec_f_x = imu_acc_vec_f_x;
    packet.imu_acc_vec_f_y = imu_acc_vec_f_y;
    packet.imu_acc_vec_f_z = imu_acc_vec_f_z;
    packet.imu_gyr_vec_x = imu_gyr_vec_x;
    packet.imu_gyr_vec_y = imu_gyr_vec_y;
    packet.imu_gyr_vec_z = imu_gyr_vec_z;
    packet.imu_euler_vec_x = imu_euler_vec_x;
    packet.imu_euler_vec_y = imu_euler_vec_y;
    packet.imu_euler_vec_z = imu_euler_vec_z;
    packet.imu_euler_vec_w = imu_euler_vec_w;
    packet.imu_quat_x = imu_quat_x;
    packet.imu_quat_y = imu_quat_y;
    packet.imu_quat_z = imu_quat_z;
    packet.imu_quat_w = imu_quat_w;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY, (const char *)&packet, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
#endif
}

/**
 * @brief Send a state_field_registry message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_state_field_registry_send_struct(mavlink_channel_t chan, const mavlink_state_field_registry_t* state_field_registry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_state_field_registry_send(chan, state_field_registry->time_t_average_cycle_time_us, state_field_registry->time_t_control_cycle_limit_us, state_field_registry->time_t_last_cycle_end_us, state_field_registry->last_transition_ccno, state_field_registry->mcl_control_cycle_num, state_field_registry->imu_linear_acc_vec_f_x, state_field_registry->imu_linear_acc_vec_f_y, state_field_registry->imu_linear_acc_vec_f_z, state_field_registry->imu_acc_vec_f_x, state_field_registry->imu_acc_vec_f_y, state_field_registry->imu_acc_vec_f_z, state_field_registry->imu_gyr_vec_x, state_field_registry->imu_gyr_vec_y, state_field_registry->imu_gyr_vec_z, state_field_registry->imu_euler_vec_x, state_field_registry->imu_euler_vec_y, state_field_registry->imu_euler_vec_z, state_field_registry->imu_euler_vec_w, state_field_registry->imu_quat_x, state_field_registry->imu_quat_y, state_field_registry->imu_quat_z, state_field_registry->imu_quat_w);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY, (const char *)state_field_registry, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
#endif
}

#if MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_state_field_registry_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  float time_t_average_cycle_time_us, int32_t time_t_control_cycle_limit_us, uint32_t time_t_last_cycle_end_us, uint64_t last_transition_ccno, uint64_t mcl_control_cycle_num, float imu_linear_acc_vec_f_x, float imu_linear_acc_vec_f_y, float imu_linear_acc_vec_f_z, float imu_acc_vec_f_x, float imu_acc_vec_f_y, float imu_acc_vec_f_z, float imu_gyr_vec_x, float imu_gyr_vec_y, float imu_gyr_vec_z, float imu_euler_vec_x, float imu_euler_vec_y, float imu_euler_vec_z, float imu_euler_vec_w, float imu_quat_x, float imu_quat_y, float imu_quat_z, float imu_quat_w)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, last_transition_ccno);
    _mav_put_uint64_t(buf, 8, mcl_control_cycle_num);
    _mav_put_float(buf, 16, time_t_average_cycle_time_us);
    _mav_put_int32_t(buf, 20, time_t_control_cycle_limit_us);
    _mav_put_uint32_t(buf, 24, time_t_last_cycle_end_us);
    _mav_put_float(buf, 28, imu_linear_acc_vec_f_x);
    _mav_put_float(buf, 32, imu_linear_acc_vec_f_y);
    _mav_put_float(buf, 36, imu_linear_acc_vec_f_z);
    _mav_put_float(buf, 40, imu_acc_vec_f_x);
    _mav_put_float(buf, 44, imu_acc_vec_f_y);
    _mav_put_float(buf, 48, imu_acc_vec_f_z);
    _mav_put_float(buf, 52, imu_gyr_vec_x);
    _mav_put_float(buf, 56, imu_gyr_vec_y);
    _mav_put_float(buf, 60, imu_gyr_vec_z);
    _mav_put_float(buf, 64, imu_euler_vec_x);
    _mav_put_float(buf, 68, imu_euler_vec_y);
    _mav_put_float(buf, 72, imu_euler_vec_z);
    _mav_put_float(buf, 76, imu_euler_vec_w);
    _mav_put_float(buf, 80, imu_quat_x);
    _mav_put_float(buf, 84, imu_quat_y);
    _mav_put_float(buf, 88, imu_quat_z);
    _mav_put_float(buf, 92, imu_quat_w);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY, buf, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
#else
    mavlink_state_field_registry_t *packet = (mavlink_state_field_registry_t *)msgbuf;
    packet->last_transition_ccno = last_transition_ccno;
    packet->mcl_control_cycle_num = mcl_control_cycle_num;
    packet->time_t_average_cycle_time_us = time_t_average_cycle_time_us;
    packet->time_t_control_cycle_limit_us = time_t_control_cycle_limit_us;
    packet->time_t_last_cycle_end_us = time_t_last_cycle_end_us;
    packet->imu_linear_acc_vec_f_x = imu_linear_acc_vec_f_x;
    packet->imu_linear_acc_vec_f_y = imu_linear_acc_vec_f_y;
    packet->imu_linear_acc_vec_f_z = imu_linear_acc_vec_f_z;
    packet->imu_acc_vec_f_x = imu_acc_vec_f_x;
    packet->imu_acc_vec_f_y = imu_acc_vec_f_y;
    packet->imu_acc_vec_f_z = imu_acc_vec_f_z;
    packet->imu_gyr_vec_x = imu_gyr_vec_x;
    packet->imu_gyr_vec_y = imu_gyr_vec_y;
    packet->imu_gyr_vec_z = imu_gyr_vec_z;
    packet->imu_euler_vec_x = imu_euler_vec_x;
    packet->imu_euler_vec_y = imu_euler_vec_y;
    packet->imu_euler_vec_z = imu_euler_vec_z;
    packet->imu_euler_vec_w = imu_euler_vec_w;
    packet->imu_quat_x = imu_quat_x;
    packet->imu_quat_y = imu_quat_y;
    packet->imu_quat_z = imu_quat_z;
    packet->imu_quat_w = imu_quat_w;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY, (const char *)packet, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_MIN_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_CRC);
#endif
}
#endif

#endif

// MESSAGE STATE_FIELD_REGISTRY UNPACKING


/**
 * @brief Get field time_t_average_cycle_time_us from state_field_registry message
 *
 * @return [us] Average control cycle time in microseconds
 */
static inline float mavlink_msg_state_field_registry_get_time_t_average_cycle_time_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field time_t_control_cycle_limit_us from state_field_registry message
 *
 * @return [us] Control cycle limit in microseconds
 */
static inline int32_t mavlink_msg_state_field_registry_get_time_t_control_cycle_limit_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field time_t_last_cycle_end_us from state_field_registry message
 *
 * @return [us] Timestamp of last control cycle in microseconds
 */
static inline uint32_t mavlink_msg_state_field_registry_get_time_t_last_cycle_end_us(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  24);
}

/**
 * @brief Get field last_transition_ccno from state_field_registry message
 *
 * @return  Last control cycle number of a state transition
 */
static inline uint64_t mavlink_msg_state_field_registry_get_last_transition_ccno(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field mcl_control_cycle_num from state_field_registry message
 *
 * @return  Main control loop cycle number
 */
static inline uint64_t mavlink_msg_state_field_registry_get_mcl_control_cycle_num(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field imu_linear_acc_vec_f_x from state_field_registry message
 *
 * @return  IMU linear acceleration vector X
 */
static inline float mavlink_msg_state_field_registry_get_imu_linear_acc_vec_f_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  28);
}

/**
 * @brief Get field imu_linear_acc_vec_f_y from state_field_registry message
 *
 * @return  IMU linear acceleration vector Y
 */
static inline float mavlink_msg_state_field_registry_get_imu_linear_acc_vec_f_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  32);
}

/**
 * @brief Get field imu_linear_acc_vec_f_z from state_field_registry message
 *
 * @return  IMU linear acceleration vector Z
 */
static inline float mavlink_msg_state_field_registry_get_imu_linear_acc_vec_f_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  36);
}

/**
 * @brief Get field imu_acc_vec_f_x from state_field_registry message
 *
 * @return  IMU acceleration vector X
 */
static inline float mavlink_msg_state_field_registry_get_imu_acc_vec_f_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  40);
}

/**
 * @brief Get field imu_acc_vec_f_y from state_field_registry message
 *
 * @return  IMU acceleration vector Y
 */
static inline float mavlink_msg_state_field_registry_get_imu_acc_vec_f_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  44);
}

/**
 * @brief Get field imu_acc_vec_f_z from state_field_registry message
 *
 * @return  IMU acceleration vector Z
 */
static inline float mavlink_msg_state_field_registry_get_imu_acc_vec_f_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  48);
}

/**
 * @brief Get field imu_gyr_vec_x from state_field_registry message
 *
 * @return  IMU gyroscope vector X
 */
static inline float mavlink_msg_state_field_registry_get_imu_gyr_vec_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  52);
}

/**
 * @brief Get field imu_gyr_vec_y from state_field_registry message
 *
 * @return  IMU gyroscope vector Y
 */
static inline float mavlink_msg_state_field_registry_get_imu_gyr_vec_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  56);
}

/**
 * @brief Get field imu_gyr_vec_z from state_field_registry message
 *
 * @return  IMU gyroscope vector Z
 */
static inline float mavlink_msg_state_field_registry_get_imu_gyr_vec_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  60);
}

/**
 * @brief Get field imu_euler_vec_x from state_field_registry message
 *
 * @return  IMU Euler angles X
 */
static inline float mavlink_msg_state_field_registry_get_imu_euler_vec_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  64);
}

/**
 * @brief Get field imu_euler_vec_y from state_field_registry message
 *
 * @return  IMU Euler angles Y
 */
static inline float mavlink_msg_state_field_registry_get_imu_euler_vec_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  68);
}

/**
 * @brief Get field imu_euler_vec_z from state_field_registry message
 *
 * @return  IMU Euler angles Z
 */
static inline float mavlink_msg_state_field_registry_get_imu_euler_vec_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  72);
}

/**
 * @brief Get field imu_euler_vec_w from state_field_registry message
 *
 * @return  IMU Euler angles W (optional for Euler, used if needed)
 */
static inline float mavlink_msg_state_field_registry_get_imu_euler_vec_w(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  76);
}

/**
 * @brief Get field imu_quat_x from state_field_registry message
 *
 * @return  IMU quaternion X
 */
static inline float mavlink_msg_state_field_registry_get_imu_quat_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  80);
}

/**
 * @brief Get field imu_quat_y from state_field_registry message
 *
 * @return  IMU quaternion Y
 */
static inline float mavlink_msg_state_field_registry_get_imu_quat_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  84);
}

/**
 * @brief Get field imu_quat_z from state_field_registry message
 *
 * @return  IMU quaternion Z
 */
static inline float mavlink_msg_state_field_registry_get_imu_quat_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  88);
}

/**
 * @brief Get field imu_quat_w from state_field_registry message
 *
 * @return  IMU quaternion W
 */
static inline float mavlink_msg_state_field_registry_get_imu_quat_w(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  92);
}

/**
 * @brief Decode a state_field_registry message into a struct
 *
 * @param msg The message to decode
 * @param state_field_registry C-struct to decode the message contents into
 */
static inline void mavlink_msg_state_field_registry_decode(const mavlink_message_t* msg, mavlink_state_field_registry_t* state_field_registry)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    state_field_registry->last_transition_ccno = mavlink_msg_state_field_registry_get_last_transition_ccno(msg);
    state_field_registry->mcl_control_cycle_num = mavlink_msg_state_field_registry_get_mcl_control_cycle_num(msg);
    state_field_registry->time_t_average_cycle_time_us = mavlink_msg_state_field_registry_get_time_t_average_cycle_time_us(msg);
    state_field_registry->time_t_control_cycle_limit_us = mavlink_msg_state_field_registry_get_time_t_control_cycle_limit_us(msg);
    state_field_registry->time_t_last_cycle_end_us = mavlink_msg_state_field_registry_get_time_t_last_cycle_end_us(msg);
    state_field_registry->imu_linear_acc_vec_f_x = mavlink_msg_state_field_registry_get_imu_linear_acc_vec_f_x(msg);
    state_field_registry->imu_linear_acc_vec_f_y = mavlink_msg_state_field_registry_get_imu_linear_acc_vec_f_y(msg);
    state_field_registry->imu_linear_acc_vec_f_z = mavlink_msg_state_field_registry_get_imu_linear_acc_vec_f_z(msg);
    state_field_registry->imu_acc_vec_f_x = mavlink_msg_state_field_registry_get_imu_acc_vec_f_x(msg);
    state_field_registry->imu_acc_vec_f_y = mavlink_msg_state_field_registry_get_imu_acc_vec_f_y(msg);
    state_field_registry->imu_acc_vec_f_z = mavlink_msg_state_field_registry_get_imu_acc_vec_f_z(msg);
    state_field_registry->imu_gyr_vec_x = mavlink_msg_state_field_registry_get_imu_gyr_vec_x(msg);
    state_field_registry->imu_gyr_vec_y = mavlink_msg_state_field_registry_get_imu_gyr_vec_y(msg);
    state_field_registry->imu_gyr_vec_z = mavlink_msg_state_field_registry_get_imu_gyr_vec_z(msg);
    state_field_registry->imu_euler_vec_x = mavlink_msg_state_field_registry_get_imu_euler_vec_x(msg);
    state_field_registry->imu_euler_vec_y = mavlink_msg_state_field_registry_get_imu_euler_vec_y(msg);
    state_field_registry->imu_euler_vec_z = mavlink_msg_state_field_registry_get_imu_euler_vec_z(msg);
    state_field_registry->imu_euler_vec_w = mavlink_msg_state_field_registry_get_imu_euler_vec_w(msg);
    state_field_registry->imu_quat_x = mavlink_msg_state_field_registry_get_imu_quat_x(msg);
    state_field_registry->imu_quat_y = mavlink_msg_state_field_registry_get_imu_quat_y(msg);
    state_field_registry->imu_quat_z = mavlink_msg_state_field_registry_get_imu_quat_z(msg);
    state_field_registry->imu_quat_w = mavlink_msg_state_field_registry_get_imu_quat_w(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN? msg->len : MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN;
        memset(state_field_registry, 0, MAVLINK_MSG_ID_STATE_FIELD_REGISTRY_LEN);
    memcpy(state_field_registry, _MAV_PAYLOAD(msg), len);
#endif
}
