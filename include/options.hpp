#pragma once
#include <Arduino.h>
#define BUTTONS 3
extern const int button_pins[BUTTONS] PROGMEM;
//default profiles
extern char profiles[][BUTTONS-1][MACRO_MAX_SIZE];
extern const int num_of_profiles;