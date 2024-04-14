#include <iostream>
#include <thread>
#include <chrono>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "src/air_proto/air_proto.hpp"
#include "include/protos/state_field_registry.pb.h"

int main()
{
    // Create the named pipe
    const char *pipe_name = "/tmp/air_proto_pipe";
    mkfifo(pipe_name, 0666);

    // Open the named pipe for writing
    FILE *pipe = fopen(pipe_name, "w");
    if (pipe == nullptr)
    {
        std::cerr << "Failed to open named pipe for writing." << std::endl;
        return 1;
    }

    while (true)
    {
        // Create a StateFields message
        StateFields state_field_registry;

        // Fill the message with dummy data
        state_field_registry.set_time_t_average_cycle_time_us(123.456f);
        state_field_registry.set_time_t_control_cycle_limit_us(1000);
        state_field_registry.set_time_t_last_cycle_end_us(9876543);
        // state_field_registry.set_last_transition_ccno(1234567890);
        // state_field_registry.set_mcl_control_cycle_num(42);
        // state_field_registry.set_mc_state(MainControlState::MC_EMPTY);
        // state_field_registry.set_target_mc_state(MainControlState::MC_EMPTY);
        // state_field_registry.set_gnc_state(GncControlState::GNC_EMPTY);
        // state_field_registry.set_target_gnc_state(GncControlState::GNC_EMPTY);

        // Vector3f *imu_linear_acc_vec_f = state_field_registry.mutable_imu_linear_acc_vec_f();
        // imu_linear_acc_vec_f->add_elements(1.0f);
        // imu_linear_acc_vec_f->add_elements(2.0f);
        // imu_linear_acc_vec_f->add_elements(3.0f);

        // Vector3f *imu_acc_vec_f = state_field_registry.mutable_imu_acc_vec_f();
        // imu_acc_vec_f->add_elements(4.0f);
        // imu_acc_vec_f->add_elements(5.0f);
        // imu_acc_vec_f->add_elements(6.0f);

        // Vector3f *imu_gyr_vec = state_field_registry.mutable_imu_gyr_vec();
        // imu_gyr_vec->add_elements(7.0f);
        // imu_gyr_vec->add_elements(8.0f);
        // imu_gyr_vec->add_elements(9.0f);

        // Vector4f *imu_euler_vec = state_field_registry.mutable_imu_euler_vec();
        // imu_euler_vec->add_elements(10.0f);
        // imu_euler_vec->add_elements(11.0f);
        // imu_euler_vec->add_elements(12.0f);
        // imu_euler_vec->add_elements(13.0f);

        // Vector4f *imu_quat = state_field_registry.mutable_imu_quat();
        // imu_quat->add_elements(14.0f);
        // imu_quat->add_elements(15.0f);
        // imu_quat->add_elements(16.0f);
        // imu_quat->add_elements(17.0f);

        // Create an AirProto object and serialize the message
        AirProto air_proto;
        air_proto.serialize_to_buffer(state_field_registry);
        // AirProto air_proto;
        // air_proto.serialize_to_buffer(static_cast<const google::protobuf::Message &>(state_field_registry));

        // Write the serialized data to the named pipe
        fwrite(air_proto.data(), 1, air_proto.size(), pipe);
        fflush(pipe);

        // Sleep for a short duration to simulate periodic updates

        std::cout << "Wrote data!" << std::endl;
        // Sleep for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}