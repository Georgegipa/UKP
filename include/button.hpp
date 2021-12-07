#pragma once
#include <Arduino.h>
#define MODE RISING

class button
{
private:
    int button_pin;
    bool using_interrupts=0;
    int id;
    unsigned long lastpress=0;
public:
    static int numofbuttons;
    button(int pin);
    void addInterrupt(void (*function)());
    bool state();
    ~button();
};