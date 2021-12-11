#include "options.hpp"
//the first defined button is used for profile switching
//
const int button_pins[] PROGMEM = {15, 14, 16};

//default profiles 
//1st dimension is profile id and, 2nd dimensio is button_id
char profiles[][BUTTONS-1][MACRO_MAX_SIZE] = {
    {"LEFT_CTRL+V",//copy & paste profile
     "LEFT_CTRL+C"},
    {"LEFT_CTRL+Z",//undo & redo profile
     "LEFT_CTRL+Y"},
     {"LEFT_ALT+LEFT_SHIFT+A",//comment & open command palette profile
     "LEFT_CTRL+LEFT_SHIFT+P"}};
const int num_of_profiles=ARR_SIZE(profiles);