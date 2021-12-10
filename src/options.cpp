#include "options.hpp"
const int button_pins[] PROGMEM = {15, 14, 16};

//default profiles 
//1st dimension is profile id and, 2nd dimensio is button_id
char profiles[][BUTTONS][MACRO_MAX_SIZE] = {
    {"KEY_LEFT_CTRL+V",
     "KEY_LEFT_CTRL+C",
     "KEY_LEFT_CTRL+X"},
    {"KEY_LEFT_CTRL+Z",
     "KEY_LEFT_CTRL+Y",
     "KEY_LEFT_ALT+KEY_TAB"}};
const int num_of_profiles=ARR_SIZE(profiles);