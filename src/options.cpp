#include "options.hpp"
const int button_pins[] PROGMEM = {15, 14, 16};

//default profiles
const char profiles[][BUTTONS][MACRO_MAX_SIZE] PROGMEM = {
    {"KEY_LEFT_CTRL+V",
     "KEY_LEFT_CTRL+C",
     "KEY_LEFT_CTRL+X"},
    {"KEY_LEFT_CTRL+Z",
     "KEY_LEFT_CTRL+Y",
     "KEY_LEFT_ALT+KEY_TAB"}};
const int num_of_profiles=ARR_SIZE(profiles);