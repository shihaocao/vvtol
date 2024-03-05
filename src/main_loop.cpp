#include <main_loop.hpp>
#include <time_task.hpp>
#include <main_control_sm.hpp>
#include <log.hpp>

MainLoop::MainLoop(StateFieldRegistry& sfr) : 
    sfr_(sfr),
    task_list_(
        {MainControlSM(sfr_),
        TimeTask(sfr_)})
    {
}

void MainLoop::setup() {
    std::apply([](auto&&... tasks) { (..., tasks.setup()); }, task_list_);

}

void MainLoop::execute() {
    std::apply([](auto&&... tasks) { (..., tasks.execute()); }, task_list_);
    // spdlog::info("Loop done!");
}