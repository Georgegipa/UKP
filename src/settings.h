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

//define macros

#define ARR_SIZE(X) sizeof(X)/sizeof(X[0])
#define IF_TRUE(X) X ? 1 : 0
#define MACRO const char PROGMEM
#define MACRO_ARRAY const char *const PROGMEM
#define MACRO_INT const int PROGMEM
#define PROGMEM_INT const int PROGMEM