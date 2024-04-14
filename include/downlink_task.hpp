#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class DownlinkTask : public Task<DownlinkTask>
{
    StateFieldRegistry &sfr_;

public:
    std::string name = "downlink_task";

    DownlinkTask(StateFieldRegistry &sfr);

    void setup();

    void execute();
};