#include <Arduino.h>
#include "UKPmanager.hpp"

void setup()
{
  UKP.init();
}

void loop()
{
  UKP.runtime();
}