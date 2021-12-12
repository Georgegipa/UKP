#pragma once
#include <Arduino.h>

#define DEBOUNCEDELAY 150 //time in ms for debounser to reenable button
#define MACRO_MAX_SIZE 50 //max number of chars allowed for profile
/* Define the number buttons that are going to be created
(Note that the actual number of buttons is BUTTONS-1 as the 1st button is used for button swicthing)
(unless PROFILE is set to 0)) */
#define BUTTONS 3
#define PROFILES 1 //set this to 0 to disable profiles and use the first button as a normal macro
//Button_pins and profiles are configured in options.cpp!

//DO NOT CHANGE
extern const int button_pins[BUTTONS] PROGMEM;
#if PROFILES
extern char profiles[][BUTTONS - 1][MACRO_MAX_SIZE];
#else
extern char profiles[1][BUTTONS][MACRO_MAX_SIZE];
#endif

//GLOBAL VARIABLES DO NOT CHANGE
extern int num_of_profiles;
extern int current_profile;