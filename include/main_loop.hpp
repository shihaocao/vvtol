#pragma once

#include <vector>
#include <tuple>
#include <main_control_sm.hpp>
#include <time_task.hpp>
#include <task.hpp>
#include <imu_monitor.hpp>
#include <blink_led_task.hpp>
#include <functional>
#include <common/stats.hpp>
#include <downlink_task.hpp>
#include <pwm_control_task.hpp>

class MainLoop : public Task<MainLoop>
{
    StateFields &sfr_;
    std::tuple<ImuMonitor,
               MainControlSM,
               BlinkLedTask,
               DownlinkTask,
               PwmControlTask,
               TimeTask>
        task_list_;
    Stats stats_;

public:
    MainLoop(StateFields &sfr);

    void setup();

    void execute();
};