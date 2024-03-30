import os
import time

import os
import sys
sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

from pymavlink import mavutil

# Import the generated dialect package for your custom protocol
# from psrc.mavgen.sfr_mavlink import MAVLink as mavlink2
# from psrc.mavgen import sfr_mavlink as mavlink2
# from pymavlink.dialects.v20 import sfr_mavlink as mavlink2
# from pymavlink.dialects.v20 import sfr_mavlink as mavlink2
from pymavlink.dialects.v20 import common as mavlink2

def main():
    pipe_path = "/tmp/mavlink_pipe"
    
    # Ensure the pipe exists
    if not os.path.exists(pipe_path):
        print(f"Named pipe at {pipe_path} does not exist.")
        return
    
    # Open the named pipe for reading
    with open(pipe_path, 'rb') as pipe_in:
        # Create a MAVLink connection with the custom dialect
        # mav = mavutil.mavlink_connection(file=pipe_in, dialect="MAVLink")
        # mav = mavutil.mavlink_connection(file=pipe_in, dialect="sfr_mavlink")
        # mav = mavutil.mavlink_connection('file:', file=pipe_in, dialect="sfr_mavlink")
        mav = mavutil.mavlink_connection(pipe_path, dialect='sfr_mavlink')
        print("Starting to read messages...")
        
        while True:
            print("Waiting...")
            # Read a message from the pipe
            msg = mav.recv_match(type='STATE_FIELD_REGISTRY', blocking=True)
            if msg:
                # Check if the message is of your custom type
                if msg.get_type() == 'STATE_FIELD_REGISTRY':  # Replace with your message type
                    # Print the contents of the deserialized struct
                    print(f"Received STATE_FIELD_REGISTRY Message:")
                    print(f"Average Cycle Time (us): {msg.time_t_average_cycle_time_us}")
                    print(f"Control Cycle Limit (us): {msg.time_t_control_cycle_limit_us}")
                    # Add additional fields as needed
                    
                else:
                    print(f"Received message of type {msg.get_type()}")
            
            # Limit the rate of polling the pipe to reduce CPU usage
            # time.sleep(1)

if __name__ == "__main__":
    main()
