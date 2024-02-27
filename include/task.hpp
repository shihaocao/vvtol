#pragma once

class Task {
public:
    // Virtual destructor to ensure proper cleanup of derived class objects
    // virtual ~Task() {}

    // Pure virtual function for setup
    virtual void setup() = 0;

    // Pure virtual function for execute
    virtual void execute() = 0;
};
