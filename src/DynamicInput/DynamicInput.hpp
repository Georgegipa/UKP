#pragma once
#include "button/button.hpp"
#include "joystick/joystick.hpp"
#include "Inputs.h"

class DynamicInput
{
private:
    InputData d;
#if BUTTON_SUM
    button btn[BUTTON_SUM];
#endif
#if JOYSTICKS
    joystick jstck[JOYSTICKS];
#endif

public:
    InputData inputPolling();
};

extern DynamicInput Input;