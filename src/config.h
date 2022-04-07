/**
 * @file config.h
 * @author Georgegipa
 * @brief This file contains all the options for the current project
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
 * @param BUTTONS Define the number BUTTON_PINS buttons that are going to be created. 
 * @param BUTTON_PINS set the pins seperated with ',' which are going to be assigned as buttons.
 * @param PROFILE_BUTTON set the pin for the button that changes profiles(should not be included in BUTTON_PINS)
 *          * Set this to -1 disable profiles.
 *          * Set this to -2 to disable profile button but keep profiles enabled.
 * 
 */

#define BUTTONS 2
#define BUTTON_PINS A1, 7
#define PROFILE_BUTTON A0

/**
 * @brief Define the number of joysticks and their pins 
 * 
 */
#define JOYSTICKS 0
#define JOYSTICK_PINS A2,A3

/**
 * @brief Display outputs
 * 7segment wiring
 *  g fCOMa b
 *  | | | | |
 *      a
 *  f       b
 *      g
 *  e       c
 *      d   .
 *  | | | | |
 *   e dCOMc .
 * @param SEVEN_SEGMENT_PINS define the 8 pins corresponding to the display pins a,b,c,d,e,f,g,.
 */
#define SEVEN_SEGMENT 0 // enable/disable 7 segment display
#define SEVEN_SEGMENT_PINS 2, 3, 4, 5, 6, 7, 8, 9 

/**
 * @brief The following settings enable/disable Components
 */
#define SWITCH 8  //set this to 0 to disable switch disabler
#define BUILTIN_LEDS_ENABLED 0 // enable/disable builtin leds of the board
#define SD_ENABLED 1 //enable/disable micro_sd (macros are loaded from default_profiles.h)
#define LED 9 //define the led pin number (set this to 0 to use builtin led)