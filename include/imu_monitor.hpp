#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class ImuMonitor : public Task{
    StateFieldRegistry& sfr_;

public:

    ImuMonitor(StateFieldRegistry& sfr);

    void setup() override;

    void execute() override;
};