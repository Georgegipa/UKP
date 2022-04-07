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
    MACRO binding_8[] = "BACKSPACE";
    MACRO binding_9[] = "TAB";
    MACRO binding_10[] = "ENTER";
    MACRO binding_11[] = "ESC";
    MACRO binding_12[] = "INSERT";
    MACRO binding_13[] = "DELETE";
    MACRO binding_14[] = "PUP";
    MACRO binding_15[] = "PDOWN";
    MACRO binding_16[] = "HOME";
    MACRO binding_17[] = "END";
    MACRO binding_18[] = "CAPS";
    MACRO binding_19[] = "F1";
    MACRO binding_20[] = "F2";
    MACRO binding_21[] = "F3";
    MACRO binding_22[] = "F4";
    MACRO binding_23[] = "F5";
    MACRO binding_24[] = "F6";
    MACRO binding_25[] = "F7";
    MACRO binding_26[] = "F8";
    MACRO binding_27[] = "F9";
    MACRO binding_28[] = "F10";
    MACRO binding_29[] = "F11";
    MACRO binding_30[] = "F12";
    MACRO binding_31[] = "F13";
    MACRO binding_32[] = "F14";
    MACRO binding_33[] = "F15";
    MACRO binding_34[] = "F16";
    MACRO binding_35[] = "F17";
    MACRO binding_36[] = "F18";
    MACRO binding_37[] = "F19";
    MACRO binding_38[] = "F20";
    MACRO binding_39[] = "F21";
    MACRO binding_40[] = "F22";
    MACRO binding_41[] = "F23";
    MACRO binding_42[] = "F24";

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
        binding_18,
        binding_19,
        binding_20,
        binding_21,
        binding_22,
        binding_23,
        binding_24,
        binding_25,
        binding_26,
        binding_27,
        binding_28,
        binding_29,
        binding_30,
        binding_31,
        binding_32,
        binding_33,
        binding_34,
        binding_35,
        binding_36,
        binding_37,
        binding_38,
        binding_39,
        binding_40,
        binding_41,
        binding_42};

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
            KEY_CAPS_LOCK,
            KEY_F1,
            KEY_F2,
            KEY_F3,
            KEY_F4,
            KEY_F5,
            KEY_F6,
            KEY_F7,
            KEY_F8,
            KEY_F9,
            KEY_F10,
            KEY_F11,
            KEY_F12,
            KEY_F13,
            KEY_F14,
            KEY_F15,
            KEY_F16,
            KEY_F17,
            KEY_F18,
            KEY_F19,
            KEY_F20,
            KEY_F21,
            KEY_F22,
            KEY_F23,
            KEY_F24};

    PROGMEM_INT bindingsSum = ARR_SIZE(key_codes);    // number of all bindings
    PROGMEM_INT bindingMaxSize = ARR_SIZE(binding_8); // size of the longest binding
}