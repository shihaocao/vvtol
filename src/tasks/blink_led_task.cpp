#include <state_field_registry.hpp>
#include <task.hpp>
#include <blink_led_task.hpp>

#ifdef NATIVE
#include <chrono>
#endif

BlinkLedTask::BlinkLedTask(StateFields &sfr) : sfr_(sfr)
{
}

static constexpr int ledPin = 13;
void BlinkLedTask::setup()
{
// Initialize the LED pin as an output
#ifndef NATIVE
    pinMode(ledPin, OUTPUT);
#endif
};

void BlinkLedTask::execute()
{
// Set the pin to desired state, and then invert it
// For the next cycle.
// At high rate this will cycle very quickly, but that's ok.
// This is meant to be a simple metric of cycle times.
// And most importantly whether or not the MainControlCycle
// is making progress.
#ifndef NATIVE
    digitalWrite(ledPin, is_led_on);
#endif
    is_led_on = !is_led_on;
}