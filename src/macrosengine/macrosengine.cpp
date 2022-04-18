#include "macrosengine/macrosengine.hpp"
#ifdef HID_ENABLED
#include "extendedHID/Consumer2.h"
#include "profiles.hpp"
macrosengine MA;

/** @brief Initialize components used by macrosengine */
void macrosengine::begin()
{
    stickyKeys = 0;
    Keyboard.begin();
    Mouse.begin();
}

/**
 * @brief Destroy the macrosengine::macrosengine object */
macrosengine::~macrosengine()
{
    Keyboard.end();
    Mouse.end();
    Consumer.end();
}

/**
 * @brief A variadic function that takes num_args followed by the keys that are going to be pressed
 *
 * @param num_args The number of keys which are going to be pressed.
 * @param ... A number of num_args which are going to be pressed.
 */
void macrosengine::keyboardMacro(int num_args, ...)
{
    va_list args;
    va_start(args, num_args);
    for (int i = 0; i < num_args; i++)
    {
        Keyboard.press(va_arg(args, int));
    }
    va_end(args);
    Keyboard.releaseAll();
}

/**
 * @brief Find the corresponding keycode for modifier key from "basic_key_codes.h"
 *
 * @param word to find inside basic_key_codes.h
 * @return The modifier key's integer value
 */
int macrosengine::findKey(char *word)
{
    using namespace basicKeys;
    char buf[bindingMaxSize];
    if (toupper(word[0]) == 'F') // check if word is a F key
    {
        strncpy(word, word + 1, strlen(word));
        int fkey = atoi(word);
        switch (atoi(word))
        {
        case 1 ... 12: // for f1 to f12 keys keycode is equal to fkey + F1
            return KEY_F1 + fkey - 1;
        case 13 ... 24: // for f13 to f24 keys keycode is equal to fkey + F13
            return KEY_F13 + fkey - 13;
        default:
            return -1;
        }
    }
    else
    {
        for (int i = 0; i < bindingsSum; i++)
        {
            strcpy_P(buf, RETRIEVE_PROFILE(bindings, i)); // retrieve current string from progmem
            if (!strcasecmp(buf, word))                   // if str1==str2 then strcmp returns 0
            {
                return intfromPROGMEM(key_codes, i); // retrieve key's code from progmem
            }
        }
    }
    return -1;
}

/**
 * @brief Return the keycode of the key if it exists in "extra_key_codes.h"
 *
 * @param key The macro to find inside extra_key_codes.h
 * @return ConsumerKeycode if key exists, else return ConsumerKeycode::KEY_NOT_FOUND
 */
ConsumerKeycode macrosengine::findExtraKey(char *key)
{
    using namespace extraKeys;
    char buf[bindingMaxSize];
    for (int i = 0; i < bindingsSum; i++)
    {
        strcpy_P(buf, RETRIEVE_PROFILE(bindings, i)); // retrieve current string from progmem
        if (!strcasecmp(buf, key))                    // if str1==str2 then strcmp returns 0
            return key_codes[i];
    }
    return HID_CONSUMER_UNASSIGNED;
}


/**
 * @brief Check if given word is a mouse action
 * @param word String to analyze
 * @return bool Returns true if word is a mouse action
 */
bool macrosengine::isMouseAction(char *word)
{
    int wordlen = strlen(word); // scroll command size is >5
    if (wordlen >= 5)
    {
        char buf[4];
        strncpy_T(buf, word, 3);
        if (!strcasecmp(buf, "SCR"))
        {
            if (toupper(word[3]) == 'U' || toupper(word[3]) == 'D')
            {
                int scrval = atoi(&word[4]);

                if (scrval >= 0 && scrval <= 127)
                    return true;
            }
        }
    }
    return false;
}

/**
 * @brief Convert given word to a mouse action.
 * Supported keywords SCRUPx and SCRDWx where x indicates the pixels to scroll (1-127)
 * @param word String to analyze and execute
 * @return int Returns -1 if keyword isn't a mouse action
 */
int macrosengine::mouseAction(char *word)
{
    int up = -1;
    SSprintf("Got mouseAction:%s\n", word);
    if (isMouseAction(word))
    {
        if (toupper(word[3]) == 'U')
            up = 1;
        else if (toupper(word[3]) == 'D')
            up = 0;
        else
            return up;
        SSprintf("Scroll action detected!\n");
        mouseScroll(up, atoi(&word[4]));
    }
    return up;
}

/**
 * @brief Select how much to scroll up or down.
 *
 * @param up Set this to true to scroll up, or false to scroll down.
 * @param val Set the amount of scrolling.
 */
inline void macrosengine::mouseScroll(bool up, int val)
{
    Mouse.move(0, 0, up ? val : val * -1);
}


/**
 * @brief Process profile commands.
 *
 * @param word String to analyze and execute.
 */
void macrosengine::processProfile(char *word)
{
#if PROFILES
    int len = strlen(word);
    if (len == 1)
    {
        switch (word[0])
        {
        case '+':
            Profile++;
            break;
        case '-':
            Profile--;
            break;
        case '0' ... '9':
            Profile[atoi(word)];
            break;
        default:
            return;
        }
    }
    else
    {
        len = atoi(word);
        if (len > 0)
            Profile[len];
    }
#endif
}

/**
 * @brief Press Once or Hold key based on their type.
 *
 * @param type The type of the key.
 * @param behavior If the key should be pressed or held.
 */
void macrosengine::extraAction(macrosengine::KeyCodeType type, macrosengine::KeyBehavior behavior)
{
    if (type == BASIC_KEY_CODE)
    {
        SSprintf("Key val:%d\n", keyCode.keyboardCode);
        switch (behavior)
        {
        case KEEP_PRESSED:
        case WAIT_FOR_ALL_KEYS:
            Keyboard.press(keyCode.keyboardCode);
            break;
        case PRESS_ONCE:
            Keyboard.press(keyCode.keyboardCode);
            Keyboard.releaseAll();
            break;
        default:
            break;
        }
    }
    else if (type == EXTRA_KEY_CODE)
    {
        SSprintf("Key val:%u\n", keyCode.consumerCode);
        switch (behavior)
        {
        case KEEP_PRESSED:
        case WAIT_FOR_ALL_KEYS:
            Consumer.press(keyCode.consumerCode);
            break;
        case PRESS_ONCE:
            Consumer.write(keyCode.consumerCode);
            break;
        default:
            break;
        }
    }
    else
        return;
}

/**
 * @brief Splits the given char* array. Then executes the given macros.
 *
 * @param *macro A char* containing the keys which are going to be pressed.
 * @param extraActions control extra behavior
 *  * 0, hold all keys and release all them once the macro is read
 *  * 1, press and release a key when its recognized.
 *  * 2, hold a key until clearStickyKeys is called again.
 */
void macrosengine::executeMacro(char *macro, macrosengine::KeyBehavior extraActions)
{
    int media_keys_pressed = 0;
    SSprintf("Macro loaded:%s\n", macro);
    char *token = strtok(macro, "+");
    while (token)
    {
        KeyCodeType type = findKeyCodeType(token);
        switch (type)
        {
        case BASIC_KEY_CODE:
            SSprintf("Got basicKey:%s\n", token);
            break;
        case EXTRA_KEY_CODE:
            SSprintf("Got extraKey:%s\n", token);
            media_keys_pressed++;
            if (media_keys_pressed >= 4) // consumer api can only send up to 4 media keys
                type = KEY_NOT_FOUND;
            break;
        case MOUSE_ACTION:
            mouseAction(token);
            break;
        default:
            break;
        }

        extraAction(type, extraActions);
        token = strtok(NULL, "+");
    }

    if (extraActions == WAIT_FOR_ALL_KEYS) // release all buttons when macro is fully read
    {
        Keyboard.releaseAll();
        Consumer.releaseAll();
    }
    else if (extraActions == KEEP_PRESSED)
        stickyKeys = true;
}

/**
 * @brief Release Keys been held from H macrocommand.
 */
void macrosengine::clearStickyKeys()
{
    Keyboard.releaseAll();
    Consumer.releaseAll();
    stickyKeys = 0;
    SSprintf("Sticky Keys cleared!\n");
}

macrosengine::KeyCodeType macrosengine::findKeyCodeType(char *word)
{
    int word_length = strlen(word);
    int key = -1;
    SSprintf("Token is:%s with length of :%d\n", word, word_length);
    // check if word is on the ascii table between 32 and 126
    if (word_length == 1 && (word[0] >= 32 && word[0] <= 126))
    {
        // if word is capitalized, the convert it to lowercase
        if (isupper(word[0]))
            word[0] = tolower(word[0]);
        keyCode.keyboardCode = word[0];
        return BASIC_KEY_CODE;
    }
    else if (word_length >= 4) // convert modifier keys
    {
        // check if word is a media key
        ConsumerKeycode temp = findExtraKey(word);
        if (temp != HID_CONSUMER_UNASSIGNED)
        {
            keyCode.consumerCode = temp;
            return EXTRA_KEY_CODE;
        }
        // check if word is a mouse action
        else if (isMouseAction(word))
        {
            return MOUSE_ACTION;
        }
    }
    // after all checks, check if word is a keyboard key
    if (key == -1)
        key = findKey(word); // check if word is a basic keyboard command
    // check if word exists as a basic key
    if (key >= 0)
    {
        keyCode.keyboardCode = key;
        return BASIC_KEY_CODE;
    }
    return KEY_NOT_FOUND;
}

void macrosengine::parseMacro(char *macro)
{
    if (macro[0] == 0)
        return;
    switch (getMacroCommand(macro))
    {
    case 'W': // paste following string
        macroCommand(macro);
        Keyboard.print(macro);
        break;
    case 'R': // open windows program
        keyboardMacro(2, KEY_RIGHT_GUI, 'r');
        macroCommand(macro);
        delay(50);
        Keyboard.println(macro);
        break;
    case 'O': // press keys one by one
        macroCommand(macro);
        executeMacro(macro, KeyBehavior::PRESS_ONCE);
        break;
    case 'P': // change profile
        macroCommand(macro);
        processProfile(macro);
        break;
    case 'H': // hold keys
        macroCommand(macro);
        executeMacro(macro, KeyBehavior::KEEP_PRESSED);
        break;
    case 1: // macro doesn't contain macro command
        executeMacro(macro);
        break;
    }
}

// Remove macro command from macro
void macrosengine::macroCommand(char *macro)
{
    char temp = toupper(macro[0]);
    strncpy_T(macro, &macro[MACRO_COMMAND_SIZE], strlen(macro) - MACRO_COMMAND_SIZE);
    SSprintf("%c macro command: %s\n", temp, macro);
}

void macrosengine::KeyboardPrint(char *word)
{
    Keyboard.print(word);
}

// Return the macro command from macro if it's found or 1 if not found(default macro)
inline char macrosengine::getMacroCommand(char *macro)
{
    return (macro[MACRO_COMMAND_SIZE - 1] == ',') ? toupper(macro[0]) : 1;
}

bool macrosengine::isMacroCommand(char *macro)
{
    if (getMacroCommand(macro) == 1)
        return false;
    switch (toupper(macro[0]))
    {
    case 'W':
    case 'R':
    case 'O':
    case 'P':
    case 'H':
        return true;
    default:
        return false;
    }
}

#endif