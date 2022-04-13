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
#endif
    int getFileInfo(const char *fileName = DEFAULT_FILE);
    int lineLen(int line, const char *fileName = DEFAULT_FILE);
    int retrieveLinePos(int line, const char *fileName = DEFAULT_FILE);
    bool checkConnection(const char *fileName = DEFAULT_FILE);
    char *readLine(int lineNumber, const char *fileName = DEFAULT_FILE);
    void replaceCarriageReturn(char replacement = '\0');
    bool sdCardFailed = 0;
#endif
public:
    void begin();
    char *getMacro(int buttonId, int profileId = 0);
    void LongMacro(int original_pos,  const char *fileName = DEFAULT_FILE);
};
extern macroretriever Retriever;
#endif