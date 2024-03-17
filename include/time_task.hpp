#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class TimeTask : public Task<TimeTask>{
    StateFieldRegistry& sfr_;

    static uint32_t micro_count();
public:
    std::string name = "time_task";

    static void delay_for_us(uint32_t delay_us);

    TimeTask(StateFieldRegistry& sfr);

    void setup();

    void execute();
};