#pragma once
#include <Mouse.h>
#include "extra_button_codes.h"

class macrosengine
{
private:
    int find_key(char *word);
    inline int findMacroID(int profile_id, int button_id);
    void ExecuteMacro(char *macro);
public:
    macrosengine();
    ~macrosengine();
    void KeyboardMacro(int num_args, ...);
    void ParseMacro(int profile_id, int button_id, bool load_default_profile=1);
};

extern macrosengine MA;