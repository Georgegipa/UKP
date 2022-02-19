#ifndef HID_REPORTID_CONSUMERCONTROL
#define HID_REPORTID_CONSUMERCONTROL 4
#endif

#if defined(ARDUINO_ARCH_AVR)
// Use default alignment for AVR
#define ATTRIBUTE_PACKED
#include "PluggableUSB.h"
#define EPTYPE_DESCRIPTOR_SIZE      uint8_t
#endif