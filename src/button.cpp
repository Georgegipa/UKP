#include "button.hpp"
#include "helpers.h"

int button::numofbuttons = 0;

button::button()
{
    button_id = numofbuttons;
    button_pin = intfromPROGMEM(button_pins, numofbuttons);
    numofbuttons++;
    pinMode(button_pin, INPUT);
}
#if INTERRUPTS_ENABLED
button::~button()
{
    if (using_interrupts)
        detachInterrupt(button_pin);
}

void button::addInterrupt(void (*function)())
{
    attachInterrupt(digitalPinToInterrupt(button_pin), function, MODE);
}
#endif

bool button::internal_debounce(unsigned long debouncedelay)
{

    if ((millis() - last_trigger) > debouncedelay)
    {
        last_trigger = millis();
        return 1;
    }
    return 0;
}

int button::state()
{
    //if button is pressed and debounce time has passed then state is 1
    if (digitalRead(button_pin) && internal_debounce())
    {
#if DEBUG
        print_state(1);
#endif
        return button_id;
    }
    else
        return -1;
}

#if DEBUG
void button::print_state(int st)
{
    if (st)
    {
        times_pressed++;
        Serial.println(F("------------------"));
        if (button_id)
        {
            Serial.print(F("Button_"));
            Serial.print(button_id);
        }
        else
        {
            Serial.print(F("Profile button"));
        }
        Serial.print(F(" registered: "));
        switch (st)
        {
        case 1:
            Serial.print(F(" single click"));
            break;
        }
        Serial.print(F(" (x"));
        Serial.print(times_pressed);
        Serial.println(F(")"));
    }
}
#endif