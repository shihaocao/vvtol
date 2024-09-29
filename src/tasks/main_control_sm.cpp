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
        { return sfr.mcl_now_ts_ms > 1000; },
        [&]
        {
            sfr.mc_state = MainControl::State::INITIALIZATION;
        });
    empty_cvd_.add(
        [&]
        { return sfr.mcl_now_ts_ms > 10 * 1000; },
        [&]
        {
            sfr.mc_state = MainControl::State::ARMED;
        });
}

void MainControlSM::setup()
{
}

MainControl::State MainControlSM::autonomous_control()
{

    return MainControl::State::ARMED;
}

void MainControlSM::intermittently_health_check()
{
#ifndef NATIVE
    uint32_t now_millis = millis();
    if (now_millis > last_hc_millis_ + HC_INTERVAL_MS)
    {
        last_hc_millis_ = now_millis;
        health_check();
    }
#endif
#ifdef NATIVE
    using namespace std::chrono;
    auto now = duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
    if (now > last_hc_millis_ + HC_INTERVAL_MS)
    {
        last_hc_millis_ = now;
        health_check();
    }
#endif
}

void MainControlSM::health_check()
{
    log_printf("On CCNO: %u", sfr_.mcl_control_cycle_num);
}

void MainControlSM::armed_control()
{
    return;
}

void MainControlSM::empty_control()
{
    // Entry Procedure
    if (sfr_.mc_state != MainControl::EMPTY)
    {
        sfr_.target_gnc_state = GncControl::State::EMPTY;
        sfr_.mc_state = MainControl::EMPTY;
    }

    // Exit condition
    if (sfr_.mcl_now_ts_ms > 1 * 1000)
    {
        sfr_.target_mc_state = MainControl::State::INITIALIZATION;
    }
}

void MainControlSM::initialization_control()
{
    // Entry Procedure
    if (sfr_.mc_state != MainControl::INITIALIZATION)
    {
        sfr_.target_gnc_state = GncControl::State::INITIALIZATION;
        sfr_.mc_state = MainControl::INITIALIZATION;
    }
    // Exit condition
    if (sfr_.mcl_now_ts_ms > 10 * 1000)
    {
        sfr_.target_mc_state = MainControl::State::FLIGHT;
    }
}

void MainControlSM::flight_control()
{
    // Entry Procedure
    if (sfr_.mc_state != MainControl::State::FLIGHT)
    {
        sfr_.target_gnc_state = GncControl::State::ASCENT;
        sfr_.mc_state = MainControl::State::FLIGHT;
    }

    // Exit Condition
    if (sfr_.mcl_now_ts_ms > 20 * 1000)
    {
        sfr_.target_mc_state = MainControl::State::SAFEHOLD;
    }
}

void MainControlSM::safehold_control()
{
    // Entry Procedure
    if (sfr_.mc_state != MainControl::State::SAFEHOLD)
    {
        // Safe the vehicle.
        sfr_.mc_state = MainControl::State::SAFEHOLD;
        sfr_.target_gnc_state = GncControl::State::SAFE;
        (void)false;
    }

    // No exit condition other than power off.
}

void MainControlSM::execute()
{
    intermittently_health_check();
    switch (sfr_.target_mc_state)
    {
    case MainControl::State::EMPTY:
        empty_control();
        break;
    case MainControl::State::INITIALIZATION:
        initialization_control();
        break;
    case MainControl::State::ABORT:
        // safe the vehicle
        sfr_.target_gnc_state = GncControl::State::DESCENT;
        break;
    case MainControl::State::HALT:
        sfr_.target_gnc_state = GncControl::State::HALT;
        break;
    case MainControl::State::ARMED:
        armed_control();
        break;
    case MainControl::State::SAFEHOLD:
        break;
    }
}