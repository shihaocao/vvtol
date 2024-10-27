#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

#ifndef NATIVE
#include <Servo.h>
#endif

class PwmControlTask : public Task<PwmControlTask>
{
    StateFields &sfr_;

#ifndef NATIVE
    Servo fin_px;
    Servo fin_nx;
    Servo fin_py;
    Servo fin_ny;

    Servo lower_motor;
#endif

public:
    std::string name = "pwm_control_task";

    int fin_py_pos = 0;

    PwmControlTask(StateFields &sfr);

    void setup();
    void safe_pwm_outputs();
    void execute();
};