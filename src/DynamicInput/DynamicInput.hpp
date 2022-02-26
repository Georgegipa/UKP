#pragma once
#include <Arduino.h>
#include "button/button.hpp"
#include "joystick/joystick.hpp"
#include "Inputs.h"

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