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
    sfr_.state_global_acc = sfr_.imu_linear_acc;
    sfr_.state_global_vel = sfr_.state_global_vel + sfr_.imu_linear_acc * sfr_.delta_t_s;
    sfr_.state_global_pos = sfr_.state_global_pos + sfr_.state_global_vel * sfr_.delta_t_s;
}