#pragma once
#ifdef HID_ENABLED
#include <Mouse.h>
#include "extra_button_codes.h"
#include "definitions.h"
#if SD_ENABLED
#include "sdcard/sdcard.hpp"
#endif

class macrosengine
{
private:
    int findKey(char *word);
    inline int findMacroID(int profileId, int buttonId);
    void executeMacro(char *macro, bool releaseOneByOne=0);
    void onePress();
public:
    void begin();
    ~macrosengine();
    void keyboardMacro(int num_args, ...);
    //if sd card is enabled then loadDefaults should be set to 0 to try load sd card macros first
    void parseMacro(int profileId, int buttonId, bool loadDefaults = !SD_ENABLED); 
};

extern macrosengine MA;
#endif