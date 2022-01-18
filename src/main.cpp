#include <Arduino.h>
#include "UKP/UKPmanager.hpp"
#include "scomms/scomms.hpp"

void setup()
{
  SC.begin(9600);
  manager.begin();
}

void loop()
{
  manager.runtime();
  SC.runtime();
}