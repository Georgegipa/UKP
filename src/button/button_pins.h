#include <Arduino.h>
#include "definitions.h"
/*Define the pins for each of the number of BUTTONS declared in definitions.h
(Note that the first number button pin is used for profile switching 
(unless PROFILE is set to 0)) */
const int buttonPins[BUTTONS] PROGMEM = {A0, A1, A2};