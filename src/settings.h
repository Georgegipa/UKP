#include "config.h"

#if !LED
#ifdef LED_BUILTIN
#define LED_PIN LED_BUILTIN
#endif
#else 
#define LED_PIN LED
#endif