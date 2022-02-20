#pragma once
#include "settings.h"
#if BUTTONS
#include <Arduino.h>
const int buttonPins[BUTTONS] PROGMEM = {BUTTON_PINS};

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
};
#endif