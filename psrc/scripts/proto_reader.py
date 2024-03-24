import subprocess
import socket

import os
import sys
sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))


from include.protos.state_field_registry_pb2 import StateFieldRegistry



def launch_cpp_program():
    # Launch the C++ program
    subprocess.Popen(["./send_data"])

def receive_and_decode():
    # Socket setup
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(('localhost', 12345))
        s.listen()

        # Accept connection from the C++ program
        conn, addr = s.accept()
        with conn:
            data = conn.recv(1024)  # Adjust buffer size as needed

    # Protobuf decoding
    message = StateFieldRegistry()
    message.ParseFromString(data)
    print("Received message:", message)

if __name__ == "__main__":
    launch_cpp_program()
    receive_and_decode()
