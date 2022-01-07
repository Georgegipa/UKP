#include "sdcard.hpp"

sdcard sd;

bool sdcard::init()
{
    if (!SD.begin(10))
    {
        Serial.println("Card Mount Failed");
        sdconnected = 0;
        return NULL;
    }
    else
    {
        sdconnected = 1;
        Serial.println("Successfully mounted microSD");
    }
    times_called = 0;
    refereshFileInfo();
    return sdconnected;
}

bool sdcard::checkConnection()
{
    if (!sdconnected)
        init();
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
    max_lines = 0;
    max_str_len = 0;
    while (F.available())
    {
        char t = F.read();
        if (t == '\n')
        {
            //remove \n from max length
            if (current_str_len > max_str_len)
                max_str_len = current_str_len - 1;
            current_str_len = 0;
            max_lines++;
        }
        else
        {
            current_str_len++;
        }
        Serial.print(t);
    }
    F.close();
    if (times_called) //if this function was called at least once before
        free(internal_str);
    internal_str = (char *)malloc(sizeof(char) * max_str_len);
    times_called++;
}

char *sdcard::readLine(int line)
{
    if (line > max_lines)
        return NULL;
    File F = SD.open(file);
    memset(internal_str, '\0', sizeof(char) * max_lines); //initialize empty array
    int linesread = 0, i = 0;
    bool found = 0;
    while (F.available())
    {
        char t = F.read();
        internal_str[i] = t;
        if (t == '\n')
        {
            if (line == linesread)
            {
                internal_str[i - 1] = '\0'; //replace \n with \0
                found = 1;
                break;
            }
            else
                //replace the written part of the array with null terminators
                memset(internal_str, '\0', sizeof(char) * strlen(internal_str));
            linesread++;
            i = 0;
        }
        else
            i++;
    }
    F.close();
    if (found)
        return internal_str;
    else
        return NULL;
}