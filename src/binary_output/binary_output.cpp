#include "binary_output.hpp"

void binary_output::begin(int pin, bool reversed,int initial_state)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    if (reversed)
    {
        stateLow = 1;
        stateHigh = 0;
        initial_state=1;
    }
    digitalWrite(ledPin, initial_state); //set led off
}

void binary_output::setHigh()
{
    digitalWrite(ledPin,stateHigh);
}

void binary_output::setLow()
{
    digitalWrite(ledPin,stateLow);
}


void binary_output::flashing(int times,int ms,double offset)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(ledPin, stateHigh);
        delay(ms*(1+offset));
        digitalWrite(ledPin, stateLow);
        delay(ms*(1-offset));
    }
}