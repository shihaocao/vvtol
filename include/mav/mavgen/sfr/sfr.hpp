/** @file
 *	@brief MAVLink comm protocol generated from sfr.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <array>
#include <cstdint>
#include <sstream>

#ifndef MAVLINK_STX
#define MAVLINK_STX 253
#endif

#include "../message.hpp"

namespace mavlink {
namespace sfr {

/**
 * Array of msg_entry needed for @p mavlink_parse_char() (through @p mavlink_get_msg_entry())
 */
constexpr std::array<mavlink_msg_entry_t, 1> MESSAGE_ENTRIES {{ {110, 22, 96, 96, 0, 0, 0} }};

//! MAVLINK VERSION
constexpr auto MAVLINK_VERSION = 2;


// ENUM DEFINITIONS




} // namespace sfr
} // namespace mavlink

// MESSAGE DEFINITIONS
#include "./mavlink_msg_state_field_registry.hpp"

// base include

