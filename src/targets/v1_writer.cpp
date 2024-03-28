#include "thirdparty/influxdb-cpp/influxdb.hpp"
#include <chrono>
#include <cmath>
#include <random>
#include <iostream>
#include <thread>

inline long long get_now_ns()
{
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int main()
{
    std::string url = "http://localhost:8086";
    std::string org = "vvtol";
    std::string bucket = "vvtol_telem";
    std::string token = std::getenv("INFLUXDB_TOKEN"); // Ensure the INFLUXDB_TOKEN environment variable is set
    std::cout << "Connecting client..." << std::endl;
    influxdb_cpp::server_info si("127.0.0.1", 8086, "&org=vvtol&bucket=vvtol_telem", "", "", "ms", token);

    // Create a client
    // auto client = influxdb::InfluxDBFactory::Get(url + "?org=" + org + "&bucket=" + bucket + "&token=" + token);
    std::cout << "Client connected!" << std::endl;

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

            std::string resp;

            int ret = influxdb_cpp::builder()
                          .meas("test")
                          .tag("vehicle_id", "123ABC")
                          //   .tag("k", "v")
                          //   .tag("x", "y")
                          .field("x", telemetry_value)
                          .field("y", telemetry_value2)
                          .timestamp(get_now_ns())
                          .post_http(si, &resp);

            // // Create a point
            // auto point = influxdb::Point{"vehicle_position"}
            //                  .addTag("vehicle_id", vehicle_id)
            //                  .addField("dummy0", telemetry_value)
            //                  .addField("dummy1", telemetry_value2)
            //                  .setTimestamp(std::chrono::system_clock::now());

            // Write the point
            // client->write(std::move(point));
            std::cout << "Wrote data ret: " << ret << std::endl;
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
