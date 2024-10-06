#pragma once

#ifndef NATIVE
#include <Arduino.h>
#endif

#include <vector_defs.hpp>
#include <array>

namespace MainControl
{
    enum State : unsigned char
    {
        EMPTY = 0,
        INITIALIZATION = 1,
        ARMED = 2,
        SAFEHOLD = 3,
        FLIGHT = 4,
    };
}

namespace GncControl
{
    enum State : unsigned char
    {
        EMPTY = 0,
        INITIALIZATION = 1,
        SAFE = 2,
        ASCENT = 3,
    };
}