#include <state_field_registry.hpp>
#include <task.hpp>
#include <gnc_controller.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

static constexpr float kp = 1.0f;
static constexpr float ki = 0.1f;
static constexpr float kd = 1.0f;

GncController::GncController(StateFields &sfr) : sfr_(sfr)
{
}

void GncController::setup()
{
    sfr_.gnc_global_target_pos_f = {3, 2, 1};
}

void GncController::execute()
{
    sfr_.gnc_global_target_error_f = sfr_.gnc_global_target_pos_f - sfr_.gnc_global_linear_pos_f;
    lin::Vector3f P = kp * sfr_.gnc_global_target_error_f;
    lin::Vector3f derivative = (sfr_.gnc_global_target_error_f - previous_pos_error_) / sfr_.delta_t_s;
    lin::Vector3f D = kd * derivative;

    integral_ = sfr_.gnc_global_target_error_f * sfr_.delta_t_s;
    lin::Vector3f I = ki * integral_;
    sfr_.gnc_global_linear_acc_f = P + I + D;

    previous_pos_error_ = sfr_.gnc_global_target_error_f;
}