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