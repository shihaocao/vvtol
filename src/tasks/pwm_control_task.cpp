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
    fin_py.attach(FIN_PY_PIN, 1000, 2000);
    fin_ny.attach(FIN_NY_PIN, 1000, 2000);

    // lower_motor.attach(LOWER_MOTOR_PIN, 1000, 2000);
    fin_py.write(0);
    sfr_.fin_py_cmd = 1500;
    sfr_.fin_ny_cmd = 1500;
    safe_pwm_outputs();
#endif
};

void PwmControlTask::safe_pwm_outputs()
{
#ifndef NATIVE
    // lower_motor.write(MOTOR_OFF_PWM);
    fin_py.writeMicroseconds(sfr_.fin_py_cmd);
    fin_ny.writeMicroseconds(sfr_.fin_ny_cmd);
#endif
}

void PwmControlTask::execute()
{
    // if (sfr_.mc_state != MainControl::State::FLIGHT)
    // {
    //     // TODO: Do not read from main SFR state,
    //     // Read from commanded flag
    //     // (SMs should propagate down, instead of looking up)
    //     safe_pwm_outputs();
    //     return;
    // }

    sfr_.fin_py_cmd += 20;
    sfr_.fin_ny_cmd += 20;

    if (sfr_.fin_py_cmd > 2000)
    {
        sfr_.fin_py_cmd = 1000;
    }

    if (sfr_.fin_ny_cmd > 2000)
    {
        sfr_.fin_ny_cmd = 1000;
    }

#ifndef NATIVE

    // fin_py.write(sfr_.fin_py_cmd);
    fin_py.writeMicroseconds(sfr_.fin_py_cmd);
    fin_ny.writeMicroseconds(sfr_.fin_ny_cmd);

    // Set some non zero throttle
    // lower_motor.write(10);
#endif
}