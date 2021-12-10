#include "button.hpp"
#include "actions.hpp"
#include "Keyboard.h"
#include "options.hpp"

int button::numofbuttons = 0;
int button::profile_id = 0;

button::button(int pin)
{
    button_pin = pin;
    button_id = numofbuttons;
    numofbuttons++;
    pinMode(button_pin, INPUT);
    if (numofbuttons == 1)
        InitActions();
}

button::button(){
    button_pin = button_pins[numofbuttons];
    button_id = numofbuttons;
    numofbuttons++;    
    pinMode(button_pin, INPUT);
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
        ExecuteMacro(profile_id,button_id);
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
        Serial.println(F("------------------"));
        Serial.print(F("Button_"));
        Serial.print(button_id+1);
        Serial.print(F(" registered: "));
        switch (st)
        {
        case single_click:
            Serial.print(F(" single click"));
            break;
        }
        Serial.print(F(" (x"));
        Serial.print(times_pressed);
        Serial.println(F(")"));
    }
}
#elif
void button::print_state(int st)
{
}
#endif