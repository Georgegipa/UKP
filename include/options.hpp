#pragma once
#include <Arduino.h>
#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])
#define BUTTONS 3

extern const int button_pins[BUTTONS] PROGMEM;
//default profiles
extern char profiles[][BUTTONS][MACRO_MAX_SIZE];
extern const int num_of_profiles;