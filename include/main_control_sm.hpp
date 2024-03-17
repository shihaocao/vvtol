#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>
#include <continuation_dispatch_vector.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

class MainControlSM : public Task<MainControlSM>{
    StateFieldRegistry& sfr_;

    ContinuationDispatchVector empty_cvd_;

public:
    std::string name = "main_control_sm";

    MainControlSM(StateFieldRegistry& sfr);

    void setup();

    MainControl::State autonomous_control();

    void execute();
};