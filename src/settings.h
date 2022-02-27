#include "config.h"

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

//enable the companion app control to UKP
#if COMPANION_APP
#define APP_CONTROL
#endif

//Check if profile button is the defined
#if PROFILE_BUTTON!=-1
#define ENABLE_PROFILES
#endif

#ifdef HID_ENABLED
#define KILL_SWITCH SWITCH
#ifdef ENABLE_PROFILES
#define PROFILES 1
#else
#define PROFILES 0
#endif
#endif

//If profiles are enabled then append profile button, 
//and increase the number of total buttons
#if PROFILES
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
#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])
#define RETRIEVE_PROFILE(ARR,POS) (char *)pgm_read_word(ARR+POS)
#define MACRO const char PROGMEM
#define MACRO_ARRAY const char *const PROGMEM
#define PROGMEM_INT const int PROGMEM