#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#include "native_only/named_pipe_manager.hpp"
#endif

class DownlinkTask : public Task<DownlinkTask>
{
    StateFields &sfr_;
    int bar;

public:
    std::string name = "downlink_task";

    DownlinkTask(StateFields &sfr);

    void setup();

    void execute();
};