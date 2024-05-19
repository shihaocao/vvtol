#include <state_field_registry.hpp>
#include <task.hpp>
#include <pwm_control_task.hpp>

#ifdef NATIVE
#include <chrono>
#endif

PwmControlTask::PwmControlTask(StateFields &sfr) : sfr_(sfr)
{
}

void PwmControlTask::setup()
{
    fin_py.attach(FIN_PY_PIN);
};

void PwmControlTask::execute()
{
    fin_py_pos += 5;
    fin_py_pos = fin_py_pos % 180;
    fin_py.write(fin_py_pos);
}