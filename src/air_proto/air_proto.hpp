#pragma once

#include <cstdint>
#include <array>
#include <google/protobuf/message.h>
#include "include/protos/state_field_registry.pb.h"

constexpr uint16_t MAX_BUFFER_LEN = 1024;
constexpr uint8_t MAGIC_BYTE = 0xAA;

class AirProto
{
    std::array<uint8_t, MAX_BUFFER_LEN> buffer_{};
    uint16_t payload_len_ = 0;

public:
    int serialize_to_buffer(const StateFieldRegistry &sfr);
    const uint8_t *data() const;
    uint16_t size() const;
};