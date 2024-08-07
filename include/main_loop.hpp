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
#include <state_estimator.hpp>
#include <simulator_inject.hpp>
#include <gnc_controller.hpp>

class MainLoop : public Task<MainLoop>
{
    StateFields &sfr_;
    // If you update this list, you must also update main_loop.cpp
    std::tuple<ImuMonitor,
               SimulatorInject,
               StateEstimator,
               MainControlSM,
               BlinkLedTask,
               DownlinkTask,
               GncController,
               PwmControlTask,
               TimeTask>
        task_list_;
    Stats stats_;

public:
    MainLoop(StateFields &sfr);

    void setup();

    void execute();
};