#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>
#include <continuation_dispatch_vector.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class MainControlSM : public Task<MainControlSM>
{
    StateFields &sfr_;

    ContinuationDispatchVector empty_cvd_;

public:
    std::string name = "main_control_sm";

    MainControlSM(StateFields &sfr);

    void setup();

    MainControl::State autonomous_control();

    void execute();
};