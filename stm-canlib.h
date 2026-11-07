#pragma once

#include "stm-canlib-types.h"
#include "stm-canlib-config.h"
#include <stdint.h>

// Message construction
// Create a message for transmission
can_message *can_create_tx_message(uint16_t message_id,
                                   uint16_t number_of_signals,
                                   can_signal *signal_array);
// Create a message for reception
can_message *can_create_rx_message(uint16_t message_id);

uint16_t can_send_message(can_message message);
uint16_t can_register_message_callback(uint16_t message_id,
                                       can_rx_cb_t callback);

// Signal construction
can_signal *can_create_signal(can_signal_type signal_type, uint16_t start_bit,
                              uint16_t bit_length, float factor, float offset);

uint16_t can_update_signal(can_signal signal, void *data);
uint16_t can_parse_signal(can_signal signal, void *data);

// Flashing functions

uint16_t can_register_flashing();
uint16_t can_unregister_flashing();