#include "settings.h"
#if SD_ENABLED
#pragma once
#include <SPI.h>
#include <SD.h>

class sdcard
{
private:
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