#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class sdcard
{
private:
    const char *file = "macros.txt";
    char *internal_str;
    int times_called;
    void refereshFileInfo();
    bool sdconnected;

public:
    bool init();
    bool checkConnection();
    int max_lines, max_str_len;
    char *readLine(int line);
};

extern sdcard sd;