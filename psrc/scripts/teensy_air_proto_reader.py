import sys
import serial

import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))


from include.protos.state_field_registry_pb2 import StateFieldRegistry
from psrc.telem.air_proto_decoder import AirProtoDecoder, AirProtoDecoderState

def main():
    port = "/dev/ttyACM0"
    baud_rate = 9600  # Adjust as needed for your device

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

    except serial.SerialException as e:
        print(f"Error opening serial port: {e}")
        sys.exit(1)
    finally:
        if 'ser' in locals() and ser.is_open:
            ser.close()

if __name__ == "__main__":
    main()
