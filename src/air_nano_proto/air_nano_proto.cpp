// #ifndef TEENSY
// #include "src/air_nano_proto/air_nano_proto.hpp"
// #else
#include "air_nano_proto/air_nano_proto.hpp"
// #endif

#include "pb_encode.h"
#include "pb_common.h"

int AirProto::serialize_to_buffer(const StateFieldRegistry &proto)
{
    // Insert the MAGIC byte into buffer_ first
    buffer_[0] = MAGIC_BYTE;

    // Reserve two bytes for the length
    uint16_t *length_ptr = reinterpret_cast<uint16_t *>(&buffer_[1]);
    *length_ptr = 0;

    // Create a stream that will write to our buffer
    pb_ostream_t stream = pb_ostream_from_buffer(&buffer_[3], MAX_BUFFER_LEN - 3);

    // Serialize the proto bytes after the MAGIC byte and length bytes
    bool status = pb_encode(&stream, StateFieldRegistry_fields, &proto);
    size_t proto_size = stream.bytes_written;

    if (!status)
    {
        // std::cout << "Encoding failed: " << PB_GET_ERROR(&stream) << std::endl;
        return -1;
    }

    // std::cout << "proto size: " << proto_size << std::endl;

    // Check if the serialized message fits in the remaining buffer space
    if (proto_size > MAX_BUFFER_LEN - 3)
    {
        // Error: Serialized message size exceeds available buffer space
        return -1;
    }

    // Update the payload length
    payload_len_ = static_cast<uint16_t>(proto_size);

    // Write the payload length to the reserved length bytes
    *length_ptr = payload_len_;

    return payload_len_;
}

const uint8_t *AirProto::data() const
{
    return buffer_;
}

uint16_t AirProto::size() const
{
    return payload_len_ + 3; // Include the magic byte and length in the total size
}
