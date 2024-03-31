import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

from include.protos.state_field_registry_pb2 import StateFieldRegistry
from psrc.telem.air_proto_decoder import AirProtoDecoder, AirProtoDecoderState
def main():
    pipe_name = "/tmp/air_proto_pipe"

    # Check if the named pipe exists
    if not os.path.exists(pipe_name):
        print(f"Named pipe '{pipe_name}' does not exist.")
        sys.exit(1)

    # Open the named pipe in non-blocking mode
    pipe_fd = os.open(pipe_name, os.O_RDONLY | os.O_NONBLOCK)

    decoder = AirProtoDecoder()

    while True:
        try:
            # Read bytes from the pipe
            data = os.read(pipe_fd, 1024)

            if not data:
                # No data available, continue to the next iteration
                continue

            # Insert the received bytes into the decoder
            result = decoder.insert_bytes(data)

            # Check if a complete message is decoded
            if isinstance(result, StateFieldRegistry):
                print("Decoded message:")
                print(result)
            elif result == AirProtoDecoderState.WAITING_FOR_MAGIC_BYTE:
                print("Waiting for magic byte...")
            elif result == AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_1:
                print("Waiting for length byte 1...")
            elif result == AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_2:
                print("Waiting for length byte 2...")
            elif result == AirProtoDecoderState.WAITING_FOR_PAYLOAD:
                print("Waiting for payload...")

        except BlockingIOError:
            # No data available, continue to the next iteration
            continue

    # Close the named pipe
    os.close(pipe_fd)

if __name__ == "__main__":
    main()