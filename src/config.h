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
 * 
 * @param DEBOUNCEDELAY Time to prevent button from been set again to true
 */
#define DEBOUNCEDELAY 150 
/**
 * @brief Define the buttons and define their pin numbers.
 * 
 * @param PROFILE_BUTTON set the pin for the button that changes profiles(should not be included in BUTTON_PINS)
 * set this to -1 disables profiles
 * 
 * @param BUTTON_PINS set the pins seperated with ',' which are going to be assigned as buttons.
 * 
 * @param BUTTONS Define the number buttons that are going to be created. 
 * Number of BUTTON_PINS+1 if PROFILE_BUTTON isn't set to -1, else the number should be the number of BUTTON_PINS.
 */

#define BUTTON_PINS A1, 7
#define PROFILE_BUTTON A0
#define BUTTONS 3

/**
 * @brief Define the number of joysticks and their pins 
 * 
 */
#define JOYSTICKS 1
#define JOYSTICK_PINS A2,A3

/**
 * @brief The following settings enable/disable Components
 */
#define SWITCH 8  //set this to 0 to disable switch disabler
#define BUILTIN_LEDS_ENABLED 0 // enable/disable builtin leds of the board
#define SEVEN_SEGMENT 0 // enable/disable 7 segment display
#define SD_ENABLED 0 //enable/disable micro_sd (macros are loaded from default_profiles.h)
#define LED 9 //define the led pin number (set this to 0 to use builtin led)