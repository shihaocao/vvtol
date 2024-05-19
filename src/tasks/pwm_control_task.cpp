#include <state_field_registry.hpp>
#include <task.hpp>
#include <pwm_control_task.hpp>
#include <type_defs.hpp>

#ifdef NATIVE
#include <chrono>
#endif

PwmControlTask::PwmControlTask(StateFields &sfr) : sfr_(sfr)
{
}

void PwmControlTask::setup()
{
#ifndef NATIVE
    fin_py.attach(FIN_PY_PIN);
    lower_motor.attach(LOWER_MOTOR_PIN, 1000, 2000);
    fin_py.write(0);
    safe_pwm_outputs();
#endif
};

void PwmControlTask::safe_pwm_outputs()
{
#ifndef NATIVE
    lower_motor.write(MOTOR_OFF_PWM);
#endif
}

void PwmControlTask::execute()
{
    if (sfr_.mc_state != MainControl::State::FLIGHT)
    {
        // TODO: Do not read from main SFR state,
        // Read from commanded flag
        // (SMs should propagate down, instead of looking up)
        safe_pwm_outputs();
        return;
    }

    fin_py_pos += 5;
    fin_py_pos = fin_py_pos % 180;
#ifndef NATIVE
    fin_py.write(fin_py_pos);

    // Set some non zero throttle
    lower_motor.write(10);
#endif
}