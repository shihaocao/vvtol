#include <state_field_registry.hpp>
#include <task.hpp>
#include <downlink_task.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

#include "air_nano_proto/air_nano_proto.hpp"
// #include <nanopb/state_field_registry.pb.h>
#include <state_field_registry.pb.h>

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
    StateFieldRegistry state_field_registry = StateFieldRegistry_init_zero;
    state_field_registry.mcl_control_cycle_num = sfr_.mcl_control_cycle_num;

    AirProto air_proto;

    air_proto.serialize_to_buffer(state_field_registry);
    log() << "Ser data:\n";
    Serial.write(air_proto.data(), air_proto.size()); // Write the buffer to the serial port.
    log() << "End ser data\n";
}