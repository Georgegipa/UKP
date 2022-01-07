#pragma once
#include <Arduino.h>

class binary_output
{
private:
    int ledPin;
    int stateLow = 0;
    int stateHigh = 1;
    unsigned long lastTrigger;
public:
    void begin(int pin , bool reversed = 0,int initialState=0);
    void setHigh();
    void setLow();
    void flashing(int times,int ms = 80,double offset=0.25);
};