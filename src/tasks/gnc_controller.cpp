#include <state_field_registry.hpp>
#include <task.hpp>
#include <gnc_controller.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>
#include <cmath> // For atan2f, asinf, and copysignf

static constexpr float kp = 1.0f;
static constexpr float ki = 0.0f;
static constexpr float kd = 2.0f; // Change kd to a positive value

GncController::GncController(StateFields &sfr) : sfr_(sfr)
{
}

void GncController::setup()
{
    sfr_.gnc_global_target_pos = {3, 2, 1};
    integral_ = lin::Vector3f{}; // Initialize the integral term to zero
}

void GncController::empty_control()
{
    if (sfr_.gnc_state != GncControl::State::EMPTY)
    {
        sfr_.gnc_state = GncControl::State::EMPTY;
    }
}

void GncController::initialization_control()
{
    if (sfr_.gnc_state != GncControl::State::INITIALIZATION)
    {
        sfr_.gnc_state = GncControl::State::INITIALIZATION;

        // Store the target
        sfr_.gnc_orientation_target_quat = sfr_.imu_quat;
    }
}

void quat_conj(lin::Vector4f const &q, lin::Vector4f &res)
{
    res = {q(0), -q(1), -q(2), -q(3)};
}

lin::Vector4f hamilton_product(lin::Vector4f const &q, lin::Vector4f const &r)
{
    lin::Vector4f res = {
        (r(0) * q(0) - r(1) * q(1) - r(2) * q(2) - r(3) * q(3)),
        (r(0) * q(1) + r(1) * q(0) - r(2) * q(3) + r(3) * q(2)),
        (r(0) * q(2) + r(1) * q(3) + r(2) * q(0) - r(3) * q(1)),
        (r(0) * q(3) - r(1) * q(2) + r(2) * q(1) + r(3) * q(0)),
    };
    return res;
}

lin::Vector3f quaternionToRPY(const lin::Vector4f &delta_quat)
{
    float w = delta_quat(0);
    float x = delta_quat(1);
    float y = delta_quat(2);
    float z = delta_quat(3);

    // Calculate Roll (rotation around X-axis)
    float sinr_cosp = 2.0f * (w * x + y * z);
    float cosr_cosp = 1.0f - 2.0f * (x * x + y * y);
    float roll = atan2f(sinr_cosp, cosr_cosp);

    // Calculate Pitch (rotation around Y-axis)
    float sinp = 2.0f * (w * y - z * x);
    float pitch;
    if (fabsf(sinp) >= 1.0f)
        pitch = copysignf(M_PI / 2.0f, sinp); // Use 90 degrees if out of range
    else
        pitch = asinf(sinp);

    // Calculate Yaw (rotation around Z-axis)
    float siny_cosp = 2.0f * (w * z + x * y);
    float cosy_cosp = 1.0f - 2.0f * (y * y + z * z);
    float yaw = atan2f(siny_cosp, cosy_cosp);

    // Construct and return a lin::Vector3f
    return {roll, pitch, yaw};
}

void GncController::ascent_control()
{
    if (sfr_.gnc_state != GncControl::State::ASCENT)
    {
        sfr_.gnc_state = GncControl::State::ASCENT;
    }

    lin::Vector4f ref_inv{};
    quat_conj(sfr_.gnc_orientation_target_quat, ref_inv);
    lin::Vector4f delta_quat = hamilton_product(ref_inv, sfr_.imu_quat);
    sfr_.gnc_orientation_error_deg = quaternionToRPY(delta_quat);
    sfr_.gnc_orientation_error_deg = 180 * sfr_.gnc_orientation_error_deg / M_PI;

    lin::Matrix4x3f M = {
        1.0f, 0.0f, 0.0f,  // Maps roll error to px fin
        -1.0f, 0.0f, 0.0f, // Maps roll error to nx fin
        0.0f, 1.0f, 0.0f,  // Maps pitch error to py fin
        0.0f, -1.0f, 0.0f  // Maps pitch error to ny fin
    };

    // Compute the fin commands as M * rpy_errors
    lin::Vector4f fin_commands = M * sfr_.gnc_orientation_error_deg;

    // Microseconds offset
    fin_commands = fin_commands * 2;
    fin_commands = fin_commands + 1500;

    sfr_.fin_px_cmd = fin_commands(0);
    sfr_.fin_nx_cmd = fin_commands(1);
    sfr_.fin_py_cmd = fin_commands(2);
    sfr_.fin_ny_cmd = fin_commands(3);
}

void GncController::safe_the_vehicle()
{
}

void GncController::safe_control()
{
    if (sfr_.gnc_state != GncControl::State::SAFE)
    {
        sfr_.gnc_state = GncControl::State::SAFE;
    }
}

void GncController::execute()
{

    switch (sfr_.target_gnc_state)
    {
    case GncControl::State::EMPTY:
        empty_control();
        break;
    case GncControl::State::INITIALIZATION:
        initialization_control();
        break;
    case GncControl::State::ASCENT:
        ascent_control();
        break;
    case GncControl::State::SAFE:
        safe_control();
        break;
    }
}

void GncController::pid_cmd_control()
{
    sfr_.gnc_global_target_error = sfr_.gnc_global_target_pos - sfr_.state_global_pos;
    lin::Vector3f P = kp * sfr_.gnc_global_target_error;

    lin::Vector3f derivative = (sfr_.gnc_global_target_error - previous_pos_error_) / sfr_.delta_t_s;
    lin::Vector3f D = kd * derivative;

    integral_ = integral_ + sfr_.gnc_global_target_error * sfr_.delta_t_s; // Accumulate the integral term
    lin::Vector3f I = ki * integral_;

    sfr_.gnc_target_global_acc = P + I + D;

    previous_pos_error_ = sfr_.gnc_global_target_error;
}
