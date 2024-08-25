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
    sfr_.gnc_global_linear_vel_f = sfr_.gnc_global_linear_vel_f + sfr_.imu_linear_acc_vec * sfr_.delta_t_s;
    sfr_.gnc_global_linear_pos_f = sfr_.gnc_global_linear_pos_f + sfr_.gnc_global_linear_vel_f * sfr_.delta_t_s;
}