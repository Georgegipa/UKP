#pragma once
#include <Arduino.h>
#include "options.hpp"

#if INTERRUPTS_ENABLED
#define MODE FALLING
#endif

class button
{
private:
    int button_pin;
    int button_id;
#if DEBUG
    int times_pressed = 0;
    void print_state(int st);
#endif
    bool internal_debounce(unsigned long debouncedelay = DEBOUNCEDELAY);
    unsigned long last_trigger = 0;

public:
    static int numofbuttons;
    button();
    int state();

#if INTERRUPTS_ENABLED
    ~button();
    void addInterrupt(void (*function)());//= foo() , if args void (*function)(int , int ) = foo
#endif
};