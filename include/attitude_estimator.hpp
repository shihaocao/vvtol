#pragma once

#include <state_field_registry.hpp>
#include <task.hpp>

#ifdef NATIVE
#include <chrono>
#include <thread>
#endif

#include <lin.hpp>

class AttitudeEstimator : public Task<AttitudeEstimator>
{
    StateFields &sfr_;

public:
    std::string name = "attitude_estimator";

    AttitudeEstimator(StateFields &sfr);

    void setup();

    void execute();

    lin::Vector4f body_quat_;
};