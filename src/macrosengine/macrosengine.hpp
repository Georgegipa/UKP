#pragma once
#include "settings.h"
#ifdef HID_ENABLED
#include <Mouse.h>
#include "basic_key_codes.h"
#include "extra_key_codes.h"

class macrosengine
{
private:
    enum KeyCodeType
    {
        KEY_NOT_FOUND,
        BASIC_KEY_CODE,
        EXTRA_KEY_CODE,
        MOUSE_ACTION        
    };
    enum KeyBehavior
    {
        WAIT_FOR_ALL_KEYS,
        PRESS_ONCE,
        KEEP_PRESSED
    };
    union KeyCode
    {
        ConsumerKeycode consumerCode;
        int keyboardCode;
    }keyCode;
    int findKey(char *word);
    ConsumerKeycode findExtraKey(char *key);
    KeyCodeType findKeyCodeType(char *word);
    int mouseAction(char *word);
    bool isMouseAction(char *word);
    inline void mouseScroll(bool up, int val);
    void executeMacro(char *macro, macrosengine::KeyBehavior behavior=WAIT_FOR_ALL_KEYS);
    void processProfile(char *word);
    void extraAction(macrosengine::KeyCodeType type, macrosengine::KeyBehavior behavior=WAIT_FOR_ALL_KEYS);
    
public:
    bool stickyKeys;
    void begin();
    ~macrosengine();
    void keyboardMacro(int num_args, ...);
    void parseMacro(char *macro);
    void clearStickyKeys();
    void KeyboardPrint(char *word);
    void macroCommand(char *macro);
    inline char getMacroCommand(char *macro);
    bool isMacroCommand(char *macro);
};
extern macrosengine MA;
#endif