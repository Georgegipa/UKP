#pragma once
#include "settings.h"
#if JOYSTICKS

PROGMEM_INT joystickPins[JOYSTICKS * 2] = {JOYSTICK_PINS};
class joystick
{
private:
    int pinX, pinY;
    int valX, valY;
    int remapXY(int x, int y);
public:
    joystick();
    int state();
    static int joysticks;
};
#endif