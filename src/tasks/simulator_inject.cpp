#include <state_field_registry.hpp>
#include <task.hpp>
#include <simulator_inject.hpp>

#ifdef NATIVE
#include <chrono>
#endif

#include <vector>
#include <vvtol_constants.hpp>

static lin::internal::RandomsGenerator lin_rand;

SimulatorInject::SimulatorInject(StateFields &sfr) : sfr_(sfr)
{
}

void SimulatorInject::setup()
{
    sfr_.sim_global_linear_pos = lin::Vector3f{0.0, 0.0, 0.0};
    // sfr_.time_t_control_cycle_limit_ms = 100;
}

void SimulatorInject::execute_sim()
{

    lin::Vector3f random_buffetting_acc = lin::gaussians<lin::Vector3f>(lin_rand, 3, 1);
    sfr_.sim_global_linear_acc = random_buffetting_acc + sfr_.state_global_acc;

    const float delta_t_s = float(sfr_.time_t_control_cycle_limit_ms) * S_IN_MS;
    sfr_.sim_global_linear_vel = sfr_.sim_global_linear_vel + sfr_.sim_global_linear_acc * delta_t_s;
    // std::cout << "Delta: " << delta_t_s << " " << sfr_.sim_global_linear_vel[0] << " " << sfr_.sim_global_linear_vel[1] << std::endl;
    sfr_.sim_global_linear_pos = sfr_.sim_global_linear_pos + sfr_.sim_global_linear_vel * delta_t_s;

    // Model noise
    lin::Vector3f random_noise_acc = lin::gaussians<lin::Vector3f>(lin_rand, 3, 1);

    // directly inject state into sensor readings
    sfr_.imu_linear_acc = sfr_.sim_global_linear_acc + random_noise_acc;
    // sfr_.state_global_pos = sfr_.sim_global_linear_pos;
}

void SimulatorInject::execute()
{
#ifdef NATIVE
    execute_sim();
#endif
}