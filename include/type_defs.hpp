enum MainControlState : unsigned char {
    EMPTY = 0,
    ARMED = 1,
    SAFEHOLD = 2,
    FLIGHT = 3,
    ABORT = 4,
    HALT = 5,
};

enum GncControlState : unsigned char {
    EMPTY = 0,
    SAFE = 1,
    HOLD = 2,
    ASCENT = 3,
    DESCENT = 4,
    TOUCHDOWN = 5,
    HALT = 6,
};