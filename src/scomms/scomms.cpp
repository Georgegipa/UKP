#include "scomms/scomms.hpp"
#include "settings.h"

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
        Serial.print(PROTOCOL_PREFIX);
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
        Serial.print(PROTOCOL_PREFIX);
        Serial.print("Protocol:");
        Serial.print(PROTOCOL);
        break;
    case '2':
        Serial.print(PROTOCOL_PREFIX);
        Serial.print("Version:");
        Serial.print(PROTOCOL_VERSION);
        break;
    case '3':
        Serial.print(PROTOCOL_PREFIX);
        Serial.print("Board:");
        Serial.print(BOARD_NAME);
        break;
    case '4':
        Serial.print(PROTOCOL_PREFIX);
        Serial.print("Buttons:");
        Serial.print(BUTTONS);
        break;
    default:
        Serial.print(NOT_VALID_COMMAND);
        break;
    }
}

void scomms::sendReport(InputData data)
{
    if (data.type == type_none) // type none shouldn't do anything
        return;
    Serial.print(PROTOCOL_PREFIX);
    switch (data.type)
    {
    case type_button:
        Serial.print("Button:");
        Serial.print(data.id);
        break;
    case type_joystick:
        Serial.print("Joystick[");
        Serial.print(data.id);
        Serial.print("]:");
        Serial.print(data.state);
        break;
    case type_keypad:
    case type_encoder:
    default:
        return;
    }
}

void scomms::runtime()
{
    if (Serial.available() > 0)
    {
        respond(Serial.read());
    }
}