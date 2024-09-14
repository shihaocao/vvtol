#include <state_field_registry.hpp>
#include <task.hpp>
#include <gnc_controller.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

static constexpr float kp = 1.0f;
static constexpr float ki = 0.0f;
static constexpr float kd = 2.0f; // Change kd to a positive value

GncController::GncController(StateFields &sfr) : sfr_(sfr)
{
}

void GncController::setup()
{
    sfr_.gnc_global_target_pos_f = {3, 2, 1};
    integral_ = lin::Vector3f{}; // Initialize the integral term to zero
}

void GncController::execute()
{
    sfr_.gnc_global_target_error_f = sfr_.gnc_global_target_pos_f - sfr_.gnc_global_linear_pos_f;
    lin::Vector3f P = kp * sfr_.gnc_global_target_error_f;

    lin::Vector3f derivative = (sfr_.gnc_global_target_error_f - previous_pos_error_) / sfr_.delta_t_s;
    lin::Vector3f D = kd * derivative;

    integral_ = integral_ + sfr_.gnc_global_target_error_f * sfr_.delta_t_s; // Accumulate the integral term
    lin::Vector3f I = ki * integral_;

    sfr_.gnc_global_linear_acc_f = P + I + D;

    previous_pos_error_ = sfr_.gnc_global_target_error_f;
}
