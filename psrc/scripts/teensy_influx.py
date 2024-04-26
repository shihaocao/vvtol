import influxdb_client, os, time
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
from math import sin, pi
import random
import copy

import sys
import serial

import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))


from include.protos.state_field_registry_pb2 import StateFieldRegistry
from psrc.telem.air_proto_decoder import AirProtoDecoder, AirProtoDecoderState


token = os.environ.get("INFLUXDB_TOKEN")
org = "vvtol"
url = "http://localhost:8086"

write_client = influxdb_client.InfluxDBClient(url=url, token=token, org=org)

bucket = "vvtol_telem"

write_api = write_client.write_api(write_options=SYNCHRONOUS)

# Vehicle ID
vehicle_id = "123ABC"


def post_sfr(sfr: StateFieldRegistry):

    # Create a point with the vehicle ID
    point = Point("vehicle_position").tag("vehicle_id", vehicle_id)
    point.field("mcl_control_cycle_number", sfr.mcl_control_cycle_num)
    point.field("time_t_average_cycle_time_us", sfr.time_t_average_cycle_time_us)
    # print(f"CCNO: {sfr.mcl_control_cycle_num} {type(sfr.mcl_control_cycle_num)}")
    # # Add 50 different telemetry fields to the point
    # # for i in range(50):
    # #     # Oscillate each telemetry field using a sinusoidal function
    # #     # and apply a random perturbation
    # telemetry_value = sin(elapsed_time * 2 * pi / 5) + random.uniform(1, 1)
    # point.field(f"dummy{0}", telemetry_value)
    # telemetry_value2 = sin(elapsed_time * 3 * pi / 5) + random.uniform(1, 1) - 2
    # point.field(f"dummy{1}", telemetry_value2)

    point.time(time.time_ns())  # Use current time in nanoseconds
    write_api.write(bucket=bucket, org=org, record=point)

    # Wait for 0.01 second before the next iteration
    time.sleep(0.01)

def main():
    port = "/dev/ttyACM0"
    baud_rate = 9600  # Adjust as needed for your device
    print("RUNNING! LETS GOOO")
    try:
        # Open the serial port
        ser = serial.Serial(port, baud_rate, timeout=0)  # `timeout=None` for blocking mode; set to 0 for non-blocking mode

        decoder = AirProtoDecoder()

        while True:
            # Read bytes from the serial port
            data = ser.read(1024)  # Adjust size as needed

            if not data:
                # No data received, continue to the next iteration
                continue

            # Insert the received bytes into the decoder
            result = decoder.insert_bytes(data)

            # Process the decoding result
            if isinstance(result, StateFieldRegistry):
                # print("Decoded message:")
                # print(result)

                post_sfr(result)
            elif result == AirProtoDecoderState.WAITING_FOR_MAGIC_BYTE:
                print("Waiting for magic byte...")
            elif result == AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_1:
                print("Waiting for length byte 1...")
            elif result == AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_2:
                print("Waiting for length byte 2...")
            elif result == AirProtoDecoderState.WAITING_FOR_PAYLOAD:
                print("Waiting for payload...")

    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        sys.exit(1)
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()

if __name__ == "__main__":
    main()
