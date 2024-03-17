#pragma once

#ifndef NATIVE
#include <Arduino.h>
#endif

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

using Vector4f = std::array<float, 4>;
using Vector4d = std::array<float, 4>;
using Vector3f = std::array<float, 3>;
using Vector3d = std::array<float, 3>;
using Vector2f = std::array<float, 2>;
using Vector2d = std::array<float, 2>;
