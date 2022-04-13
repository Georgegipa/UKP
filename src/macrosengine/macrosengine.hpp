#pragma once
#include "settings.h"
#ifdef HID_ENABLED
#include <Mouse.h>
#include "basic_key_codes.h"
#include "extra_key_codes.h"

class macrosengine
{
private:
    int findKey(char *word);
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
    void parseMacro(char *macro);
    void clearStickyKeys();
    void KeyboardPrint(char *word);
};
extern macrosengine MA;
#endif