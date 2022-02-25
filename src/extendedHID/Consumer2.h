#pragma once
#include "settings.h"
#ifdef HID_ENABLED
#include <Arduino.h>
#include "HID.h"
#include "Consumer_definitions.h"
#include "Consumer2_Keycodes.h"

typedef union ATTRIBUTE_PACKED
{
    // Every usable Consumer key possible, up to 4 keys presses possible
    uint8_t whole8[0];
    uint16_t whole16[0];
    uint32_t whole32[0];
    ConsumerKeycode keys[4];
    struct ATTRIBUTE_PACKED
    {
        ConsumerKeycode key1;
        ConsumerKeycode key2;
        ConsumerKeycode key3;
        ConsumerKeycode key4;
    };
} HID_ConsumerControlReport_Data_t;

class Consumer2_
{
private:
    inline void press(ConsumerKeycode m)
    {
        // search for a free spot
        for (uint8_t i = 0; i < sizeof(HID_ConsumerControlReport_Data_t) / 2; i++)
        {
            if (_report.keys[i] == HID_CONSUMER_UNASSIGNED)
            {
                _report.keys[i] = m;
                break;
            }
        }
        SendReport(&_report, sizeof(_report));
    }
    inline void release(ConsumerKeycode m)
    {
        // search and release the keypress
        for (uint8_t i = 0; i < sizeof(HID_ConsumerControlReport_Data_t) / 2; i++)
        {
            if (_report.keys[i] == m)
            {
                _report.keys[i] = HID_CONSUMER_UNASSIGNED;
                // no break to delete multiple keys
            }
        }
        SendReport(&_report, sizeof(_report));
    }
    inline void releaseAll(void)
    {
        end();
    }

public:
    Consumer2_(void);
    inline void begin(void)
    {
        end();
    }
    inline void end(void)
    {
        memset(&_report, 0, sizeof(_report));
        SendReport(&_report, sizeof(_report));
    }
    inline void write(ConsumerKeycode m)
    {
        press(m);
        release(m);
    }
    // Sending is public in the base class for advanced users.
    void SendReport(void *data, int length);

protected:
    HID_ConsumerControlReport_Data_t _report;
};
extern Consumer2_ Consumer;
#endif