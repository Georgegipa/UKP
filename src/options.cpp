#include "options.hpp"
#include "macros.h"

/*Define the pins for each of the number BUTTONS declared in options.hpp
(Note that the first number button pin is used for profile switching) */
const int button_pins[BUTTONS] PROGMEM = {15, 14, 16};

//default profiles
//1st dimension is profile id and, 2nd dimension is button_id
char profiles[][BUTTONS - 1][MACRO_MAX_SIZE] = {
    {"LEFT_CTRL+V", //copy & paste profile
     "LEFT_CTRL+C"},
    {"LEFT_CTRL+Z", //undo & redo profile
     "LEFT_CTRL+Y"},
    {"LEFT_ALT+LEFT_SHIFT+A", //comment & open command palette profile
     "LEFT_CTRL+LEFT_SHIFT+P"}};

//GLOBAL VARIABLES DO NOT CHANGE
const int num_of_profiles PROGMEM = ARR_SIZE(profiles);
int current_profile = 0;