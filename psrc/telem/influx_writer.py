import influxdb_client, os, time
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
from math import sin, pi

token = os.environ.get("INFLUXDB_TOKEN")
org = "vvtol"
url = "http://localhost:8086"

write_client = influxdb_client.InfluxDBClient(url=url, token=token, org=org)

bucket="vvtol_telem"

write_api = write_client.write_api(write_options=SYNCHRONOUS)
   
# Initial GPS coordinates
initial_latitude = 40.7128
initial_longitude = 74.0060
vehicle_id = "123ABC"

try:
    start_time = time.time()
    while True:
        elapsed_time = time.time() - start_time

        # Oscillate latitude and longitude using a sinusoidal function
        latitude = initial_latitude + 10 * sin(elapsed_time * 2 * pi / 5)
        longitude = initial_longitude + 10 * sin(elapsed_time * 2 * pi / 5)

        point = (
            Point("vehicle_position")
            .tag("vehicle_id", vehicle_id)
            .field("latitude", latitude)
            .field("longitude", longitude)
            .time(time.time_ns())  # Use current time in nanoseconds
        )
        write_api.write(bucket=bucket, org=org, record=point)

        # Wait for 1 second before the next iteration
        time.sleep(1)
except KeyboardInterrupt:
    print("Simulation stopped by user.")
finally:
    client.close()