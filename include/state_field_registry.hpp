#pragma once

#include <stdint.h>

// Design idea: do not nest structs inside structs, just pass around a flat SFR
// all control logic should read from the SFR
// logic inside control tasks should pull references from the SFR
// if they must they can create a construct to reference the SFR
// but at the global level, this should remain flat

// design idea, dont use any unsigned ints.
// Generally, going negative is much safer than rolling over and going to zero

// enforce namspacing via prefixes
struct StateFieldRegistry{
    float time_t_average_cucle_time_us = -1;
    int time_t_control_cycle_limit_us = 20000;
    uint32_t time_t_last_cycle_start_us = 0;
    uint64_t mcl_control_cycle_num = 0;
};

