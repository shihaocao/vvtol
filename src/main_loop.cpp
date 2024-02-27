#include <main_loop.hpp>
#include <time_task.hpp>

MainLoop::MainLoop(StateFieldRegistry& sfr) : 
    sfr_(sfr_),
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
}