#if HID_ENABLED && SD_ENABLED
#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class sdcard
{
private:
    const char *file = "macros.txt";
    char *internalStr;
    int timesCalled;
    void refereshFileInfo();
    bool sdConnected;

public:
    bool begin();
    bool checkConnection();
    int maxLines, maxStrLength;
    char *readLine(int line);
};

extern sdcard sd;
#endif