#include <state_field_registry.hpp>
#include <task.hpp>
#include <state_estimator.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

StateEstimator::StateEstimator(StateFields &sfr) : sfr_(sfr)
{
}

void StateEstimator::setup()
{
}

void StateEstimator::execute()
{
}