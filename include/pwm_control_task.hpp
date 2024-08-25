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

#ifndef T40
    static constexpr int FIN_PX_PIN = 2;
    static constexpr int FIN_NX_PIN = 3;
    static constexpr int FIN_PY_PIN = 28; // These are arbitrary, choose PCB optimal
    static constexpr int FIN_NY_PIN = 5;  // 5

    static constexpr int LOWER_MOTOR_PIN = 29;
#else
    // TEENSY 4.0
    static constexpr int FIN_PX_PIN = 22;
    static constexpr int FIN_NX_PIN = 23;
    static constexpr int FIN_PY_PIN = 5; // These are arbitrary, choose PCB optimal
    static constexpr int FIN_NY_PIN = 4; // 5

    static constexpr int LOWER_MOTOR_PIN = 3;
#endif
    static constexpr int MOTOR_OFF_PWM = 0;

    int fin_py_pos = 0;

    PwmControlTask(StateFields &sfr);

    void setup();
    void safe_pwm_outputs();
    void execute();
};