#pragma once
#include <Mouse.h>
#include "extra_button_codes.h"
#include "definitions.h"
#if MICRO_SD_ENABLED
#include "sdcard/sdcard.hpp"
#endif

class macrosengine
{
private:
    int findKey(char *word);
    inline int findMacroID(int profileId, int buttonId);
    void executeMacro(char *macro);

public:
    void begin();
    ~macrosengine();
    void keyboardMacro(int num_args, ...);
    void parseMacro(int profileId, int buttonId, bool loadDefaults = 0);
};

extern macrosengine MA;