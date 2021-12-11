#include <Arduino.h>
#include "button.hpp"
#include "options.hpp"

button button_1(button_pins[0]), button_2(button_pins[1]), button_3(button_pins[2]);

void UKP()
{
  Serial.begin(9600);
#if DEBUG_OPTIONS_ENABLED
  while (!Serial); //wait for serial
  Serial.print("Number of buttons intialized:");
  Serial.println(button::numofbuttons);
  Serial.print("Number of profiles intialized:");
  Serial.println(num_of_profiles);
#endif
}

void setup()
{
  UKP();
}

void loop()
{
  button_1.state();
  button_2.state();
  button_3.state();
}
