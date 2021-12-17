#include "binary_output.hpp"

void binary_output::init(int pin, bool reversed,int initial_state)
{
    led_pin = pin;
    pinMode(led_pin, OUTPUT);
    if (reversed)
    {
        state_low = 1;
        state_high = 0;
        initial_state=1;
    }
    digitalWrite(led_pin, initial_state); //set led off
}

void binary_output::setHigh()
{
    digitalWrite(led_pin,state_high);
}

void binary_output::setLow()
{
    digitalWrite(led_pin,state_low);
}


void binary_output::flashing(int times,int ms,double offset)
{
    for (int i = 0; i < times; i++)
    {
        digitalWrite(led_pin, state_high);
        delay(ms*(1+offset));
        digitalWrite(led_pin, state_low);
        delay(ms*(1-offset));
    }
}