#pragma once
#include <Arduino.h>
#include "config/button_pins.h"

#if INTERRUPTS_ENABLED
#define MODE FALLING
#endif

class button
{
private:
    int buttonPin;
    int buttonId;
#if DEBUG
    int timesPressed = 0;
    void printState();
#endif
    bool internalDebounce(unsigned long debouncedelay = DEBOUNCEDELAY);
    unsigned long lastTrigger = 0;

public:
    static int buttonSum;
    button();
    int state();

#if INTERRUPTS_ENABLED
    ~button();
    void addInterrupt(void (*function)());//= foo() , if args void (*function)(int , int ) = foo
#endif
};