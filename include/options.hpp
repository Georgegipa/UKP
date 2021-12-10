#pragma once
#define BUTTONS 3
#define ARR_SIZE(X) (int)sizeof(X)/sizeof(X[0]);
extern const int button_pins[BUTTONS] ; //= {15,14,16};

//if micro_sd module is disabled the following macros are enabled
#if MICRO_SD_ENABLED==0
extern char profiles[][BUTTONS][MACRO_MAX_SIZE];
extern int num_of_profiles;
#endif