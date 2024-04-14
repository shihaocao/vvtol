#include <iostream>
#include <thread>
#include <chrono>
#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "src/air_nano_proto/air_nano_proto.hpp"
#include "include/nanopb/state_field_registry.pb.h"

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
        // StateFields state_field_registry;
        StateFieldRegistry state_field_registry = StateFieldRegistry_init_zero;

        // Fill the message with dummy data
        state_field_registry.time_t_average_cycle_time_us = 123.456f;
        state_field_registry.time_t_control_cycle_limit_us = 1000;
        state_field_registry.time_t_last_cycle_end_us = 9876543;

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