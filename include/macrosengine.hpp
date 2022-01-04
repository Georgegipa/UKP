#pragma once
#include <Mouse.h>
#include "extra_button_codes.h"
#include "config/definitions.h"
#if MICRO_SD_ENABLED
#include "sdcard.hpp"
#endif

class macrosengine
{
private:
    int find_key(char *word);
    inline int findMacroID(int profile_id, int button_id);
    void ExecuteMacro(char *macro);

public:
    void init();
    ~macrosengine();
    void KeyboardMacro(int num_args, ...);
    void ParseMacro(int profile_id, int button_id, bool load_defaults = 0);
};

extern macrosengine MA;