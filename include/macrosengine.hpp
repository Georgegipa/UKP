#pragma once
#include <Mouse.h>
#include "extra_button_codes.h"

class macrosengine
{
private:
    int find_key(char *word);
    inline int findMacroID(int profile_id, int button_id);
public:
    macrosengine();
    ~macrosengine();
    void KeyboardMacro(int num_args, ...);
    void ExecuteMacro(int profile_id, int button_id);
};

extern macrosengine MA;