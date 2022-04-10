#pragma once
#include "settings.h"
#ifdef HID_ENABLED
#if SD_ENABLED
#include <SPI.h>
#include <SD.h>
#endif

class macroretriever
{
private:
    char str[MACRO_MAX_SIZE];
    inline int findMacroID(int profileId, int buttonId);
#if SD_ENABLED
#if DEBUG
    void SDFileInfo();
    void printFile(const char *fileName);
#endif
    int retrieveLinePos(int line, const char *fileName = DEFAULT_FILE);
#endif
public:
    void begin();
    char *getMacro(int buttonId, int profileId = 0);

#if SD_ENABLED
    bool checkConnection(const char *fileName = DEFAULT_FILE);
    char *readLine(int lineNumber, const char *fileName = DEFAULT_FILE);
#endif
};
extern macroretriever Retriever;
#endif