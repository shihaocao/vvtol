#pragma once

#include <state_field_registry.pb.h> // Adjust the include path to match your nanopb generated file

#include <iostream>
#include <cstdint>

class AirProto
{
public:
    int serialize_to_buffer(const StateFieldRegistry &proto);
    const uint8_t *data() const;
    uint16_t size() const;

private:
    static const uint8_t MAGIC_BYTE = 0xAA;    // Example magic byte, adjust as needed
    static const size_t MAX_BUFFER_LEN = 1024; // Adjust buffer size as needed
    uint8_t buffer_[MAX_BUFFER_LEN] = {0};
    uint16_t payload_len_ = 0;
};
