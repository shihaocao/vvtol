#pragma once

#include <vector>
#include <time_task.hpp>
#include <task.hpp>

class MainLoop : public Task {
    StateFieldRegistry& sfr_;
    std::vector<TimeTask> task_list_;

public:
    MainLoop(StateFieldRegistry& sfr);

    void setup() override;

    void execute() override;
};