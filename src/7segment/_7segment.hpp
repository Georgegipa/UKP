#pragma once
#include "settings.h"
#if SEVEN_SEGMENT
#include "binary_output/binary_output.hpp"
#define SEGMENT_LEDS 8
PROGMEM_INT leds[SEGMENT_LEDS] = {SEVEN_SEGMENT_PINS};

const byte symbols[] = {

    B01000001, //!
    B01000100, //"
    B01101100, //#
    B10110100, //%
    B11011110, //&
    B00000100, //',`
    B10011100, //(,[
    B11110000, //),]
    B11000110, //*
    B00001110, //h
    B00110000, //,
    B00000010, //-
    B00000001, //.
    B01000010, // /
    B00010010, //:
    B10110000, //;(modified)
    B10000110, //<
    B10000010, //=
    B11000010, //>
    B11100011, //?(modified)
    B11111010, //@
    B00000110, // \ ///
    B11000100, //^
    B00010000  //_
};

const byte numbers[] = {
    B11111100, //0
    B01100000, //1
    B11011010, //2
    B11110010, //3
    B01100110, //4
    B10110110, //5
    B10111110, //6
    B11100000, //7
    B11111110, //8
    B11110110, //9
};

const byte alphabet[] = {

    B11101110, //A
    B00111110, //b
    B10011100, //C
    B01111010, //d
    B10011110, //E
    B10001110, //F
    B10111100, //G
    B00101110, //h
    B00001100, //I
    B01111000, //J
    B10101110, //k
    B00011100, //L
    B10101000, //M
    B11101100, //N
    B11111100, //O
    B11001110, //P
    B11100110, //Q
    B11001100, //P
    B10110110, //S
    B00011110, //t
    B01111100, //U
    B01110100, //V
    B01010100, //W
    B01101110, //X
    B01110110, //Y
    B11010010  //Z
};

class _7segment
{
private:
    binary_output led[SEGMENT_LEDS];
    void display(const byte *ledArray, int ledId);

public:
    //if COM pin is connected to GND(cathode) is_cathode is true
    void begin(bool isCathode = 1);
    void displayChar(int c);
    void displayProfile(int profileId);
#if DEBUG
    void testLeds();
#endif
};
#endif