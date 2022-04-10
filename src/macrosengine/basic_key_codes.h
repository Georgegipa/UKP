#include "settings.h"
#include "Keyboard.h"

namespace basicKeys
{
    MACRO binding_0[] = "CTRL";
    MACRO binding_1[] = "SHIFT";
    MACRO binding_2[] = "ALT";
    MACRO binding_3[] = "WIN";
    MACRO binding_4[] = "UP";
    MACRO binding_5[] = "DOWN";
    MACRO binding_6[] = "LEFT";
    MACRO binding_7[] = "RIGHT";
    MACRO binding_8[] = "BKSP";
    MACRO binding_9[] = "TAB";
    MACRO binding_10[] = "ENTER";
    MACRO binding_11[] = "ESC";
    MACRO binding_12[] = "INS";
    MACRO binding_13[] = "DEL";
    MACRO binding_14[] = "PU";
    MACRO binding_15[] = "PD";
    MACRO binding_16[] = "HOME";
    MACRO binding_17[] = "END";
    MACRO binding_18[] = "CL";

    MACRO_ARRAY bindings[] = {
        binding_0,
        binding_1,
        binding_2,
        binding_3,
        binding_4,
        binding_5,
        binding_6,
        binding_7,
        binding_8,
        binding_9,
        binding_10,
        binding_11,
        binding_12,
        binding_13,
        binding_14,
        binding_15,
        binding_16,
        binding_17,
        binding_18};

    const int key_codes[] PROGMEM =
        {
            KEY_LEFT_CTRL,
            KEY_LEFT_SHIFT,
            KEY_LEFT_ALT,
            KEY_LEFT_GUI,
            KEY_UP_ARROW,
            KEY_DOWN_ARROW,
            KEY_LEFT_ARROW,
            KEY_RIGHT_ARROW,
            KEY_BACKSPACE,
            KEY_TAB,
            KEY_RETURN,
            KEY_ESC,
            KEY_INSERT,
            KEY_DELETE,
            KEY_PAGE_UP,
            KEY_PAGE_DOWN,
            KEY_HOME,
            KEY_END,
            KEY_CAPS_LOCK};

    PROGMEM_INT bindingsSum = ARR_SIZE(key_codes);    // number of all bindings
    PROGMEM_INT bindingMaxSize = ARR_SIZE(binding_1); // size of the longest binding
}