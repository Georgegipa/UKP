#pragma once
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class sdcard
{
private:
    const char *file = "macros.txt";
    enum sdstatus
    {
        notconnected,
        connected,
        no_file
    };
    char *internal_str;
    int times_called;
    void refereshFileInfo();

public:
    int max_lines, max_str_len;
    char *readLine(int line);
    int sdconnected;
    bool init();
};

extern sdcard sd;