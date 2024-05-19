#include <state_field_registry.hpp>
#include <task.hpp>
#include <main_control_sm.hpp>
#include <time_task.hpp>
#include <log.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

// MainControlSM::MainControlSM(StateFields& sfr) : sfr_(sfr), empty_cvd_({
//         { [&] { return sfr_.mcl_control_cycle_num - sfr_.last_transition_ccno  > 10;},
//             [&] {
//                 spdlog::info("dispatching action");
//                 sfr_.mc_state = MainControl::State::ARMED;
//             },
//         },
//     }){

// }

MainControlSM::MainControlSM(StateFields &sfr) : sfr_(sfr), empty_cvd_({})
{
    empty_cvd_.add(
        [&]
        { return sfr.mcl_control_cycle_num - sfr.last_transition_ccno > 1; },
        [&]
        {
            log_printf("Waiting for initial warmup");
        });
    empty_cvd_.add(
        [&]
        { return sfr.mcl_control_cycle_num - sfr.last_transition_ccno > 80; },
        [&]
        {
            log_printf("Motor Init complete going to FLIGHT");
            sfr.mc_state = MainControl::State::FLIGHT;
            log_printf("Going to armed!");

            // log() << global_stats.to_string() << '\n';
        });
    empty_cvd_.add(
        [&]
        { return sfr.mcl_control_cycle_num - sfr.last_transition_ccno > 200; },
        [&]
        {
            log_printf("Flight complete going to HALT");
            sfr.mc_state = MainControl::State::HALT;
            log_printf("Going to HALT!");

            // log() << global_stats.to_string() << '\n';
        });
}

void MainControlSM::setup()
{
}

MainControl::State MainControlSM::autonomous_control()
{

    return MainControl::State::ARMED;
}

void MainControlSM::execute()
{

    switch (sfr_.mc_state)
    {
    case MainControl::State::EMPTY:
        empty_cvd_.execute();
    case MainControl::State::ABORT:
        // safe the vehicle
        sfr_.target_gnc_state = GncControl::State::DESCENT;
        break;
    case MainControl::State::HALT:
        sfr_.target_gnc_state = GncControl::State::HALT;
        break;
    }
}