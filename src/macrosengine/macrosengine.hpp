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
    inline int findMacroID(int profileId, int buttonId);
    void executeMacro(char *macro, int extraActions = 0);
    bool processExtraKey(char *key,bool hold=0);
    inline void mouseScroll(bool up, int val);
    inline bool holdButton(int extraActions);
    int mouseAction(char *word);
    void processProfile(char *word);

public:
    bool stickyKeys;
    void begin();
    ~macrosengine();
    void keyboardMacro(int num_args, ...);
    void parseMacro(int buttonId, int profileId = 0, bool loadDefaults = !SD_ENABLED);
    void clearStickyKeys();
};
extern macrosengine MA;
#endif