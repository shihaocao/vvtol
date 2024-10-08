import struct
from lib.nanopb.state_field_registry_pb2 import StateFieldRegistry
import logging

class AirProtoDecoderState:
    WAITING_FOR_MAGIC_BYTE = 0
    WAITING_FOR_LENGTH_BYTE_1 = 1
    WAITING_FOR_LENGTH_BYTE_2 = 2
    WAITING_FOR_PAYLOAD = 3

class AirProtoDecoder:
    def __init__(self):
        self.decoding_buffer = []
        self.state = AirProtoDecoderState.WAITING_FOR_MAGIC_BYTE
        self.magic_byte = 0xAA
        self.payload_length = 0
        self.expected_payload_length = 0

    def insert_bytes(self, bytes_to_decode):
        # print(f"Inserting.. {len(bytes_to_decode)}")
        self.decoding_buffer.extend(bytes_to_decode)
        return self._process_bytes()

    def _process_bytes(self):
        while self.decoding_buffer:
            if self.state == AirProtoDecoderState.WAITING_FOR_MAGIC_BYTE:
                if self.decoding_buffer[0] == self.magic_byte:
                    self.state = AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_1
                    self.decoding_buffer.pop(0)
                else:
                    self.decoding_buffer.pop(0)
            elif self.state == AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_1:
                self.payload_length = self.decoding_buffer.pop(0)
                self.state = AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_2
            elif self.state == AirProtoDecoderState.WAITING_FOR_LENGTH_BYTE_2:
                self.payload_length |= self.decoding_buffer.pop(0) << 8
                # self.expected_payload_length = self.payload_length - 3
                self.expected_payload_length = self.payload_length
                self.state = AirProtoDecoderState.WAITING_FOR_PAYLOAD
                # logging.info(f"Expecting a payload length of: {self.expected_payload_length}")
            elif self.state == AirProtoDecoderState.WAITING_FOR_PAYLOAD:
                if len(self.decoding_buffer) >= self.expected_payload_length:
                    payload = self.decoding_buffer[:self.expected_payload_length]
                    # print(f"Got payload len {len(payload)}")
                    del self.decoding_buffer[:self.expected_payload_length]
                    state_field_registry = StateFieldRegistry()
                    try:
                        state_field_registry.ParseFromString(bytes(payload))
                        self._reset_state()
                        return state_field_registry
                    except:
                        logging.error("Failed to parse. Dropping and resetting.")
                        self._hard_reset_state()
                        return self.state
                else:
                    break
        return self.state

    def _reset_state(self):
        self.state = AirProtoDecoderState.WAITING_FOR_MAGIC_BYTE
        self.payload_length = 0
        self.expected_payload_length = 0

    def _hard_reset_state(self):
        '''
        Call this if you get an error, we need to purge the buffer
        since it could be bad material too.

        It is not fool proof, but it may reduce the likelyhood we get stuck on the bad byte.
        '''
        self._reset_state()
        self.decoding_buffer = []
