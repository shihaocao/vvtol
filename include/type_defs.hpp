#pragma once

#ifndef NATIVE
#include <Arduino.h>
#endif

#include <vector_defs.hpp>
#include <array>

namespace MainControl {
    enum State : unsigned char {
        EMPTY = 0,
        ARMED = 1,
        SAFEHOLD = 2,
        FLIGHT = 3,
        ABORT = 4,
        HALT = 5,
    };
}

namespace GncControl {
    enum State : unsigned char {
        EMPTY = 0,
        SAFE = 1,
        HOLD = 2,
        ASCENT = 3,
        DESCENT = 4,
        TOUCHDOWN = 5,
        HALT = 6,
    };
}