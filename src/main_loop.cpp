#include <main_loop.hpp>
#include <time_task.hpp>
#include <log.hpp>

MainLoop::MainLoop(StateFieldRegistry& sfr) : 
    sfr_(sfr),
    task_list_{TimeTask(sfr_)}
    {
}

void MainLoop::setup() {
    for (auto task : task_list_) {
        task.setup();
    }
}

void MainLoop::execute() {
    for (auto task : task_list_) {
        task.execute();
    }
    spdlog::info("Loop done!");
}