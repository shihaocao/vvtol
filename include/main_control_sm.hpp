#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class MainControlSM : public Task{
    StateFieldRegistry& sfr_;

public:
    MainControlSM(StateFieldRegistry& sfr);

    void setup() override;

    MainControlState autonomous_control();

    void execute() override;
};