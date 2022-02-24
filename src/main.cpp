#include <Arduino.h>
#include "printtobuild.h"
#include "UKP/UKPmanager.hpp"
#include "scomms/scomms.hpp"

void setup()
{
  SC.begin(BAUD_RATE);
  manager.begin();
}

void loop()
{
  manager.runtime();
  SC.runtime();
}