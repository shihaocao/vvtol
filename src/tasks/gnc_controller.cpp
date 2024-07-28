#include <state_field_registry.hpp>
#include <task.hpp>
#include <gnc_controller.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

GncController::GncController(StateFields &sfr) : sfr_(sfr)
{
}

void GncController::setup()
{
}

void GncController::execute()
{
}