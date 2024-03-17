#pragma once

#include <stdarg.h>
#include <string>
#include <sstream>
#include <memory>

void log_init();
void log_printf(const char* format, ...);

class Logger {
public:
    // Delete copy constructor and assignment operator
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Singleton access
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    // Specialization for the char type
    Logger& operator<<(char value) {
        stream << value;
        if (value == '\n') {
            // Perform the flush if the character is a newline
            stream.flush(); // Assuming 'flush' is a method of Logger that flushes the stream
        }
        return *this;
    }


    // Overload << operator for various types
    template<typename T>
    Logger& operator<<(const T& value) {
        stream << value;
        return *this;
    }

    // Explicit flush method
    void flush() {
        std::string output = stream.str();
        if (!output.empty()) {
            log_printf("%s", output.c_str());
            stream.str(""); // Clear the stream buffer after flushing
            stream.clear(); // Clear any error flags
        }
    }

private:
    // Private constructor for singleton
    Logger() = default;

    std::ostringstream stream;
};

// Wrapper functions if needed for ease of use
inline Logger& log() {
    return Logger::getInstance();
}