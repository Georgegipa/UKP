#include <Arduino.h>
#include <string.h>
#include "Keyboard.h"
#define BIND_MAX_SIZE 12
#define MAX_BINDINGS 47

//removed KEYS_ to save space
char key_bindings[MAX_BINDINGS][BIND_MAX_SIZE] =
    {
        "LEFT_CTRL",
        "LEFT_SHIFT",
        "LEFT_ALT",
        "LEFT_GUI",
        "RIGHT_CTRL",
        "RIGHT_SHIFT",
        "RIGHT_ALT",
        "RIGHT_GUI",
        "UP_ARROW",
        "DOWN_ARROW",
        "LEFT_ARROW",
        "RIGHT_ARROW",
        "BACKSPACE",
        "TAB",
        "RETURN",
        "ESC",
        "INSERT",
        "DELETE",
        "PAGE_UP",
        "PAGE_DOWN",
        "HOME",
        "END",
        "CAPS_LOCK",
        "F1",
        "F2",
        "F3",
        "F4",
        "F5",
        "F6",
        "F7",
        "F8",
        "F9",
        "F10",
        "F11",
        "F12",
        "F13",
        "F14",
        "F15",
        "F16",
        "F17",
        "F18",
        "F19",
        "F20",
        "F21",
        "F22",
        "F23",
        "F24"};

int key_codes[MAX_BINDINGS] =
    {
        KEY_LEFT_CTRL,
        KEY_LEFT_SHIFT,
        KEY_LEFT_ALT,
        KEY_LEFT_GUI,
        KEY_RIGHT_CTRL,
        KEY_RIGHT_SHIFT,
        KEY_RIGHT_ALT,
        KEY_RIGHT_GUI,
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

int find_key(char *word)
{
    for (int i = 0; i < MAX_BINDINGS; i++)
    {
        if (strstr(word,key_bindings[i])!=NULL)
        {
            return key_codes[i];
        }
    }
    return -1;
}
