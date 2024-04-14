// send_data.cpp
#include "include/protos/state_field_registry.pb.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <iostream>

int main()
{
    std::cout << "STARTED" << std::endl;
    // Socket setup
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Error opening socket." << std::endl;
        return -1;
    }

    sockaddr_in serv_addr{};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345); // Port number
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cerr << "Error connecting to socket." << std::endl;
        return -1;
    }

    // Protobuf serialization
    StateFields message;
    message.set_time_t_average_cycle_time_us(100.0);
    // Set other fields as necessary...

    std::string serialized;
    if (!message.SerializeToString(&serialized))
    {
        std::cerr << "Failed to serialize message." << std::endl;
        return -1;
    }

    // Send serialized data
    write(sockfd, serialized.data(), serialized.size());

    // Clean up
    close(sockfd);

    return 0;
}
