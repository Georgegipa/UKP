#include <Arduino.h>
#include "printtobuild.h"
#include "UKP/UKPmanager.hpp"
#include "SKP/SKPmanager.hpp"

void setup()
{
  manager.begin();
}

void loop()
{
  manager.runtime();
}