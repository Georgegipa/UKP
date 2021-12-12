#include "options.hpp"
#include "macros.h"
/*Define the pins for each of the number BUTTONS declared in options.hpp
(Note that the first number button pin is used for profile switching 
(unless PROFILE is set to 0)) */
const int button_pins[BUTTONS] PROGMEM = {15, 14, 16};

//default profiles

#if PROFILES //if profiles are enabled(PROFILES 1)change default profiles here
//1st dimension is profile id and, 2nd dimension is button_id
char profiles[][BUTTONS - 1][MACRO_MAX_SIZE] = {
    {"LEFT_CTRL+V", //copy & paste profile
     "LEFT_CTRL+C"},
    {"LEFT_CTRL+Z", //undo & redo profile
     "LEFT_CTRL+Y"},
    {"LEFT_ALT+LEFT_SHIFT+A", //comment & open command palette profile
     "LEFT_CTRL+LEFT_SHIFT+P"}};
#else//if profiles are disabled(PROFILES 0)change default macros here
char profiles[1][BUTTONS][MACRO_MAX_SIZE] = {
    "LEFT_CTRL+V", //copy & paste profile
    "LEFT_CTRL+C",
    "LEFT_CTRL+X"};
#endif

//GLOBAL VARIABLES DO NOT CHANGE
int num_of_profiles = ARR_SIZE(profiles);
int current_profile = 0;