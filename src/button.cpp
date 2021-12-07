#include "button.hpp"

int button::numofbuttons = 0;

button::button(int pin)
{
    button_pin = pin;
    numofbuttons++;
    id = numofbuttons;
    pinMode(pin, INPUT);
}

void button::addInterrupt(void (*function)())
{
    attachInterrupt(digitalPinToInterrupt(button_pin), function, MODE);
}

bool button::state()
{
    //if button is pressed and debounce time has passed then state is true
    if (digitalRead(button_pin) && debounce.debounce())
    {
#if DEBUG_OPTIONS_ENABLED
        Serial.print("Button_");
        Serial.print(id);
        Serial.println(" pressed!");
#endif
        return digitalRead(button_pin);
    }
}

button::~button()
{
    if (using_interrupts)
        detachInterrupt(button_pin);
}