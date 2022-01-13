#include <Arduino.h>
#include "UKP/UKPmanager.hpp"
#include "jcomms/scomms.hpp"

void setup()
{
  JC.begin(9600);
  manager.begin();
}

void loop()
{
  manager.runtime();
  JC.runtime();
}