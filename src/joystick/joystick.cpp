#include "joystick.hpp"
#if JOYSTICKS
#include <math.h>
#define REMAP_VAL 10
#define OFFSET 2

#define POSITIVE_VAL REMAP_VAL - OFFSET
#define NEGATIVE_VAL -REMAP_VAL + OFFSET

int joystick::joysticks = 0;

joystick::joystick()
{
    pinX = intfromPROGMEM(joystickPins, joysticks * 2);
    pinY = intfromPROGMEM(joystickPins, joysticks * 2 + 1);
    SSprintf("pinX:%d\n",pinX);
    SSprintf("pinY:%d\n",pinY);
    pinMode(pinX, INPUT);
    pinMode(pinY, INPUT);
    joysticks++;
}

int joystick::remapXY(int x, int y)
{
    /*Remapping documentation
            1
            |Y
            |
    <-------+------->X
    -1      |       1
            |
            |
           -1

    Axis remaping

    4 3 2
    5 0 1
    6 7 8

    +---------------+ Outside area =
    |   +-------+   |
    |   | Inner |   |
    |   | area  |   |
    |   |       |   |
    |   +-------+   |
    +---------------+
    -x              x
    Outside area is the area where the joystick is near the edges.

    Convert the passed x and y to 1 0 or -1 based on position
    X and Y is 0 where inside their value is inside inner square
    else 1 and -1 correspond to cartesian coordinates
    */
    if (x >= POSITIVE_VAL) // 1
        x = 1;
    else if (x <= NEGATIVE_VAL) //-1
        x = -1;
    else
        x = 0;

    if (y >= POSITIVE_VAL) // 1
        y = 1;
    else if (y <= NEGATIVE_VAL) // -1
        y = -1;
    else
        y = 0;

    if (y == 0 && x == 0)
        return 0;
    else if (y == 0 && x == 1)
        return 1;

    // calculate the angle
    int val = atan2(y, x) * 180.0 / PI;

    // convert the given angle to a number
    switch (val)
    {
    case 45:
        return 2;
    case 90:
        return 3;
    case 135:
        return 4;
    case 180:
        return 5;
    case -135:
        return 6;
    case -90:
        return 7;
    case -45:
        return 8;
    default:
        return 0;
    }
}

// TODO: add debounce
int joystick::state()
{
    valX = map(analogRead(pinX), 0, 1023, -REMAP_VAL, REMAP_VAL);
    valY = map(analogRead(pinY), 0, 1023, REMAP_VAL, -REMAP_VAL);
    return remapXY(valX, valY);
}

#endif