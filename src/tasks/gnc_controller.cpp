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
    sfr_.gnc_global_target_pos = {3, 2, 1};
    integral_ = lin::Vector3f{}; // Initialize the integral term to zero
}

void GncController::empty_control()
{
    if (sfr_.target_gnc_state != GncControl::State::EMPTY)
    {
        sfr_.gnc_state = GncControl::EMPTY;
    }
}

void GncController::initialization_control()
{
    if (sfr_.target_gnc_state != GncControl::State::INITIALIZATION)
    {
        sfr_.gnc_state = GncControl::INITIALIZATION;
    }
}

void GncController::ascent_control()
{
    if (sfr_.target_gnc_state != GncControl::State::ASCENT)
    {
        sfr_.gnc_state = GncControl::ASCENT;
    }
}

void GncController::safe_the_vehicle()
{
}

void GncController::safe_control()
{
    if (sfr_.target_gnc_state != GncControl::State::SAFE)
    {
        sfr_.gnc_state = GncControl::SAFE;
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
