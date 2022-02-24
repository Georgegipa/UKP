#include "config.h"

#if !LED
#ifdef LED_BUILTIN
#define LED_PIN LED_BUILTIN
#endif
#else
#define LED_PIN LED
#endif

#ifdef HID_ENABLED
#define KILL_SWITCH SWITCH
#if PROFILES_ENABLED
#define PROFILES 1
#else
#define PROFILES 0
#endif
#endif

//check if the sum of inputs is 0
//prevent from compiling a build that does nothing

#if BUTTONS+JOYSTICKS == 0
#error Defined not inputs, build canceled
#endif

//define macros

#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])
#define IF_TRUE(X) X ? 1 : 0
#define RETRIEVE_PROFILE(POS) (char *)pgm_read_word(&(defaultMacros[POS]))
#define MACRO const char PROGMEM
#define MACRO_ARRAY const char *const PROGMEM
#define PROGMEM_INT const int PROGMEM