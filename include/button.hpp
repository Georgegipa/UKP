#pragma once
#include <Arduino.h>
#define MODE RISING

class button
{
private:
    int button_pin;
    bool using_interrupts = 0;
    int id;
#if DEBUG_OPTIONS_ENABLED
    int times_pressed = 0;
#endif
    void print_state(int st);
    bool internal_debounce(unsigned long debouncedelay = DEBOUNCEDELAY);
    unsigned long last_trigger = 0;

public:
    static int numofbuttons;
    button(int pin);
    ~button();
    void addInterrupt(void (*function)());
    bool state();
};