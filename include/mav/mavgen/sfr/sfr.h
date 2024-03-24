/** @file
 *  @brief MAVLink comm protocol generated from sfr.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_SFR_H
#define MAVLINK_SFR_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_SFR.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#define MAVLINK_SFR_XML_HASH 4978823413554147177

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{110, 22, 96, 96, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_SFR

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_state_field_registry.h"

// base include



#if MAVLINK_SFR_XML_HASH == MAVLINK_PRIMARY_XML_HASH
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_STATE_FIELD_REGISTRY}
# define MAVLINK_MESSAGE_NAMES {{ "STATE_FIELD_REGISTRY", 110 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_SFR_H
