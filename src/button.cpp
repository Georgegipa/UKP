#include "button.hpp"
#include "options.hpp"
#include "macrosengine.hpp"

int button::numofbuttons = 0;
int button::current_profile = 0;

button::button(int pin)
{
    button_pin = pin;
    button_id = numofbuttons;
    numofbuttons++;
    pinMode(button_pin, INPUT);
}

button::button()
{
    button_pin = button_pins[numofbuttons];
    button_id = numofbuttons;
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

bool button::state()
{
    //if button is pressed and debounce time has passed then state is 1
    if (digitalRead(button_pin) && internal_debounce())
    {
#if DEBUG
        print_state(1);
#endif
        if (button_id) //if button isn't profile button
            MA.ExecuteMacro(current_profile, button_id - 1);
        else
        {
            if (current_profile < num_of_profiles - 1)
                current_profile++;
            else
                current_profile = 0;
#if DEBUG
            Serial.print(F("Current Profile changed to: "));
            Serial.println(current_profile);
#endif
        }
        return digitalRead(button_pin);
    }
    else
        return 0;
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