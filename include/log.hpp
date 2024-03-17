#ifndef LOG_HPP
#define LOG_HPP

#include <stdarg.h>

void log_init();
void log_printf(const char* format, ...);

#endif // LOG_HPP