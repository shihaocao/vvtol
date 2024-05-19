#include <state_field_registry.hpp>
#include <task.hpp>
#include <time_task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

uint32_t TimeTask::micro_count()
{
#ifdef NATIVE
    auto now = std::chrono::high_resolution_clock::now();
    auto now_us = std::chrono::time_point_cast<std::chrono::microseconds>(now).time_since_epoch().count();
    return now_us;
#else
    return micros();
#endif
}

TimeTask::TimeTask(StateFields &sfr) : sfr_(sfr)
{
}

void TimeTask::setup()
{
    sfr_.time_t_last_cycle_end_us = micro_count();
};

void TimeTask::delay_for_us(uint32_t delay_us)
{
#ifdef NATIVE
    std::this_thread::sleep_for(std::chrono::microseconds(delay_us));
#else
    delayMicroseconds(delay_us);
#endif
}

void TimeTask::execute()
{
    // Get the current time in microseconds
    uint32_t now_us = micro_count();

    // Calculate the target end time
    unsigned long target_end_time_us = sfr_.time_t_last_cycle_end_us + sfr_.time_t_control_cycle_limit_us;
    // Update last_cycle_start_us for the next cycle
    sfr_.time_t_last_cycle_end_us = target_end_time_us;

    // Calculate the sleep duration to meet the target cycle time
    long sleep_duration_us = target_end_time_us - now_us;

    // Sleep for the calculated duration if it is positive
    if (sleep_duration_us > 0)
    {
        delay_for_us(sleep_duration_us);
    }
    else
    {
        // We had a desync, the last cycle end time is not true anymore, update it
        sfr_.time_t_last_cycle_end_us = target_end_time_us;

        // TODO increment a desync counter, and maybe measure it
    }

    if (sfr_.mcl_control_cycle_num % 10 == 0)
    {
        // log() << "CCNO: " << sfr_.mcl_control_cycle_num << '\n';
    }

    if (sfr_.mcl_control_cycle_num % 100 == 0)
    {
        // log() << global_stats.to_string() << '\n';
    }

    // increment the cycle counter
    sfr_.mcl_control_cycle_num++;
    // log() << "Time task end\n";
}