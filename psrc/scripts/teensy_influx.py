import influxdb_client, os, time
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS
from math import sin, pi
import random
import copy
from typing import *
import struct

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

# Batch settings
batch_size = 20  # Set the batch size to 100
point_batch = []  # A list to accumulate data points


def vec_measurement(field: Any, field_name: str, time_point: int) -> Point:
    point = Point("vector_measurement") \
        .tag("sensor", field_name) \
        .field("x", field.elements[0]) \
        .field("y", field.elements[1]) \
        .field("z", field.elements[2]) \
        .time(time_point)
    return point


def post_sfr(sfr: StateFieldRegistry):
    global point_batch
    points = []
    time_point = time.time_ns()

    point = Point("vehicle_position").tag("vehicle_id", vehicle_id)
    '''[[[cog
    import psrc.sfr_gen.sfr_gen as sfr_gen
    sfr_gen.py_generate_all()
    ]]]'''
    if len(sfr.zero_vec.elements) > 0:
        points.append(vec_measurement(sfr.zero_vec, 'zero_vec', time_point))
    if len(sfr.imu_linear_acc.elements) > 0:
        points.append(vec_measurement(sfr.imu_linear_acc, 'imu_linear_acc', time_point))
    if len(sfr.imu_acc.elements) > 0:
        points.append(vec_measurement(sfr.imu_acc, 'imu_acc', time_point))
    if len(sfr.imu_gyr_acc.elements) > 0:
        points.append(vec_measurement(sfr.imu_gyr_acc, 'imu_gyr_acc', time_point))
    if len(sfr.imu_euler_vec.elements) > 0:
        points.append(vec_measurement(sfr.imu_euler_vec, 'imu_euler_vec', time_point))
    if len(sfr.imu_quat.elements) > 0:
        points.append(vec_measurement(sfr.imu_quat, 'imu_quat', time_point))
    if len(sfr.gnc_global_target_error.elements) > 0:
        points.append(vec_measurement(sfr.gnc_global_target_error, 'gnc_global_target_error', time_point))
    if len(sfr.gnc_global_target_pos.elements) > 0:
        points.append(vec_measurement(sfr.gnc_global_target_pos, 'gnc_global_target_pos', time_point))
    if len(sfr.state_global_pos.elements) > 0:
        points.append(vec_measurement(sfr.state_global_pos, 'state_global_pos', time_point))
    if len(sfr.state_global_vel.elements) > 0:
        points.append(vec_measurement(sfr.state_global_vel, 'state_global_vel', time_point))
    if len(sfr.state_global_acc.elements) > 0:
        points.append(vec_measurement(sfr.state_global_acc, 'state_global_acc', time_point))
    if len(sfr.state_euler_vec.elements) > 0:
        points.append(vec_measurement(sfr.state_euler_vec, 'state_euler_vec', time_point))
    if len(sfr.gnc_target_global_acc.elements) > 0:
        points.append(vec_measurement(sfr.gnc_target_global_acc, 'gnc_target_global_acc', time_point))
    if len(sfr.gnc_global_quat.elements) > 0:
        points.append(vec_measurement(sfr.gnc_global_quat, 'gnc_global_quat', time_point))
    if len(sfr.gnc_euler_angles.elements) > 0:
        points.append(vec_measurement(sfr.gnc_euler_angles, 'gnc_euler_angles', time_point))
    if len(sfr.sim_global_linear_pos.elements) > 0:
        points.append(vec_measurement(sfr.sim_global_linear_pos, 'sim_global_linear_pos', time_point))
    if len(sfr.sim_global_linear_vel.elements) > 0:
        points.append(vec_measurement(sfr.sim_global_linear_vel, 'sim_global_linear_vel', time_point))
    if len(sfr.sim_global_linear_acc.elements) > 0:
        points.append(vec_measurement(sfr.sim_global_linear_acc, 'sim_global_linear_acc', time_point))
    if len(sfr.sim_global_quat.elements) > 0:
        points.append(vec_measurement(sfr.sim_global_quat, 'sim_global_quat', time_point))
    if len(sfr.sim_euler_angles.elements) > 0:
        points.append(vec_measurement(sfr.sim_euler_angles, 'sim_euler_angles', time_point))
    point.field("time_t_average_cycle_time_us", sfr.time_t_average_cycle_time_us)
    point.field("mcl_control_cycle_num", sfr.mcl_control_cycle_num)
    point.field("mc_state", sfr.mc_state)
    point.field("target_mc_state", sfr.target_mc_state)
    point.field("gnc_state", sfr.gnc_state)
    point.field("target_gnc_state", sfr.target_gnc_state)
    point.field("packed_imu_state", sfr.packed_imu_state)
    #[[[end]]]

    imu_sys_state, imu_gyr_state, imu_acc_state, imu_mag_state = struct.pack('>I', sfr.packed_imu_state)
    point.field("imu_sys_state", imu_sys_state)
    point.field("imu_gyr_state", imu_gyr_state)
    point.field("imu_acc_state", imu_acc_state)
    point.field("imu_mag_state", imu_mag_state)

    point.time(time_point)  # Use current time in nanoseconds
    points.append(point)

    point_batch.extend(points)

    # Write points if batch size is reached
    if len(point_batch) >= batch_size:
        logging.info(f"Writing batch of {len(point_batch)} points")
        write_api.write(bucket=bucket, org=org, record=point_batch)
        point_batch.clear()


# Optional: Write any remaining points before program ends
def flush_batch():
    global point_batch
    if point_batch:
        logging.info(f"Flushing final batch of {len(point_batch)} points")
        write_api.write(bucket=bucket, org=org, record=point_batch)
        point_batch.clear()


class AirProtoReader:

    def __init__(self, source: Any, is_serial: bool = True):
        self.source = source
        self.decoder = AirProtoDecoder()
        self.is_serial = is_serial
        self.log_interval = 100
        self.log_counter = 0

    def read_and_maybe_result(self):
        if self.is_serial:
            data = self.source.read(1024)  # Adjust size as needed
        else:
            data = os.read(self.source.fileno(), 1024)  # Adjust size as needed

        if not data:
            return None

        result = self.decoder.insert_bytes(data)

        if isinstance(result, StateFieldRegistry):
            self.log_counter += 1
            if self.log_counter % self.log_interval == 0:
                logging.info(f"Decode successful on counter_val {self.log_counter}")
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

    logging.info("RUNNING! LETS GOOO")

    def do_reading(reader: AirProtoReader):
        while True:
            time.sleep(0.001)
            result = reader.read_and_maybe_result()
            if result is None:
                continue

            post_sfr(result)

    while True:
        try:
            if args.radio or not args.native:
                ser = serial.Serial(port, baud_rate, timeout=0)  # `timeout=None` for blocking mode; set to 0 for non-blocking mode
                reader = AirProtoReader(ser)
                do_reading(reader)
            else:
                with open(pipe_path, 'rb', buffering=0) as fifo:
                    reader = AirProtoReader(fifo, is_serial=False)
                    do_reading(reader)

        except serial.SerialException as e:
            logging.error(f"Error opening serial port: {e}. Trying again shortly.")
            time.sleep(0.001)
        except OSError as e:
            logging.error(f"Error opening named pipe: {e}. Trying again shortly.")
            time.sleep(0.001)
        finally:
            if 'ser' in locals() and ser.is_open:
                ser.close()

    flush_batch()  # Ensure any remaining data is written before exit


if __name__ == "__main__":
    main()
