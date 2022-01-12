#include <Arduino.h>
#include "UKP/UKPmanager.hpp"

void setup()
{
  manager.begin();
}

void loop()
{
  manager.runtime();
}