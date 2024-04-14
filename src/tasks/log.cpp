#include "log.hpp"

#ifdef NATIVE
#include <cstdio>
#else
#include <Arduino.h>
#endif

void log_init()
{
#ifndef NATIVE
#ifndef DEBUGSER
    Serial.begin(9600);
    while (!Serial)
    {
        ; // Wait for serial port to connect
    }
#endif
#endif
}

void log_printf(const char *format, ...)
{
#ifndef DEBUGSER
    va_list args;
    va_start(args, format);

#ifdef NATIVE
    vprintf(format, args);
    printf("\n");
#else
    char buffer[512];
    vsnprintf(buffer, sizeof(buffer), format, args);
    Serial.println(buffer);
#endif

    va_end(args);
#endif
}