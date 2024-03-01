#include <state_field_registry.hpp>
#include <task.hpp>
#include <main_control_sm.hpp>
#include <time_task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

MainControlSM::MainControlSM(StateFieldRegistry& sfr) : sfr_(sfr) {

}

void MainControlSM::setup() {

}

MainControlState MainControlSM::autonomous_control() {
    switch(sfr_.mc_state) {
        case MainControlState::EMPTY:
            return MainControlState::ARMED;
        case MainControlState::ARMED:
            // do your preflight checks here, and make sure the subsystems are ready
            TimeTask::delay_for_us(1000);
            return MainControlState::FLIGHT;
        case MainControlState::FLIGHT:
            TimeTask::delay_for_us(1000); // wait gotta figure out how to do this construct.
            return MainControlState::SAFEHOLD;
    }
}

void MainControlSM::execute() {

    switch(sfr_.mc_state) {
        case MainControlState::ABORT:
            // safe the vehicle
            sfr_.target_gnc_state = GncControlState::DESCENT;
            break;
        case MainControlState::HALT:
            sfr_.target_gnc_state = GncControlState::HALT;
            break;
    }
}