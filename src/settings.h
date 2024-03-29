#include "config.h"
#include "helpers/helpers.h"

#if !LED
#ifdef LED_BUILTIN
#define LED_PIN LED_BUILTIN
#endif
#else
#define LED_PIN LED
#endif

#ifdef UKP
#define HID_ENABLED 1
#endif

//TODO: support for companion app
//enable the companion app control to UKP
#if COMPANION_APP
#define APP_CONTROL
#endif

#ifdef HID_ENABLED//HID board definitions
#define KILL_SWITCH SWITCH
#if PROFILE_BUTTON!=-1
#define PROFILES 1
#else
#define PROFILES 0
#endif
#else //Non HID boards
#undef PROFILE_BUTTON
#undef SD_ENABLED
#endif

//If profiles are enabled then append profile button, 
//and increase the number of total buttons
#if PROFILE_BUTTON>=0 && HID_ENABLED
#define BTNS PROFILE_BUTTON,BUTTON_PINS
#define BUTTON_SUM BUTTONS+1
#else
#define BUTTON_SUM BUTTONS
#define BTNS BUTTON_PINS
#endif

//check if the sum of inputs is 0
//prevent from compiling a build that does nothing

#if BUTTON_SUM+JOYSTICKS == 0
#error Defined not inputs, build canceled
#endif

//define macros
#define FLASH_PROFILES (PROFILES ? (dp_num / (BUTTON_SUM - 1)) : 1) //set the number of profiles when reading macros from flash
#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])
#define RETRIEVE_PROFILE(ARR,POS) (char *)pgm_read_word(ARR+POS)
#define MACRO const char PROGMEM
#define MACRO_ARRAY const char *const PROGMEM
#define PROGMEM_INT const int PROGMEM