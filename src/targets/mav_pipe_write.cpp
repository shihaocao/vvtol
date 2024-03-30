#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include "include/mav/mav_gen/sfr_mavlink/mavlink.h" // Include the main header for MAVLink definitions

int main()
{
    // The path to the named pipe
    std::string pipePath = "/tmp/mavlink_pipe";

    // Open the named pipe for writing
    std::ofstream pipeOut;
    pipeOut.open(pipePath, std::ios::out | std::ios::binary);
    if (!pipeOut.is_open())
    {
        std::cerr << "Failed to open named pipe for writing." << std::endl;
        return -1;
    }

    // Main loop - write a message every second
    while (true)
    {
        // Create a dummy message of type STATE_FIELD_REGISTRY (or your message ID)
        mavlink_message_t message;
        mavlink_state_field_registry_t msg = {};
        msg.time_t_average_cycle_time_us = 101.0f; // Example dummy data
        msg.time_t_control_cycle_limit_us = 200;   // More dummy data
        // Continue filling in the msg structure with your data...

        // Serialize the message
        mavlink_msg_state_field_registry_encode(1, 200, &message, &msg); // 1 and 200 are example system and component IDs

        // Buffer to hold the serialized data
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        // Serialize the message into the buffer
        uint16_t len = mavlink_msg_to_send_buffer(buffer, &message);

        // Write the serialized data to the pipe
        pipeOut.write(reinterpret_cast<char *>(buffer), len);
        pipeOut.flush(); // Ensure the data is sent immediately

        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait for 1 second
    }

    return 0;
}
