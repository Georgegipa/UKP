#pragma once
#include "settings.h"
#if BUTTON_SUM
PROGMEM_INT buttonPins[BUTTON_SUM] = {BTNS};

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