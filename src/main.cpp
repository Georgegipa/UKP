#include <Arduino.h>
#include <Mouse.h>
#include <Keyboard.h>
#include "button.hpp"

/* #define button_1 15
#define button_2 14
#define button_3 16 */

button button_1(15),button_2(14),button_3(16);


void UKP()
{
  Serial.begin(9600);
  Mouse.begin();
  Keyboard.begin();
  pinMode(LED_BUILTIN, OUTPUT);
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