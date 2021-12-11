#include "options.hpp"
const int button_pins[] PROGMEM = {15, 14, 16};

//default profiles 
//1st dimension is profile id and, 2nd dimensio is button_id
char profiles[][BUTTONS][MACRO_MAX_SIZE] = {
    {"LEFT_CTRL+V",
     "LEFT_CTRL+C",
     "LEFT_CTRL+X"},
    {"LEFT_CTRL+Z",
     "LEFT_CTRL+Y",
     "LEFT_ALT+TAB"}};
const int num_of_profiles=ARR_SIZE(profiles);