#include "macrosengine/macrosengine.hpp"
#ifdef HID_ENABLED
#include "macrosengine/default_macros.h"
#include "extendedHID/Consumer2.h"
#include "helpers/helpers.h"
#include "profiles.hpp"
const int defaultProfilesSum = (PROFILES ? (dp_num / (BUTTON_SUM - 1)) : 1);
macrosengine MA;

/** @brief Initialize components used by macrosengine */
void macrosengine::begin()
{
    Keyboard.begin();
    Mouse.begin();
#if SD_ENABLED
    sd.begin();
#endif
}

/**
 * @brief Destroy the macrosengine::macrosengine object */
macrosengine::~macrosengine()
{
    Keyboard.end();
    Mouse.end();
}

/**
 * @brief Find the corresponding code for modifier key from "basic_key_codes.h"
 *
 * @param word to find inside basic_key_codes.h
 * @return The modifier key's integer value
 */
int macrosengine::findKey(char *word)
{
    using namespace basicKeys;
    char buf[bindingMaxSize];
    LOG(2,"Got basicKey:",word);
    for (int i = 0; i < bindingsSum; i++)
    {
        strcpy_P(buf, RETRIEVE_PROFILE(bindings, i)); // retrieve current string from progmem
        if (!strcasecmp(buf, word))                   // if str1==str2 then strcmp returns 0
        {
            return intfromPROGMEM(key_codes, i); // retrieve key's code from progmem
        }
    }
    return -1;
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
 * @brief Convert given word to a mouse action.
 * Supported keywords SCRUPx and SCRDWx where x indicates the pixels to scroll (1-127)
 * @param word String to analyze and execute
 * @return int Returns -1 if keyword isn't a mouse action
 */
int macrosengine::mouseAction(char *word)
{
    // scroll command size is >5
    int wordlen = strlen(word);
    int up = -1;
    if (wordlen >= 5)
    {
        char buf[4];
        strncpy_T(buf, word, 3);
        if (!strcmp(buf, "SCR"))
        {
            strncpy_T(buf, &word[3], 2);
            if (!strcmp(buf, "UP"))
                up = 1;
            else if (!strcmp(buf, "DW"))
                up = 0;
            else
                return up;
            LOG(1,"Scroll action detected!");
            int scrval = atoi(&word[5]);
            if (scrval >= 0 && scrval <= 127)
                mouseScroll(up, scrval);
        }
    }
    return up;
}

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
 * @brief Returns the position of the default_profiles array corresponding to the button pressed and the profile selected.
 * If profiles are enabled the total number of buttons is -1.
 * @param profile_id the currently selected profile
 * @param button_id the pressed button
 */
inline int macrosengine::findMacroID(int profile_id, int button_id)
{
    return (((PROFILES ? BUTTON_SUM - 1 : BUTTON_SUM) * profile_id) + (button_id));
}

/**
 * @brief Splits the given char* array. Then executes the given macros.
 *
 * @param *macro A char* containing the keys which are going to be pressed.
 */
void macrosengine::executeMacro(char *macro, bool releaseOneByOne)
{
    int token_length = 0, key;
    LOG(2,"Macro loaded:",macro);
    char *token = strtok(macro, "+");
    while (token != NULL)
    {
        token_length = strlen(token);
        key = -1;
        if (token_length == 1) // convert char to int
        {
            key = tolower(*token);
        }
        else if (token_length > 1) // convert modifier keys
        {
            if (mouseAction(token) == -1) // if mouse action isn't found
                key = findKey(token);     // execute a basic keyboard command
        }

        LOG(2, "Token is:", token, " with length of :", token_length, " and an integer value of: ", key);
        if (key != -1)
            Keyboard.press(key);
        if (releaseOneByOne)
            Keyboard.releaseAll();
        token = strtok(NULL, "+");
    }
    Keyboard.releaseAll();
}

/**
 * @brief Find and Press the corresponding keycode for the extra keys from "extra_key_codes.h".
 *
 * @param If keycode is found returns true.
 */
bool macrosengine::processExtraKey(char *key)
{

    using namespace extraKeys;
    LOG(2,"Got extraKey:",key);
    char buf[bindingMaxSize];
    for (int i = 0; i < bindingsSum; i++)
    {
        strcpy_P(buf, RETRIEVE_PROFILE(bindings, i)); // retrieve current string from progmem
        if (!strcasecmp(buf, key))                   // if str1==str2 then strcmp returns 0
        {
            Consumer.write(key_codes[i]);
            return true;
        }
    }
    return false;
}

/**
 * @brief Reads,analyzes and executes all the supported macro types (see README).
 * Extra info:
 * If sd card is enabled then loadDefaults should be set to 0 to try load sd card macros first.
 * If profiles are disabled profileId should be 0.
 * @param buttonId The currently selected profile
 * @param profileId The button pressed
 * @param loadDefaults True to load the default profiles/False load from sd.(if sd card is not enabled this parameter doesn't do anything)
 */
void macrosengine::parseMacro(int buttonId, int profileId, bool loadDefaults)
{
    char str[MACRO_MAX_SIZE], check[MACRO_COMMAND_SIZE + 1];
    if (!SD_ENABLED) // if sd card is disabled only default profiles can be loaded
        loadDefaults = 1;
#if SD_ENABLED
    else // check if file can be read
    {
        if (!sd.checkConnection())
            loadDefaults = 1;
    }
#endif
    // first start by checking if a macro command exists
    if (loadDefaults)
        strncpy_PT(check, RETRIEVE_PROFILE(defaultMacros, findMacroID(profileId, buttonId)), MACRO_COMMAND_SIZE);
#if SD_ENABLED
    else
        strncpy_T(check, sd.readLine(findMacroID(profileId, buttonId)), MACRO_COMMAND_SIZE); // load from micro sd
#endif

    if (check[MACRO_COMMAND_SIZE - 1] == ',') // macro contains macro command , remove command from macro
    {
        if (loadDefaults) // read from progmem
            strcpy_P(str, RETRIEVE_PROFILE(defaultMacros, findMacroID(profileId, buttonId)) + MACRO_COMMAND_SIZE);
#if SD_ENABLED
        else // read from micro_sd
            strncpy_T(str, sd.readLine(findMacroID(profileId, buttonId)) + MACRO_COMMAND_SIZE, MACRO_MAX_SIZE);
#endif
        switch (toupper(check[0]))
        {
        case 'W': // paste following string
            LOG(2, "W macro loaded", str);
            Keyboard.print(str);
            break;
        case 'R': // open windows program
            keyboardMacro(2, KEY_RIGHT_GUI, 'r');
            LOG(2, "R macro loaded", str);
            delay(50);
            Keyboard.println(str);
            break;
        case 'O': // press keys one by one
            LOG(2, "O macro loaded", str);
            executeMacro(str, true);
            break;
        case 'E': // press extra keys
            LOG(2, "E macro loaded", str);
            processExtraKey(str);
            break;
        case 'P': // change profile
            LOG(2, "P macro loaded", str);
            processProfile(str);
            break;
        }
    }
    else // macro doesn't contain macro command
    {
        if (loadDefaults)
            strcpy_P(str, RETRIEVE_PROFILE(defaultMacros, findMacroID(profileId, buttonId)));
#if SD_ENABLED
        else
            strncpy_T(str, sd.readLine(findMacroID(profileId, buttonId)), MACRO_MAX_SIZE);
#endif
        executeMacro(str);
    }
}
#endif