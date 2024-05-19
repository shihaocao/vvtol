#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class BlinkLedTask : public Task<BlinkLedTask>
{
    StateFields &sfr_;

public:
    std::string name = "blink_led_task";

    bool is_led_on = false;

    BlinkLedTask(StateFields &sfr);

    void setup();

    void execute();
};