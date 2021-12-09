#include "button.hpp"
#include "actions.hpp"
#include "Keyboard.h"
int button::numofbuttons = 0;

button::button(int pin)
{
    button_pin = pin;
    numofbuttons++;
    id = numofbuttons;
    pinMode(pin, INPUT);
    if (numofbuttons == 1)
        InitActions();
}

button::~button()
{
    if (using_interrupts)
        detachInterrupt(button_pin);
}

bool button::internal_debounce(unsigned long debouncedelay)
{

    if ((millis() - last_trigger) > debouncedelay)
    {
        last_trigger = millis();
        return 1;
    }
    return 0;
}

void button::addInterrupt(void (*function)())
{
    attachInterrupt(digitalPinToInterrupt(button_pin), function, MODE);
}

bool button::state()
{
    //if button is pressed and debounce time has passed then state is 1
    if (digitalRead(button_pin) && internal_debounce())
    {
        print_state(1);
        //KeyboardMacro(2,KEY_LEFT_CTRL, 118);
        MacroParser((char*)"KEY_LEFT_CTRL+v");
        return digitalRead(button_pin);
    }
    else
        return 0;
}

#if DEBUG_OPTIONS_ENABLED
void button::print_state(int st)
{
    if (st)
    {
        times_pressed++;
        Serial.print("Button_");
        Serial.print(id);
        Serial.print(" registered: ");
        switch (st)
        {
        case single_click:
            Serial.print(" single click");
            break;
        }
        Serial.print(" (x");
        Serial.print(times_pressed);
        Serial.println(")");
    }
}
#elif
void button::print_state(int st)
{
}
#endif