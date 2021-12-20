#include "options.hpp"
#include "macros.h"
/*Define the pins for each of the number BUTTONS declared in options.hpp
(Note that the first number button pin is used for profile switching 
(unless PROFILE is set to 0)) */
const int button_pins[BUTTONS] PROGMEM = {15, 14, 16};

/**default profiles
* edit the following lines to change the default profiles
* to avoid errors the default profiles must be at least the BUTTONS (if profiles is set to 0) and or alternatively BUTTONS-1**/
char profiles[][MACRO_MAX_SIZE] = {
    "LEFT_CTRL+V", //copy & paste profile
    "LEFT_CTRL+C",
    "LEFT_CTRL+Z", //undo & redo profile
    "LEFT_CTRL+Y",
    "LEFT_ALT+LEFT_SHIFT+A", //comment & open command palette profile
    "LEFT_CTRL+LEFT_SHIFT+P"
};
//GLOBAL VARIABLES DO NOT CHANGE
int num_of_profiles = (PROFILES ? (ARR_SIZE(profiles) / (BUTTONS - 1)) : 1);
int current_profile = 0;