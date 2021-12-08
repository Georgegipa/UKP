#pragma once
#include <Arduino.h>
#define MODE RISING

class button
{
private:
    int button_pin;
    bool using_interrupts = 0;
    int id;
    enum click
    {
        no_click,
        single_click,
        double_click,
        long_click,
        longer_click
    };
#if DEBUG_OPTIONS_ENABLED
    int times_pressed = 0;
#endif
    void print_state(int st);
    bool internal_debounce(unsigned long debouncedelay=DEBOUNCEDELAY);
    unsigned long last_trigger=0;
public:
    static int numofbuttons;
    button(int pin);
    ~button();
    void addInterrupt(void (*function)());
    int advnaced_state();
    bool state();
};