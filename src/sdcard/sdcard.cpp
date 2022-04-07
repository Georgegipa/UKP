#include "sdcard/sdcard.hpp"
#if SD_ENABLED
#define file "macros.txt"
sdcard sd;

bool sdcard::begin()
{
    if (!SD.begin(10))
    {
        SSprintf("Card Mount Failed\n");
        sdConnected = 0;
        return false;
    }
    else
    {
        sdConnected = 1;
        SSprintf("Successfully mounted microSD\n");
    }
    timesCalled = 0;
    refereshFileInfo();
    return sdConnected;
}

//show the SD files info
void sdcard::refereshFileInfo()
{
    if (sdConnected)
    {
        SSprintf("\n");
        SSprintf("File List:\n");
        SSprintf("----------\n");
        File root = SD.open("/");
        if (!root)
        {
            SSprintf("Error opening root\n");
            return;
        }
        File f = root.openNextFile();
        while (f)
        {
            if (f.isDirectory())
            {
                SSprintf("[%s]\n", f.name());
            }
            else
            {
                SSprintf("%s\n", f.name());
            }
            f = root.openNextFile();
        }
        SSprintf("\n");
    }
}

//read specified line from file
char *sdcard::readLine(const char *fileName, int lineNumber)
{
    if (sdConnected)
    {
        File f = SD.open(fileName);
        if (!f)
        {
            SSprintf("Error opening file\n");
            return NULL;
        }
        for (int i = 0; i < lineNumber; i++)
        {
            f.readBytesUntil('\n', internalStr, MACRO_MAX_SIZE);
        }
        f.close();
        return internalStr;
    }
    else
    {
        return NULL;
    }
}

char *sdcard::readLine(int line)
{
    return readLine(file, line);
}


//check if a file exists
bool sdcard::checkConnection()
{
    if (sdConnected)
    {
        File f = SD.open(file);
        if (!f)
        {
            SSprintf("Error opening file\n");
            return false;
        }
        f.close();
        return true;
    }
    else
    {
        return false;
    }
}

#endif