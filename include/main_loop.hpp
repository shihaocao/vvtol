#pragma once

#include <vector>
#include <tuple>
#include <main_control_sm.hpp>
#include <time_task.hpp>
#include <task.hpp>
#include <imu_monitor.hpp>
#include <functional>
#include <common/stats.hpp>
#include <downlink_task.hpp>

class MainLoop : public Task<MainLoop>
{
    StateFieldRegistry &sfr_;
    std::tuple<ImuMonitor, MainControlSM, DownlinkTask, TimeTask> task_list_;
    Stats stats_;

public:
    MainLoop(StateFieldRegistry &sfr);

    void setup();

    void execute();
};