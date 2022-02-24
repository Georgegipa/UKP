#include "7segment/_7segment.hpp"
#if SEVEN_SEGMENT
#include "helpers.h"

void _7segment::begin(bool is_cathode)
{
    for (int i = 0; i < SEGMENT_LEDS; i++)
        led[i].begin(intfromPROGMEM(leds, i), !is_cathode);
}

void _7segment::display(const byte *arr, int num)
{
    bool isBitSet;
    int led_pos = 0;
    for (int i = 7; i >= 0; i--)
    { //start from the bit and check one by one if it is 1 or 0
        isBitSet = bitRead(arr[num], i);
        if (isBitSet)
            led[led_pos].setHigh();
        else
            led[led_pos].setLow();
        led_pos++;
    }
}

void _7segment::displayChar(int c)
{
    if (c >= 97 && c <= 122) //convert lower case letters to capital ones
        c = toupper(c);
    int conversion;
    if (c >= 21 && c <= 47) //symbols before numbers
    {
        conversion = c - 21; //0 is first allowed symbol
        display(symbols, conversion);
    }
    else if (c >= 48 && c <= 57) //numbers
    {
        conversion = c - 48;
        display(numbers, conversion);
    }
    else if (c >= 58 && c <= 64) //symbols after numbers
    {
        conversion = c - 58 + 14; //add the position of the last symbol before numbers

        display(symbols, conversion);
    }
    else if (c >= 65 && c <= 90) //letters
    {
        conversion = c - 65;
        display(alphabet, conversion);
    }
    else if (c >= 91 && c <= 96) //symbols after letters
    {
        conversion = c - 91 + 19; //add the previously passed symbols
        if (c == 91)
            conversion = 6; //remap [ to (
        else if (c == 93)
            conversion = 7; //remap ] to )
        else if (c == 92)
            conversion = 21; //remap \ //
        else if (c == 96)
            conversion = 5; //remap ` to '
        display(symbols, conversion);
    }
}

void _7segment::displayProfile(int num)
{
    if (num <= 9)
    {
        led[SEGMENT_LEDS - 1].setLow();
        displayChar((char)num + 48);
    }
    else if (num <= 19)
    {
        displayChar((char)(num - 10 +48));
        led[SEGMENT_LEDS - 1].setHigh();
    }
}

#if DEBUG
void _7segment::testLeds()
{
    for (int i = 0; i < SEGMENT_LEDS; i++)
    {
        Serial.print("Led: ");
        if (i == SEGMENT_LEDS - 1)
            Serial.println(".");
        else
            Serial.println((char)(97 + i));
        led[i].setHigh();
        delay(1000);
        led[i].setLow();
        delay(300);
    }
}
#endif
#endif