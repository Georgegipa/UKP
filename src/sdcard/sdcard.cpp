#ifdef HID_ENABLED
#include "definitions.h"
#if SD_ENABLED
#include "sdcard/sdcard.hpp"

sdcard sd;

bool sdcard::begin()
{
    if (!SD.begin(10))
    {
        Serial.println("Card Mount Failed");
        sdConnected = 0;
        return false;
    }
    else
    {
        sdConnected = 1;
        Serial.println("Successfully mounted microSD");
    }
    timesCalled = 0;
    refereshFileInfo();
    return sdConnected;
}

bool sdcard::checkConnection()
{
    if (!sdConnected)
        begin();
    else
    {
        File F = SD.open(file);
        if (F)//if file exists return true
            return 1;
    }
    return 0;
}

void sdcard::refereshFileInfo()
{
    File F = SD.open(file);
    int current_str_len = 0;
    maxLines = 0;
    maxStrLength = 0;
    while (F.available())
    {
        char t = F.read();
        if (t == '\n')
        {
            //remove \n from max length
            if (current_str_len > maxStrLength)
                maxStrLength = current_str_len - 1;
            current_str_len = 0;
            maxLines++;
        }
        else
        {
            current_str_len++;
        }
        Serial.print(t);
    }
    F.close();
    if (timesCalled) //if this function was called at least once before
        free(internalStr);
    internalStr = (char *)malloc(sizeof(char) * maxStrLength);
    timesCalled++;
}

char *sdcard::readLine(int line)
{
    if (line > maxLines)
        return NULL;
    File F = SD.open(file);
    memset(internalStr, '\0', sizeof(char) * maxLines); //initialize empty array
    int linesread = 0, i = 0;
    bool found = 0;
    while (F.available())
    {
        char t = F.read();
        internalStr[i] = t;
        if (t == '\n')
        {
            if (line == linesread)
            {
                internalStr[i - 1] = '\0'; //replace \n with \0
                found = 1;
                break;
            }
            else
                //replace the written part of the array with null terminators
                memset(internalStr, '\0', sizeof(char) * strlen(internalStr));
            linesread++;
            i = 0;
        }
        else
            i++;
    }
    F.close();
    if (found)
        return internalStr;
    else
        return NULL;
}
#endif
#endif