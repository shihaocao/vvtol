#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class TimeTask : public Task{
    StateFieldRegistry& sfr_;

    static uint32_t micro_count();

    static void delay_for_us(uint32_t delay_us);

public:
    TimeTask(StateFieldRegistry& sfr);

    void setup() override;

    void execute() override;
};