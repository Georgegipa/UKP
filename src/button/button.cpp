#include "button/button.hpp"
#if BUTTON_SUM
#include "helpers/helpers.h"

int button::buttonSum = 0;

button::button()
{
    buttonId = buttonSum;
    buttonPin = intfromPROGMEM(buttonPins, buttonSum);
    buttonSum++;
    pinMode(buttonPin, INPUT);
}

bool button::internalDebounce(unsigned long debouncedelay)
{

    if ((millis() - lastTrigger) > debouncedelay)
    {
        lastTrigger = millis();
        return 1;
    }
    return 0;
}

int button::state()
{
    //if button is pressed and debounce time has passed then state is 1
    if (digitalRead(buttonPin) && internalDebounce())
    {
#if DEBUG
        printState();
#endif
        return buttonId;
    }
    else
        return -1;
}

#if DEBUG
void button::printState()
{
        timesPressed++;
        Serial.println(F("------------------"));
        if (buttonId)
        {
            Serial.print(F("Button_"));
            Serial.print(buttonId);
            Serial.print(F(" registered: "));
        }
        else
        {
            Serial.print(F("Profile button"));
        }
        Serial.print(F(" clicked x"));
        Serial.println(timesPressed);
}
#endif
#endif