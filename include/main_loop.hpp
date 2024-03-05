#pragma once

#include <vector>
#include <tuple>
#include <main_control_sm.hpp>
#include <time_task.hpp>
#include <task.hpp>

class MainLoop : public Task {
    StateFieldRegistry& sfr_;
    std::tuple<MainControlSM, TimeTask> task_list_;
    

public:
    MainLoop(StateFieldRegistry& sfr);

    void setup() override;

    void execute() override;
};