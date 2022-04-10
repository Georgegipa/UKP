#pragma once
#include "settings.h"
#ifdef HID_ENABLED
#if SD_ENABLED
#include "sdcard/sdcard.hpp"
#endif

class macroretriever
{
private:
    /* data */
    inline int findMacroID(int profileId, int buttonId);
public:
    void begin();
    char *getMacro( int buttonId,int profileId=0, bool loadDefaults = !SD_ENABLED);
};
extern macroretriever Retriever;
#endif