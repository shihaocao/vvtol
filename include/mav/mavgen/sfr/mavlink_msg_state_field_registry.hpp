// MESSAGE STATE_FIELD_REGISTRY support class

#pragma once

namespace mavlink {
namespace sfr {
namespace msg {

/**
 * @brief STATE_FIELD_REGISTRY message
 *
 * State field registry message, representing system state and control vectors.
 */
struct STATE_FIELD_REGISTRY : mavlink::Message {
    static constexpr msgid_t MSG_ID = 110;
    static constexpr size_t LENGTH = 96;
    static constexpr size_t MIN_LENGTH = 96;
    static constexpr uint8_t CRC_EXTRA = 22;
    static constexpr auto NAME = "STATE_FIELD_REGISTRY";


    float time_t_average_cycle_time_us; /*< [us] Average control cycle time in microseconds */
    int32_t time_t_control_cycle_limit_us; /*< [us] Control cycle limit in microseconds */
    uint32_t time_t_last_cycle_end_us; /*< [us] Timestamp of last control cycle in microseconds */
    uint64_t last_transition_ccno; /*<  Last control cycle number of a state transition */
    uint64_t mcl_control_cycle_num; /*<  Main control loop cycle number */
    float imu_linear_acc_vec_f_x; /*<  IMU linear acceleration vector X */
    float imu_linear_acc_vec_f_y; /*<  IMU linear acceleration vector Y */
    float imu_linear_acc_vec_f_z; /*<  IMU linear acceleration vector Z */
    float imu_acc_vec_f_x; /*<  IMU acceleration vector X */
    float imu_acc_vec_f_y; /*<  IMU acceleration vector Y */
    float imu_acc_vec_f_z; /*<  IMU acceleration vector Z */
    float imu_gyr_vec_x; /*<  IMU gyroscope vector X */
    float imu_gyr_vec_y; /*<  IMU gyroscope vector Y */
    float imu_gyr_vec_z; /*<  IMU gyroscope vector Z */
    float imu_euler_vec_x; /*<  IMU Euler angles X */
    float imu_euler_vec_y; /*<  IMU Euler angles Y */
    float imu_euler_vec_z; /*<  IMU Euler angles Z */
    float imu_euler_vec_w; /*<  IMU Euler angles W (optional for Euler, used if needed) */
    float imu_quat_x; /*<  IMU quaternion X */
    float imu_quat_y; /*<  IMU quaternion Y */
    float imu_quat_z; /*<  IMU quaternion Z */
    float imu_quat_w; /*<  IMU quaternion W */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_t_average_cycle_time_us: " << time_t_average_cycle_time_us << std::endl;
        ss << "  time_t_control_cycle_limit_us: " << time_t_control_cycle_limit_us << std::endl;
        ss << "  time_t_last_cycle_end_us: " << time_t_last_cycle_end_us << std::endl;
        ss << "  last_transition_ccno: " << last_transition_ccno << std::endl;
        ss << "  mcl_control_cycle_num: " << mcl_control_cycle_num << std::endl;
        ss << "  imu_linear_acc_vec_f_x: " << imu_linear_acc_vec_f_x << std::endl;
        ss << "  imu_linear_acc_vec_f_y: " << imu_linear_acc_vec_f_y << std::endl;
        ss << "  imu_linear_acc_vec_f_z: " << imu_linear_acc_vec_f_z << std::endl;
        ss << "  imu_acc_vec_f_x: " << imu_acc_vec_f_x << std::endl;
        ss << "  imu_acc_vec_f_y: " << imu_acc_vec_f_y << std::endl;
        ss << "  imu_acc_vec_f_z: " << imu_acc_vec_f_z << std::endl;
        ss << "  imu_gyr_vec_x: " << imu_gyr_vec_x << std::endl;
        ss << "  imu_gyr_vec_y: " << imu_gyr_vec_y << std::endl;
        ss << "  imu_gyr_vec_z: " << imu_gyr_vec_z << std::endl;
        ss << "  imu_euler_vec_x: " << imu_euler_vec_x << std::endl;
        ss << "  imu_euler_vec_y: " << imu_euler_vec_y << std::endl;
        ss << "  imu_euler_vec_z: " << imu_euler_vec_z << std::endl;
        ss << "  imu_euler_vec_w: " << imu_euler_vec_w << std::endl;
        ss << "  imu_quat_x: " << imu_quat_x << std::endl;
        ss << "  imu_quat_y: " << imu_quat_y << std::endl;
        ss << "  imu_quat_z: " << imu_quat_z << std::endl;
        ss << "  imu_quat_w: " << imu_quat_w << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << last_transition_ccno;          // offset: 0
        map << mcl_control_cycle_num;         // offset: 8
        map << time_t_average_cycle_time_us;  // offset: 16
        map << time_t_control_cycle_limit_us; // offset: 20
        map << time_t_last_cycle_end_us;      // offset: 24
        map << imu_linear_acc_vec_f_x;        // offset: 28
        map << imu_linear_acc_vec_f_y;        // offset: 32
        map << imu_linear_acc_vec_f_z;        // offset: 36
        map << imu_acc_vec_f_x;               // offset: 40
        map << imu_acc_vec_f_y;               // offset: 44
        map << imu_acc_vec_f_z;               // offset: 48
        map << imu_gyr_vec_x;                 // offset: 52
        map << imu_gyr_vec_y;                 // offset: 56
        map << imu_gyr_vec_z;                 // offset: 60
        map << imu_euler_vec_x;               // offset: 64
        map << imu_euler_vec_y;               // offset: 68
        map << imu_euler_vec_z;               // offset: 72
        map << imu_euler_vec_w;               // offset: 76
        map << imu_quat_x;                    // offset: 80
        map << imu_quat_y;                    // offset: 84
        map << imu_quat_z;                    // offset: 88
        map << imu_quat_w;                    // offset: 92
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> last_transition_ccno;          // offset: 0
        map >> mcl_control_cycle_num;         // offset: 8
        map >> time_t_average_cycle_time_us;  // offset: 16
        map >> time_t_control_cycle_limit_us; // offset: 20
        map >> time_t_last_cycle_end_us;      // offset: 24
        map >> imu_linear_acc_vec_f_x;        // offset: 28
        map >> imu_linear_acc_vec_f_y;        // offset: 32
        map >> imu_linear_acc_vec_f_z;        // offset: 36
        map >> imu_acc_vec_f_x;               // offset: 40
        map >> imu_acc_vec_f_y;               // offset: 44
        map >> imu_acc_vec_f_z;               // offset: 48
        map >> imu_gyr_vec_x;                 // offset: 52
        map >> imu_gyr_vec_y;                 // offset: 56
        map >> imu_gyr_vec_z;                 // offset: 60
        map >> imu_euler_vec_x;               // offset: 64
        map >> imu_euler_vec_y;               // offset: 68
        map >> imu_euler_vec_z;               // offset: 72
        map >> imu_euler_vec_w;               // offset: 76
        map >> imu_quat_x;                    // offset: 80
        map >> imu_quat_y;                    // offset: 84
        map >> imu_quat_z;                    // offset: 88
        map >> imu_quat_w;                    // offset: 92
    }
};

} // namespace msg
} // namespace sfr
} // namespace mavlink
