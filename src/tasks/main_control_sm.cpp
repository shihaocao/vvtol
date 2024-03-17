#include <state_field_registry.hpp>
#include <task.hpp>
#include <main_control_sm.hpp>
#include <time_task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

// MainControlSM::MainControlSM(StateFieldRegistry& sfr) : sfr_(sfr), empty_cvd_({
//         { [&] { return sfr_.mcl_control_cycle_num - sfr_.last_transition_ccno  > 10;},
//             [&] { 
//                 spdlog::info("dispatching action");
//                 sfr_.mc_state = MainControl::State::ARMED;
//             },
//         },
//     }){
    
// }

MainControlSM::MainControlSM(StateFieldRegistry& sfr) : sfr_(sfr), empty_cvd_({}) {
    empty_cvd_.add(
        [&] { return sfr.mcl_control_cycle_num - sfr.last_transition_ccno  > 50;},
        [&] { 
                spdlog::info("Waiting for initial warmup");
            } 
    );
    empty_cvd_.add(
        [&] { return sfr.mcl_control_cycle_num - sfr.last_transition_ccno  > 200;},
        [&] { 
                spdlog::info("Waiting for imu to calibrate");
                sfr.mc_state = MainControl::State::ARMED;
                spdlog::info("Going to armed!");
            } 
    );
}

void MainControlSM::setup() {

}

MainControl::State MainControlSM::autonomous_control() {
    switch(sfr_.mc_state) {
        case MainControl::State::EMPTY:
            return MainControl::State::ARMED;
        case MainControl::State::ARMED:
            // do your preflight checks here, and make sure the subsystems are ready
            ImuMonitor::delay_for_us(1000);
            return MainControl::State::FLIGHT;
        case MainControl::State::FLIGHT:
            ImuMonitor::delay_for_us(1000); // wait gotta figure out how to do this construct.
            return MainControl::State::SAFEHOLD;
    }
}

void MainControlSM::execute() {

    switch(sfr_.mc_state) {
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