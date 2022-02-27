#include "DynamicInput.hpp"

DynamicInput Input;
InputData DynamicInput::inputPolling()
{
#if BUTTON_SUM
    for (int i = 0; i < BUTTON_SUM; i++)
    {
        d.type = type_button;
        d.id = -1;
        int id = btn[i].state();
        if (id != -1)
        {
            d.id = id;
            return d;
        }
    }
#endif
#if JOYSTICKS
    for (int i = 0; i < JOYSTICKS; i++)
    {
#if DEBUG
        int state = jstck[i].state();
        if (state != 0)
        {
            Serial.print("Joystick position:");
            Serial.println(state);
        }
#endif
    }
#endif
    d.type = type_none;
    return d;
}