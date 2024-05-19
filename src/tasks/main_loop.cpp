#include <imu_monitor.hpp>
#include <main_loop.hpp>
#include <time_task.hpp>
#include <main_control_sm.hpp>
#include <downlink_task.hpp>
#include <log.hpp>

MainLoop::MainLoop(StateFields &sfr) : sfr_(sfr),
                                       task_list_(

                                           ImuMonitor(sfr_),
                                           MainControlSM(sfr_),
                                           BlinkLedTask(sfr_),
                                           DownlinkTask(sfr_),
                                           PwmControlTask(sfr_),
                                           TimeTask(sfr_))
{
}

void MainLoop::setup()
{
    std::apply([](auto &&...tasks)
               { (..., tasks.setup()); }, task_list_);

    log_init();
}

void MainLoop::execute()
{
    std::apply([](auto &&...tasks)
               { (..., tasks.execute_w_timer()); }, task_list_);
    // spdlog::info("Loop done!");

    log().flush(); // flush at the end of every CC, **ATLEAST** users can flush more if needed
}