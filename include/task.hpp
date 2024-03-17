#pragma once

#include <log.hpp>
#include <common/stats.hpp>

// class Task {
// public:
//     // Virtual destructor to ensure proper cleanup of derived class objects
//     // virtual ~Task() {}

//     // Pure virtual function for setup
//     virtual void setup() = 0;

//     // Pure virtual function for execute
//     virtual void execute() = 0;
// };


// Base class template
template <typename Derived>
class Task {
public:
    void execute_w_timer() {
        // Directly access the 'name' member variable of the Derived class
        std::string& name = static_cast<Derived*>(this)->name;
        stats().start_mark(name);
        // log_printf("Starting timer for: %s", name.c_str());
        // Call the execute method, which is specific to the derived class
        static_cast<Derived*>(this)->execute();
        // log_printf("Stopping timer for: %s", name.c_str());
        stats().end_mark(name);
    }
};

// // Derived class SpecificTaskA
// class SpecificTaskA : public NamedTimerTask<SpecificTaskA> {
// public:
//     std::string name = "Task A";

//     void execute() {
//         std::cout << "Executing specific logic for SpecificTaskA" << std::endl;
//         // Task-specific logic here
//     }
// };