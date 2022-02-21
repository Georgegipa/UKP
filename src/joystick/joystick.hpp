#pragma once
#include "settings.h"
#if JOYSTICKS
#include <Arduino.h>

const int joystickPins[JOYSTICKS * 2] PROGMEM = {JOYSTICK_PINS};
class joystick
{
private:
    int pinX, pinY;
    int valX, valY;

public:
    joystick();
    int state();
    static int joysticks;
};
#endif