#include "jcomms/scomms.hpp"
#include "definitions.h"

scomms JC;

void scomms::begin(int baudRate)
{
    Serial.begin(baudRate);
}

void scomms::respond(int request)
{
    switch (request)
    {
    case 1:
        Serial.print(prefix);
        Serial.print("Protocol:");
        Serial.print(PROTOCOL);
        break;
    case 2:
        Serial.print(prefix);
        Serial.print("Version:");
        Serial.print(PROTOCOL_VERSION);
        break;
    case 3:
        Serial.print(prefix);
        Serial.print("Board:");
        Serial.print(BOARD_NAME);
        break;
    case 4:
        Serial.print(prefix);
        Serial.print("Buttons:");
        Serial.print(BUTTONS);
        break;
    default:
        Serial.print(request);
        break;
    }
}

void scomms::runtime()
{
    if (Serial.available() > 0)
    {
        respond((int)Serial.read());
    }
}