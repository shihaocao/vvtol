#pragma once

#include <stdarg.h>
#include <string>
#include <sstream>
#include <memory>
#include <vector_defs.hpp>

void log_init();
void log_printf(const char *format, ...);

class Logger
{
public:
    // Delete copy constructor and assignment operator
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

    // Singleton access
    static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }

    // Specialization for the char type
    Logger &operator<<(char value)
    {
        stream << value;
        if (value == '\n')
        {
            // Perform the flush if the character is a newline
            stream.flush(); // Assuming 'flush' is a method of Logger that flushes the stream
        }
        return *this;
    }

    // template<typename T>
    // Logger& operator<<(Vector<T, 2> v2) {
    //     stream << "(" << v2.x() << ", " << v2.y() << ")\n";
    //     return *this;
    // }

    // template<typename T>
    // Logger& operator<<(Vector<T, 3> v) {
    //     stream << "(" << v.x() << ", " << v.y() << ", " << v.z() << ")\n";
    //     return *this;
    // }
    template <typename T, size_t N>
    Logger &operator<<(Vector<T, N> v)
    {
        stream << "(";
        // this should be evaluated at compile time.
        for (unsigned int i = 0; i < N - 1; i++)
        {
            stream << v[i] << ", ";
        }
        stream << v[N - 1] << ")\n";
        return *this;
    }

    // Overload << operator for various types
    template <typename T>
    Logger &operator<<(const T &value)
    {
        stream << value;
        return *this;
    }

    // Explicit flush method
    void flush()
    {
        std::string output = stream.str();
        if (!output.empty())
        {
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
inline Logger &log()
{
    return Logger::getInstance();
}