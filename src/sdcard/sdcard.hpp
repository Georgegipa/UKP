#include "settings.h"
#if SD_ENABLED
#pragma once
#include <SPI.h>
#include <SD.h>

class sdcard
{
private:
    char internalStr[MACRO_MAX_SIZE];
    int timesCalled;
    void refereshFileInfo();
    bool sdConnected;

public:
    bool begin();
    bool checkConnection();
    char *readLine(const char *fileName, int lineNumber);
    char *readLine(int line);
};

extern sdcard sd;
#endif