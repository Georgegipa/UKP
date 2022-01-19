#include <Arduino.h>
#include "macros.h"
#define MACRO const char PROGMEM

MACRO macro_0[] = "CTRL+C";
MACRO macro_1[] = "CTRL+V";
MACRO macro_2[] = "CTRL+Z";
MACRO macro_3[] = "CTRL+Y";
MACRO macro_4[] = "ALT+SHIFT+A";
MACRO macro_5[] = "CTRL+SHIFT+P";
MACRO macro_6[] = "W,calc";
MACRO macro_7[] = "W,notepad";

const char *const defaultMacros[] PROGMEM = {
    macro_0,
    macro_1,
    macro_2,
    macro_3,
    macro_4,
    macro_5,
    macro_6,
    macro_7};

//this variable saves the size of the array in order to calculate default_profiles_num in macrosengine
const int dp_num = ARR_SIZE(defaultMacros);