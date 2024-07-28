import influxdb_client, os, time
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
from math import sin, pi
import random
import copy
from typing import *

import logging
# Configure logging to display the timestamp and the log level
logging.basicConfig(level=logging.DEBUG, 
                    format='%(asctime)s - %(levelname)s - %(message)s')

import sys
import serial
import argparse

from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv('secrets/influx_secrets.env')


import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

from lib.nanopb.state_field_registry_pb2 import StateFieldRegistry
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
    # point.field("mcl_control_cycle_number", sfr.mcl_control_cycle_num)
    # point.field("time_t_average_cycle_time_us", sfr.time_t_average_cycle_time_us)

    point = Point("vehicle_position").tag("vehicle_id", vehicle_id)

    '''[[[cog
    import psrc.sfr_gen.sfr_gen as sfr_gen
    sfr_gen.py_generate_all()
    ]]]'''
    points.append(vec_measurement(sfr.gnc_global_target_error_f, 'gnc_global_target_error_f', time_point))
    points.append(vec_measurement(sfr.gnc_global_target_pos_f, 'gnc_global_target_pos_f', time_point))
    points.append(vec_measurement(sfr.gnc_global_linear_pos_f, 'gnc_global_linear_pos_f', time_point))
    points.append(vec_measurement(sfr.gnc_global_linear_vel_f, 'gnc_global_linear_vel_f', time_point))
    points.append(vec_measurement(sfr.gnc_global_linear_acc_f, 'gnc_global_linear_acc_f', time_point))
    points.append(vec_measurement(sfr.gnc_global_quat, 'gnc_global_quat', time_point))
    points.append(vec_measurement(sfr.gnc_euler_angles, 'gnc_euler_angles', time_point))
    points.append(vec_measurement(sfr.sim_global_linear_pos_f, 'sim_global_linear_pos_f', time_point))
    points.append(vec_measurement(sfr.sim_global_linear_vel_f, 'sim_global_linear_vel_f', time_point))
    points.append(vec_measurement(sfr.sim_global_linear_acc_f, 'sim_global_linear_acc_f', time_point))
    points.append(vec_measurement(sfr.sim_global_quat, 'sim_global_quat', time_point))
    points.append(vec_measurement(sfr.sim_euler_angles, 'sim_euler_angles', time_point))
    point.field("time_t_average_cycle_time_us", sfr.time_t_average_cycle_time_us)
    point.field("mcl_control_cycle_num", sfr.mcl_control_cycle_num)
    point.field("mc_state", sfr.mc_state)
    point.field("target_mc_state", sfr.target_mc_state)
    point.field("gnc_state", sfr.gnc_state)
    point.field("target_gnc_state", sfr.target_gnc_state)
    #[[[end]]]
    point.time(time_point)  # Use current time in nanoseconds
    points.append(point)

    points.append(vec_measurement(sfr.imu_gyr_vec, 'imu_gyr_vec', time_point))
    points.append(vec_measurement(sfr.imu_acc_vec_f, 'imu_acc_vec_f', time_point))

    write_api.write(bucket=bucket, org=org, record=points)

class AirProtoReader:

    def __init__(self, source: Any, is_serial: bool = True):
        self.source = source
        self.decoder = AirProtoDecoder()
        self.is_serial = is_serial

    def read_and_maybe_result(self):
        if self.is_serial:
            data = self.source.read(1024)  # Adjust size as needed
        else:
            data = os.read(self.source.fileno(), 1024)  # Adjust size as needed

        if not data:
            return None

        result = self.decoder.insert_bytes(data)

        if isinstance(result, StateFieldRegistry):
            logging.debug("Decoded message:")
            logging.debug(result)
            return result
        
        return None

def get_args():
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
        pipe_path = "/tmp/vvtol_downlink"  # Adjust the path to your named pipe
        if not os.path.exists(pipe_path):
            os.mkfifo(pipe_path)
    else:
        port = "/dev/ttyACM0"
        baud_rate = 9600

    print("RUNNING! LETS GOOO")
    while True:
        try:
            if args.radio or not args.native:
                ser = serial.Serial(port, baud_rate, timeout=0)  # `timeout=None` for blocking mode; set to 0 for non-blocking mode
                reader = AirProtoReader(ser)
            else:
                with open(pipe_path, 'rb', buffering=0) as fifo:
                    reader = AirProtoReader(fifo, is_serial=False)

                    while True:
                        time.sleep(0.01)
                        result = reader.read_and_maybe_result()
                        if result is None:
                            continue
                        # logging.info("Got result!")
                        post_sfr(result)

        except serial.SerialException as e:
            print(f"Error opening serial port: {e}. Trying again shortly.")
            time.sleep(0.5)
        except OSError as e:
            print(f"Error opening named pipe: {e}. Trying again shortly.")
            time.sleep(0.5)
        finally:
            if 'ser' in locals() and ser.is_open:
                ser.close()

if __name__ == "__main__":
    main()
