#include <state_field_registry.hpp>
#include <task.hpp>
#include <downlink_task.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

// #include "air_nano_proto/air_nano_proto.hpp"
// #include <nanopb/state_field_registry.pb.h>

DownlinkTask::DownlinkTask(StateFields &sfr) : sfr_(sfr)
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