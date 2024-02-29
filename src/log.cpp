// log.cpp
#include "log.hpp"

#include "spdlog/details/null_mutex.h"
#include <mutex>

#ifdef NATIVE
    #include <iostream>
    #include <spdlog/sinks/stdout_color_sinks.h>
#else
    #include <Arduino.h>
    #include <spdlog/sinks/base_sink.h>
#endif

// Custom Sink definition
template<typename Mutex>
class CustomArduinoSink : public spdlog::sinks::base_sink<Mutex> {
protected:
    void sink_it_(const spdlog::details::log_msg& msg) override {
        spdlog::memory_buf_t formatted;
        this->formatter_->format(msg, formatted);
        auto str = fmt::to_string(formatted);
        #ifdef NATIVE
        std::cout << str;
        #else
        Serial.print(str.c_str());
        #endif
    }

    void flush_() override {
        #ifdef NATIVE
        std::cout.flush();
        #else
        Serial.flush();
        #endif
    }
};

void setup_logger() {
    auto custom_sink = std::make_shared<CustomArduinoSink<spdlog::details::null_mutex>>();
    auto logger = std::make_shared<spdlog::logger>("main", std::move(custom_sink));
    spdlog::register_logger(logger);
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::info); // Set global log level to info
    #ifndef NATIVE
    Serial.begin(9600);
    #endif
}

