#pragma once
#include <Arduino.h>

#define DEBOUNCEDELAY 150 //time in ms for debounser to reenable button
#define MACRO_MAX_SIZE 50 //max number of chars allowed for profile
/* Define the number buttons that are going to be created
(Note that the actual number of buttons is BUTTONS-1 as the 1st button is used for button swicthing) */
#define BUTTONS 3

//Button_pins and profiles are configured in options.cpp!

extern const int button_pins[BUTTONS] PROGMEM;
extern char profiles[][BUTTONS - 1][MACRO_MAX_SIZE];

//GLOBAL VARIABLES DO NOT CHANGE
extern const int num_of_profiles PROGMEM;
extern int current_profile;