#pragma once

#include <stdint.h>
#include <stdbool.h>

// Signal data type enum used to track
// what sort of data is being stored in each
// signal for updating and parsing
typedef enum {
    SIG_U8, SIG_U16, SIG_U32, SIG_U64,
    SIG_I8, SIG_I16, SIG_I32, SIG_I64,
    SIG_FLOAT, SIG_BOOL,
} can_signal_type;

// CAN signal metadata and data
typedef struct {
    can_signal_type signal_type;
    uint16_t start_bit;
    uint16_t bit_length;
    float factor;
    float offset;
    uint8_t* data;
} can_signal;

// CAN message metadata and signal array
typedef struct {
    uint16_t message_id;
    uint16_t number_of_bytes;
    uint16_t number_of_signals;
    can_signal* message_signals;
} can_message;

// CAN frame struct for actual rx and tx
typedef struct {
    uint16_t frame_id;
    uint8_t dlc;
    uint8_t data[8];
} can_frame_t;

// Callback function typedef to enable registering
// callback functions with messages that are passed
// the recieved CAN frame itself
typedef void (*can_rx_cb_t)(const can_frame_t *frame);

// Bus config
typedef struct {
    uint16_t bitrate;
    bool enable_can_flashing;
} can_config_t;