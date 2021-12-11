#include "options.hpp"
//the first defined button is used for profile switching
//
const int button_pins[] PROGMEM = {15, 14, 16};

//default profiles 
//1st dimension is profile id and, 2nd dimensio is button_id
char profiles[][BUTTONS-1][MACRO_MAX_SIZE] = {
    {"LEFT_CTRL+V",
     "LEFT_CTRL+C"},
    {"LEFT_CTRL+Z",
     "LEFT_CTRL+Y"}};
const int num_of_profiles=ARR_SIZE(profiles);