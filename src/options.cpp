#include "options.hpp"
#include "macros.h"
/*Define the pins for each of the number BUTTONS declared in options.hpp
(Note that the first number button pin is used for profile switching 
(unless PROFILE is set to 0)) */
const int button_pins[BUTTONS] PROGMEM = {A0, A1, A2};

/**default profiles
* edit the following lines to change the default profiles
* to avoid errors the default profiles must be at least the BUTTONS (if profiles is set to 0) and or alternatively BUTTONS-1**/
char profiles[][MACRO_MAX_SIZE+MACRO_COMMAND_SIZE] = {
    "CTRL+C", //copy & paste profile
    "CTRL+V",
    "CTRL+Z", //undo & redo profile
    "CTRL+Y",
    "ALT+SHIFT+A", //comment & open command palette profile
    "CTRL+SHIFT+P",
    "W,calc", //open windows programs
    "W,msedge"
};
//GLOBAL VARIABLES DO NOT CHANGE
int num_of_profiles = (PROFILES ? (ARR_SIZE(profiles) / (BUTTONS - 1)) : 1);
int current_profile = 0;