#pragma once

#include "main.h"

// Some STM32 have FDCAN and some have standard CAN
// select which HAL to build with here based on cubemx output
#if defined(HAL_FDCAN_MODULE_ENABLED)
  #define CAN_BACKEND_FDCAN
#elif defined(HAL_CAN_MODULE_ENABLED)
  #define CAN_BACKEND_BXCAN
#endif

#define CAN_DEFAULT_BITRATE 500000

