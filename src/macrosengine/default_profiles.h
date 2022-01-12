#include <Arduino.h>
#include "macros.h"

const char macro_0[] PROGMEM = "CTRL+C";
const char macro_1[] PROGMEM = "CTRL+V";
const char macro_2[] PROGMEM = "CTRL+Z";
const char macro_3[] PROGMEM = "CTRL+Y";
const char macro_4[] PROGMEM = "ALT+SHIFT+A";
const char macro_5[] PROGMEM = "CTRL+SHIFT+P";
const char macro_6[] PROGMEM = "W,calc";
const char macro_7[] PROGMEM = "W,msedge";

const char *const defaultProfiles[] PROGMEM = {
    macro_0,
    macro_1,
    macro_2,
    macro_3,
    macro_4,
    macro_5,
    macro_6,
    macro_7};

//this variable saves the size of the array in order to calculate default_profiles_num in macrosengine
const int dp_num = ARR_SIZE(defaultProfiles);