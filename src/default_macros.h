#include "settings.h"

MACRO macro_0[] = "CTRL+C";
MACRO macro_1[] = "CTRL+V";
MACRO macro_2[] = "CTRL+Z";
MACRO macro_3[] = "CTRL+Y";
MACRO macro_4[] = "VOL_U";
MACRO macro_5[] = "VOL_D";
MACRO macro_6[] = "R,calc";
MACRO macro_7[] = "R,notepad";

MACRO_ARRAY defaultMacros[] = {
    macro_0,
    macro_1,
    macro_2,
    macro_3,
    macro_4,
    macro_5,
    macro_6,
    macro_7};

//this variable saves the size of the array in order to calculate default_profiles_num in macrosengine
PROGMEM_INT dp_num = ARR_SIZE(defaultMacros);