#include <state_field_registry.hpp>
#include <task.hpp>
#include <downlink_task.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

DownlinkTask::DownlinkTask(StateFieldRegistry &sfr) : sfr_(sfr)
{
}

void DownlinkTask::setup()
{
#ifndef NATIVE
    log() << "Downlink setup complete" << '\n';
#endif
};

void DownlinkTask::execute()
{
}