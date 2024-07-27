#include <state_field_registry.hpp>
#include <task.hpp>
#include <simulator_inject.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

SimulatorInject::SimulatorInject(StateFields &sfr) : sfr_(sfr)
{
}

void SimulatorInject::setup()
{
}

void SimulatorInject::execute()
{
    sfr_.global_coords = lin::Vector3f{0.0, 1.0, 2.0};
}