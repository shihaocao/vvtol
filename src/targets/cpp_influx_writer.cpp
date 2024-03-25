#include <influxdb.hpp>
#include <chrono>
#include <cmath>
#include <random>
#include <iostream>
#include <thread>

int main()
{
    std::string url = "http://localhost:8086";
    std::string org = "vvtol";
    std::string bucket = "vvtol_telem";
    std::string token = std::getenv("INFLUXDB_TOKEN"); // Ensure the INFLUXDB_TOKEN environment variable is set

    // Create a client
    auto client = influxdb::InfluxDBFactory::Get(url + "?org=" + org + "&bucket=" + bucket + "&token=" + token);

    // Vehicle ID
    std::string vehicle_id = "123ABC";

    try
    {
        auto start_time = std::chrono::steady_clock::now();
        while (true)
        {
            auto elapsed_time = std::chrono::steady_clock::now() - start_time;
            auto elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(elapsed_time).count();

            // Generate dummy telemetry data
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(1, 2); // Random uniform distribution between 1 and 2

            double telemetry_value = sin(elapsed_seconds * 2 * M_PI / 5) + dis(gen);
            double telemetry_value2 = sin(elapsed_seconds * 3 * M_PI / 5) + dis(gen) - 2;

            // Create a point
            auto point = influxdb::Point{"vehicle_position"}
                             .addTag("vehicle_id", vehicle_id)
                             .addField("dummy0", telemetry_value)
                             .addField("dummy1", telemetry_value2)
                             .setTimestamp(std::chrono::system_clock::now());

            // Write the point
            client->write(std::move(point));

            // Wait for 0.01 second before the next iteration
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
