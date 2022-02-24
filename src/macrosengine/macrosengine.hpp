#pragma once
#ifdef HID_ENABLED
#include <Mouse.h>
#include "basic_key_codes.h"
#include "extra_key_codes.h"
#include "settings.h"
#if SD_ENABLED
#include "sdcard/sdcard.hpp"
#endif

class macrosengine
{
private:
    int findKey(char *word);
    ConsumerKeycode findExtraKey(char *word);
    inline int findMacroID(int profileId, int buttonId);
    void executeMacro(char *macro, bool releaseOneByOne=0);
    void executeExtraKey(char *key);
    inline void mouseScroll(bool up,int val);
    void mouseAction(char *word);
public:
    void begin();
    ~macrosengine();
    void keyboardMacro(int num_args, ...);
    //if sd card is enabled then loadDefaults should be set to 0 to try load sd card macros first
    void parseMacro(int profileId, int buttonId, bool loadDefaults = !SD_ENABLED); 
};
extern const int defaultProfilesSum;
extern macrosengine MA;
#endif