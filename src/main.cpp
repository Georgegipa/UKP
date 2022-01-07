#include <Arduino.h>
#include "UKPmanager.hpp"

void setup()
{
  UKP.begin();
}

void loop()
{
  UKP.runtime();
}