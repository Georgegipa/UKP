#pragma once
#include <Arduino.h>
#include "button/button.hpp"
#include "joystick/joystick.hpp"

enum InputType
{
    type_none,
    type_button,
    type_keypad,
    type_encoder,
    type_joystick
};

// keypad -> 0...N(int)
// button -> 0...N(int)
// encoder -> +(1) or -(0) (bool)
/*joystic position
1   2   3
4  -1   5
6   7   8
*/
struct InputData
{
    InputType type;//type of input
    int id;//id of triggered input if multiple exist(example. 1st btn -> 0 , 2nd btn -> 1 ...)
    int state = 0; // last known state of triggered input
};

class DynamicInput
{
private:
    InputData d;
#if BUTTONS
    button btn[BUTTONS];
#endif
#if JOYSTICKS
    joystick jstck[JOYSTICKS];
#endif

public:
    InputData inputPolling();
};

extern DynamicInput Input;