/**
 * @file config.h
 * @author Georgegipa
 * @brief This file contains all the options for the current project
 * @version 0.7.0
 */

/**
 * @brief Macro settings 
 */
#define MACRO_MAX_SIZE 50 //max number of chars allowed for a macro

/**
 * @brief The following settings change behavior of inputs
 */
#define DEBOUNCEDELAY 150 //time to prevent button from been set again to true
/**
 * @brief Define the number buttons that are going to be created
 * (Note that the actual number of buttons is BUTTONS-1 as the 1st button is used for button switching)
 * (unless PROFILE is set to 0)
 */
#define BUTTONS 3

/**
 * @brief The following settings enable/disable Components
 */
#define KILL_SWITCH 8  //set this to 0 to disable switch disabler
#define PROFILES 1 //set this to 0 to disable profiles and use the first button as a normal macro
#define BUILTIN_LEDS_ENABLED 0 // enable/disable builtin leds of the board
#define SEVEN_SEGMENT 0 // enable/disable 7 segment display
#define SD_ENABLED 0 //enable/disable micro_sd (macros are loaded from default_profiles.h)
#define LED 9 //define the led pin number (set this to 0 to use builtin led)