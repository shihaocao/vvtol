#include "air_proto.hpp"

#include <iostream>

int AirProto::serialize_to_buffer(const StateFieldRegistry &proto)
{
    // Insert the MAGIC byte into buffer_ first
    buffer_[0] = MAGIC_BYTE;

    // Reserve two bytes for the length
    uint16_t *length_ptr = reinterpret_cast<uint16_t *>(&buffer_[1]);
    *length_ptr = 0;

    // Get the size of the serialized message
    size_t proto_size = proto.ByteSizeLong();
    std::cout << "proto size: " << proto_size << std::endl;

    // Check if the serialized message fits in the remaining buffer space
    if (proto_size > MAX_BUFFER_LEN - 3)
    {
        // Error: Serialized message size exceeds available buffer space
        return -1;
    }

    // Serialize the proto bytes after the MAGIC byte and length bytes
    proto.SerializeToArray(&buffer_[3], proto_size);

    // Update the payload length
    payload_len_ = proto_size;

    // Write the payload length to the reserved length bytes
    *length_ptr = payload_len_;
    return payload_len_;
}

const uint8_t *AirProto::data() const
{
    return buffer_.data();
}

uint16_t AirProto::size() const
{
    return payload_len_;
}