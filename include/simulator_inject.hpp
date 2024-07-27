#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

#include <lin.hpp>

class SimulatorInject : public Task<SimulatorInject>
{
    StateFields &sfr_;

public:
    std::string name = "state_estimator";

    SimulatorInject(StateFields &sfr);

    void setup();

    void execute();

    lin::Vector4f body_quat_;
};