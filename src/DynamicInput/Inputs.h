#pragma once

typedef enum
{
    type_none,
    type_button,
    type_keypad,
    type_encoder,
    type_joystick//possible positions 0-8
}InputType;

typedef struct
{
    InputType type;//type of input
    int id;//id of triggered input if multiples exist,index of array(example. 1st btn -> 0 , 2nd btn -> 1 ...)
    int state = 0; // last known state of triggered input
}InputData;