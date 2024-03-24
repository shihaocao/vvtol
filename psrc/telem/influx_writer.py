import influxdb_client, os, time
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
from math import sin, pi
import random
import copy
token = os.environ.get("INFLUXDB_TOKEN")
org = "vvtol"
url = "http://localhost:8086"

write_client = influxdb_client.InfluxDBClient(url=url, token=token, org=org)

bucket = "vvtol_telem"

write_api = write_client.write_api(write_options=SYNCHRONOUS)

# Vehicle ID
vehicle_id = "123ABC"

try:
    start_time = time.time()
    while True:
        elapsed_time = time.time() - start_time

        # Create a point with the vehicle ID
        point = Point("vehicle_position").tag("vehicle_id", vehicle_id)
        
        # Add 50 different telemetry fields to the point
        # for i in range(50):
        #     # Oscillate each telemetry field using a sinusoidal function
        #     # and apply a random perturbation
        telemetry_value = sin(elapsed_time * 2 * pi / 5) + random.uniform(1, 1)
        point.field(f"dummy{0}", telemetry_value)
        telemetry_value2 = sin(elapsed_time * 3 * pi / 5) + random.uniform(1, 1) - 2
        point.field(f"dummy{1}", telemetry_value2)

        point.time(time.time_ns())  # Use current time in nanoseconds
        write_api.write(bucket=bucket, org=org, record=point)

        # Wait for 0.01 second before the next iteration
        time.sleep(0.01)
except KeyboardInterrupt:
    print("Simulation stopped by user.")
finally:
    write_client.close()
