#pragma once

#include <log.hpp>
#include <common/stats.hpp>
#include <globals.hpp>

// Base class template
template <typename Derived>
class Task {
public:
    void execute_w_timer() {
        // Directly access the 'name' member variable of the Derived class
        std::string& name = static_cast<Derived*>(this)->name;
        global_stats.hist_s(name);
        // Call the execute method, which is specific to the derived class
        static_cast<Derived*>(this)->execute();
        global_stats.hist_e(name);
    }
};