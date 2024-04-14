#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class ImuMonitor : public Task<ImuMonitor>
{
    StateFields &sfr_;

public:
    std::string name = "imu_montor";

    ImuMonitor(StateFields &sfr);

    void setup();

    void execute();
};