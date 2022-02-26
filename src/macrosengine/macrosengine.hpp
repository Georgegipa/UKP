#pragma once
#include "settings.h"
#ifdef HID_ENABLED
#include <Mouse.h>
#include "basic_key_codes.h"
#include "extra_key_codes.h"
#if SD_ENABLED
#include "sdcard/sdcard.hpp"
#endif

class macrosengine
{
private:
    int findKey(char *word);
    ConsumerKeycode findExtraKey(char *word);
    inline int findMacroID(int profileId, int buttonId);
    void executeMacro(char *macro, bool releaseOneByOne = 0);
    void executeExtraKey(char *key);
    inline void mouseScroll(bool up, int val);
    int mouseAction(char *word);
    void processProfile(char *word);

public:
    void begin();
    ~macrosengine();
    void keyboardMacro(int num_args, ...);
    void parseMacro(int buttonId, int profileId = 0, bool loadDefaults = !SD_ENABLED);
};
extern macrosengine MA;
#endif