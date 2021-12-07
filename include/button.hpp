#pragma once
#include <Arduino.h>
#include "debouncer.hpp"
#define MODE RISING

class button
{
private:
    debouncer debounce;
    int button_pin;
    bool using_interrupts=0;
    int id;
public:
    static int numofbuttons;
    button(int pin);
    void addInterrupt(void (*function)());
    bool state();
    ~button();
};