#include "button.hpp"

int button::numofbuttons = 0;

button::button(int pin)
{
    button_pin = pin;
    numofbuttons++;
    id = numofbuttons;
    pinMode(pin, INPUT);
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
        last_trigger=millis();
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

    //if button is pressed and debounce time has passed then state is true
    if (digitalRead(button_pin) && internal_debounce())
    {
        print_state(1);
        return digitalRead(button_pin);
    }
    else
        return 0;
}

int button::advnaced_state()
{//add multi-functions to button
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
        case double_click:
            Serial.print(" double click");
            break;
        case long_click:
            Serial.print(" long press");
            break;
        case longer_click:
            Serial.print(" longer press");
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