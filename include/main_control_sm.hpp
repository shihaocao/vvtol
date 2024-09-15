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

    uint32_t last_hc_millis_ = 0;

    MainControlSM(StateFields &sfr);

    void setup();

    void intermittently_health_check();
    void health_check();

    void armed_control();

    MainControl::State autonomous_control();

    void execute();
};