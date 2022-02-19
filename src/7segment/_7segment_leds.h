#include <Arduino.h>
#include "settings.h"
#if SEVEN_SEGMENT
#define SEGMENT_LEDS 8
const int leds[SEGMENT_LEDS] PROGMEM = {2, 3, 4, 5, 6, 7, 8, 9};
#endif