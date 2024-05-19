import influxdb_client, os, time
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
from math import sin, pi
import random
import copy

import logging
# Configure logging to display the timestamp and the log level
logging.basicConfig(level=logging.INFO, 
                    format='%(asctime)s - %(levelname)s - %(message)s')

import sys
import serial

import os
from typing import *
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

from dotenv import load_dotenv
import os

# Load environment variables from .env file
load_dotenv('secrets/influx_secrets.env')

from include.protos.state_field_registry_pb2 import StateFieldRegistry
from psrc.telem.air_proto_decoder import AirProtoDecoder, AirProtoDecoderState


token = os.environ.get("INFLUXDB_TOKEN")
org = "vvtol"
url = "http://localhost:8086"
logging.info(token)
write_client = influxdb_client.InfluxDBClient(url=url, token=token, org=org)

bucket = "vvtol_telem"

write_api = write_client.write_api(write_options=SYNCHRONOUS)

# Vehicle ID
vehicle_id = "123ABC"

def vec_measurement(field: Any, field_name: str, time_point: int) -> Point:
    p = point = Point("vector_measurement") \
        .tag("sensor", field_name) \
        .field("x", field.elements[0]) \
        .field("y", field.elements[1]) \
        .field("z", field.elements[2]) \
        .time(time_point)
    return p

def post_sfr(sfr: StateFieldRegistry):

    points = []
    time_point = time.time_ns()

    # Create a point with the vehicle ID
    point = Point("vehicle_position").tag("vehicle_id", vehicle_id)
    point.field("mcl_control_cycle_number", sfr.mcl_control_cycle_num)
    point.field("time_t_average_cycle_time_us", sfr.time_t_average_cycle_time_us)
    point.time(time_point)  # Use current time in nanoseconds
    points.append(point)

    points.append(vec_measurement(sfr.imu_gyr_vec, 'imu_gyr_vec', time_point))
    points.append(vec_measurement(sfr.imu_acc_vec_f, 'imu_acc_vec_f', time_point))

    write_api.write(bucket=bucket, org=org, record=points)

class AirProtoReader:

    def __init__(self, ser: serial.Serial):
        self.ser = ser
        self.decoder = AirProtoDecoder()

    def read_and_maybe_result(self):
        # Read bytes from the serial port
        data = self.ser.read(1024)  # Adjust size as needed

        if not data:
            # No data received, continue to the next iteration
            return None

        # Insert the received bytes into the decoder
        result = self.decoder.insert_bytes(data)

        # Process the decoding result
        if isinstance(result, StateFieldRegistry):
            logging.debug("Decoded message:")
            logging.debug(result)

            return result
        
        return None

def get_args():
    import argparse
    parser = argparse.ArgumentParser()

    parser.add_argument('--radio', action='store_true')
    parser.add_argument('--native', action='store_true')
    return parser.parse_args()

def main():

    args = get_args()
    if args.radio:
        port = "/dev/ttyUSB0"
        baud_rate = 57600
    elif args.native:
        """TODO:
        READ FROM A NAMED FIFO ON LINX
        """
        pass
    else:
        port = "/dev/ttyACM0"
        baud_rate = 9600  # Adjust as needed for your device

    print("RUNNING! LETS GOOO")
    while True:
        try:
            # Open the serial port
            ser = serial.Serial(port, baud_rate, timeout=0)  # `timeout=None` for blocking mode; set to 0 for non-blocking mode

            reader = AirProtoReader(ser)
            
            while True:
                time.sleep(0.01)
                result = reader.read_and_maybe_result()
                if result is None:
                    continue

                post_sfr(result)

        except serial.SerialException as e:
            print(f"Error opening serial port: {e}. Trying again shortly.")
            time.sleep(0.5)
        finally:
            if 'ser' in locals() and ser.is_open:
                ser.close()

if __name__ == "__main__":
    main()
