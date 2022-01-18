#include "scomms/scomms.hpp"
#include "definitions.h"

scomms SC;

void scomms::begin(int baudRate)
{
    Serial.begin(baudRate);
}

void scomms::respond(char request)
{
    switch (request)
    {
    case '0':
        Serial.print(protocolPrefix);
        Serial.print("Blinking Led");
        for (int i = 0; i < 5; i++)
        {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(300);
            digitalWrite(LED_BUILTIN, LOW);
            delay(300);
        }
        break;
    case '1':
        Serial.print(protocolPrefix);
        Serial.print("Protocol:");
        Serial.print(PROTOCOL);
        break;
    case '2':
        Serial.print(protocolPrefix);
        Serial.print("Version:");
        Serial.print(PROTOCOL_VERSION);
        break;
    case '3':
        Serial.print(protocolPrefix);
        Serial.print("Board:");
        Serial.print(BOARD_NAME);
        break;
    case '4':
        Serial.print(protocolPrefix);
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
        respond(Serial.read());
    }
}