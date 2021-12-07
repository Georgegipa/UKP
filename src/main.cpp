#include <Arduino.h>
#include <Mouse.h>
#include <Keyboard.h>
#include "button.hpp"

button button_1(15),button_2(14),button_3(16);


void UKP()
{
  Serial.begin(9600);
  Mouse.begin();
  Keyboard.begin();
  while(!Serial);//wait for serial
  #if DEBUG_OPTIONS_ENABLED
  Serial.print("Number of buttons intialized:");
  Serial.println(button::numofbuttons);
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