#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

#include <lin.hpp>

class GncController : public Task<GncController>
{
    StateFields &sfr_;

public:
    std::string name = "gnc_controller";

    GncController(StateFields &sfr);

    void setup();

    void execute();

    lin::Vector4f body_quat_;
};