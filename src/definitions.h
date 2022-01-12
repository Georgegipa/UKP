#define DEBOUNCEDELAY 150 //time in ms for debounser to reenable button
#define MACRO_MAX_SIZE 50 //max number of chars allowed for profile
#define MACRO_COMMAND_SIZE 2
#define KILL_SWITCH 8  //set this to 0 to disable switch disabler
/* Define the number buttons that are going to be created
(Note that the actual number of buttons is BUTTONS-1 as the 1st button is used for button swicthing)
(unless PROFILE is set to 0)) */
#define BUTTONS 5
#define PROFILES 1 //set this to 0 to disable profiles and use the first button as a normal macro
#define BUILTIN_LEDS_ENABLED 0 // enable/disable builtin_leds
#define SEVEN_SEGMENT 0 // enable/disable 7 segment display
#define MICRO_SD_ENABLED 1 //enable/disable micro_sd (macros are loaded from default_profiles.h)
extern const int defaultProfilesSum;