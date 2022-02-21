#include "joystick.hpp"
#include "helpers.h"
#define REMAP_VAL 10
int joystick::joysticks = 0;

joystick::joystick()
{
    pinX = intfromPROGMEM(joystickPins, joysticks * 2);
    pinY = intfromPROGMEM(joystickPins, joysticks * 2 + 1);
    Serial.println("pinX:" + pinX);
    Serial.println("pinY:" + pinY);
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
    joysticks++;
}

// TODO: add debounce
// TODO: remap values
int joystick::state()
{
    valX = map(analogRead(pinX), 0, 1023, -REMAP_VAL, REMAP_VAL);
    valY = map(analogRead(pinY), 0, 1023, REMAP_VAL, -REMAP_VAL);
    /*
    How remap works
            1
            |Y
            |
    <-------+------->X
    -1      |       1
            |
            |
           -1

    1 2 3
    4 0 5
    6 7 8

    pos  X   Y
     0   0   0
    ----------
     1  -1   1
     2   0   1
     3   1   1
     4  -1   0
     5   1   0
     6  -1  -1
     7   0  -1
     8   1  -1
    */

#if DEBUG
    Serial.print("(");
    Serial.print(valX);
    Serial.print(",");
    Serial.print(valY);
    Serial.println(")");
#endif

    switch (valY)
    {
    case REMAP_VAL: // 1
        switch (valX)
        {
        case -REMAP_VAL:
            return 1;
        default:
            return 2;
        case REMAP_VAL:
            return 3;
        }
    default: // 0
        switch (valX)
        {
        case -REMAP_VAL:
            return 4;
        default:
            return 0;
        case REMAP_VAL:
            return 5;
        }
    case -REMAP_VAL: // -1
        switch (valX)
        {
        case -REMAP_VAL:
            return 6;
        default:
            return 7;
        case REMAP_VAL:
            return 8;
        }
        break;
    }

    return 0;
}