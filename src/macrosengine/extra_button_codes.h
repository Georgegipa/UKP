#include <Arduino.h>
#include "Keyboard.h"
#include "macros.h"

//use PROGMEM to improve memory usage
const char binding_0[] PROGMEM = "CTRL";
const char binding_1[] PROGMEM = "SHIFT";
const char binding_2[] PROGMEM = "ALT";
const char binding_3[] PROGMEM = "WIN";
const char binding_4[] PROGMEM = "UP";
const char binding_5[] PROGMEM = "DOWN";
const char binding_6[] PROGMEM = "LEFT";
const char binding_7[] PROGMEM = "RIGHT";
const char binding_8[] PROGMEM = "BACKSPACE";
const char binding_9[] PROGMEM = "TAB";
const char binding_10[] PROGMEM = "RETURN";
const char binding_11[] PROGMEM = "ESC";
const char binding_12[] PROGMEM = "INSERT";
const char binding_13[] PROGMEM = "DELETE";
const char binding_14[] PROGMEM = "PUP";
const char binding_15[] PROGMEM = "PDOWN";
const char binding_16[] PROGMEM = "HOME";
const char binding_17[] PROGMEM = "END";
const char binding_18[] PROGMEM = "CAPS";
const char binding_19[] PROGMEM = "F1";
const char binding_20[] PROGMEM = "F2";
const char binding_21[] PROGMEM = "F3";
const char binding_22[] PROGMEM = "F4";
const char binding_23[] PROGMEM = "F5";
const char binding_24[] PROGMEM = "F6";
const char binding_25[] PROGMEM = "F7";
const char binding_26[] PROGMEM = "F8";
const char binding_27[] PROGMEM = "F9";
const char binding_28[] PROGMEM = "F10";
const char binding_29[] PROGMEM = "F11";
const char binding_30[] PROGMEM = "F12";
const char binding_31[] PROGMEM = "F13";
const char binding_32[] PROGMEM = "F14";
const char binding_33[] PROGMEM = "F15";
const char binding_34[] PROGMEM = "F16";
const char binding_35[] PROGMEM = "F17";
const char binding_36[] PROGMEM = "F18";
const char binding_37[] PROGMEM = "F19";
const char binding_38[] PROGMEM = "F20";
const char binding_39[] PROGMEM = "F21";
const char binding_40[] PROGMEM = "F22";
const char binding_41[] PROGMEM = "F23";
const char binding_42[] PROGMEM = "F24";

const char *const bindings[] PROGMEM = {
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

const int bindingsSum PROGMEM = ARR_SIZE(key_codes);  //number of all bindings
const int bindingMaxSize PROGMEM = ARR_SIZE(binding_8); //size of the longest binding