#include <state_field_registry.hpp>
#include <task.hpp>
#include <state_estimator.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

static constexpr float DEG_PER_RAD = 180 / M_PI;
StateEstimator::StateEstimator(StateFields &sfr) : sfr_(sfr)
{
}

void StateEstimator::setup()
{
}

void StateEstimator::execute()
{
    sfr_.state_global_acc = sfr_.imu_linear_acc;
    sfr_.state_global_vel = sfr_.state_global_vel + sfr_.imu_linear_acc * sfr_.delta_t_s;
    sfr_.state_global_pos = sfr_.state_global_pos + sfr_.state_global_vel * sfr_.delta_t_s;

    float w = sfr_.imu_quat[0];
    float x = sfr_.imu_quat[1];
    float y = sfr_.imu_quat[2];
    float z = sfr_.imu_quat[3];

    // Conversion to Euler angles (in radians)
    float euler_x, euler_y, euler_z;

    // Roll (x-axis rotation)
    float sinr_cosp = 2.0f * (w * x + y * z);
    float cosr_cosp = 1.0f - 2.0f * (x * x + y * y);
    euler_x = std::atan2(sinr_cosp, cosr_cosp);

    // Pitch (y-axis rotation)
    float sinp = 2.0f * (w * y - z * x);
    if (std::abs(sinp) >= 1)
        euler_y = std::copysign(M_PI / 2.0f, sinp); // use 90 degrees if out of range
    else
        euler_y = std::asin(sinp);

    // Yaw (z-axis rotation)
    float siny_cosp = 2.0f * (w * z + x * y);
    float cosy_cosp = 1.0f - 2.0f * (y * y + z * z);
    euler_z = std::atan2(siny_cosp, cosy_cosp);

    sfr_.state_euler_vec = {
        euler_x * DEG_PER_RAD, euler_y * DEG_PER_RAD, euler_z * DEG_PER_RAD};
}