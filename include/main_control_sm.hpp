#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>
#include <continuation_dispatch_vector.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class MainControlSM : public Task{
    StateFieldRegistry& sfr_;

    ContinuationDispatchVector empty_cvd_;

public:
    MainControlSM(StateFieldRegistry& sfr);

    void setup() override;

    MainControl::State autonomous_control();

    void execute() override;
};