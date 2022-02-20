#include "DynamicInput.hpp"

DynamicInput Input;
InputData DynamicInput::inputPolling()
{
#if BUTTONS
    for (int i = 0; i < BUTTONS; i++)
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
    d.type = type_none;
    return d;
}