#include <Arduino.h>
#include <Mouse.h>
#include <Keyboard.h>

#define button_1 15
#define button_2 14
#define button_3 16

void setup() {
  Serial.begin(9600);
  Mouse.begin(); 
  Keyboard.begin();
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(button_1,INPUT);
  pinMode(button_2,INPUT);
  pinMode(button_3,INPUT);

}

void loop() {
  Serial.print("Button_1 state:");
  Serial.println(digitalRead(button_1));
  delay(250);
  Serial.print("Button_2 state:");
  Serial.println(digitalRead(button_2));
  delay(250);
  Serial.print("Button_3 state:");
  Serial.println(digitalRead(button_3));
  delay(250);  
}