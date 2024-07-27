#include <state_field_registry.hpp>
#include <task.hpp>
#include <attitude_estimator.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <atomic>

AttitudeEstimator::AttitudeEstimator(StateFields &sfr) : sfr_(sfr)
{
}

void AttitudeEstimator::setup()
{
}

void AttitudeEstimator::execute()
{
}