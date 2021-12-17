#pragma once
#include <Arduino.h>

class binary_output
{
private:
    int led_pin;
    int state_low = 0;
    int state_high = 1;
    unsigned long last_trigger;
public:
    void init(int pin , bool reversed = 0,int initial_state=0);
    void setHigh();
    void setLow();
    void flashing(int times,int ms = 80,double offset=0.25);
};