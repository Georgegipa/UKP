#ifdef HID_ENABLED
#include "macrosengine/macrosengine.hpp"
#include "macrosengine/default_macros.h"
#include "extendedHID/Consumer2.h"
#include "helpers.h"
const int defaultProfilesSum = (PROFILES ? (dp_num / (BUTTONS - 1)) : 1);
macrosengine MA;

void macrosengine::begin()
{
    Keyboard.begin();
    Mouse.begin();
#if SD_ENABLED
    sd.begin();
#endif
}

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
#if DEBUG
    Serial.print(F("Got basicKey:"));
    Serial.println(word);
#endif
    for (int i = 0; i < bindingsSum; i++)
    {
        strcpy_P(buf, (char *)pgm_read_word(&(bindings[i]))); // retrieve current string from progmem
        if (!strcmp(buf, word))                               // if str1==str2 then strcmp returns 0
        {
            return intfromPROGMEM(key_codes, i); // retrieve key's code from progmem
        }
    }
    return -1;
}

/**
 * @brief Find the corresponding code for the extra keys from "extra_key_codes.h"
 *
 * @param word to find inside extra_key_codes.h
 * @return The modifier key's integer value
 */
//TODO: Clean up extra_key_codes.h
ConsumerKeycode macrosengine::findExtraKey(char *word)
{
    using namespace extraKeys;
#if DEBUG
    Serial.print(F("Got extraKey:"));
    Serial.println(word);
#endif
    char buf[bindingMaxSize];
    for (int i = 0; i < bindingsSum; i++)
    {
        strcpy_P(buf, (char *)pgm_read_word(&(bindings[i]))); // retrieve current string from progmem
        if (!strcmp(buf, word))                               // if str1==str2 then strcmp returns 0
        {
            return key_codes[i];
        }
    }
    return HID_CONSUMER_UNASSIGNED;
}

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
 * @brief Returns the position of the default_profiles array corres corresponding to the button pressed and the profile selected.
 * If profiles are enabled the total number of buttons is -1.
 * @param profile_id the currently selected profile
 * @param button_id the pressed button
 */
inline int macrosengine::findMacroID(int profile_id, int button_id)
{
    return (((PROFILES ? BUTTONS - 1 : BUTTONS) * profile_id) + (button_id));
}

/**
 * @brief Splits the given char* array. Then executes the given macros.
 *
 * @param *macro A char* containing the keys which are going to be pressed.
 */
void macrosengine::executeMacro(char *macro, bool releaseOneByOne)
{
    int token_length = 0, key;
#if DEBUG
    Serial.print(F("Macro loaded:"));
    Serial.println(macro);
#endif
    char *token = strtok(macro, "+");
    while (token != NULL)
    {
        token_length = strlen(token);
        key = -1;
        if (token_length == 1) // convert char to int
        {
            key = toLowerCase(*token);
        }
        else if (token_length > 1) // convert modifier keys
        {
            key = findKey(token);
        }

#if DEBUG
        Serial.print("Token is:");
        Serial.print(token);
        Serial.print(" with length of :");
        Serial.print(token_length);
        Serial.print(" and an integer value of: ");
        Serial.println(key);
#endif
        if (key != -1)
            Keyboard.press(key);
        if (releaseOneByOne)
            Keyboard.releaseAll();
        token = strtok(NULL, "+");
    }
    Keyboard.releaseAll();
}

void macrosengine::executeExtraKey(char *key)
{
    ConsumerKeycode keyCode = findExtraKey(key);
    if(keyCode!=HID_CONSUMER_UNASSIGNED)
    Consumer.write(keyCode);
}

/**
 * @brief Reads,analyzes and executes all the supported macro types (see README).
 *
 * @param buttonId The currently selected profile
 * @param profileId The button pressed
 * @param loadDefaults True to load the default profiles/False load from sd.(if sd card is not enabled this parameter doesn't do anything)
 */
void macrosengine::parseMacro(int profileId, int buttonId, bool loadDefaults)
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
        strncpy_P(check, RETRIEVE_PROFILE(findMacroID(profileId, buttonId)), MACRO_COMMAND_SIZE);
#if SD_ENABLED
    else
        strncpy(check, sd.readLine(findMacroID(profileId, buttonId)), MACRO_COMMAND_SIZE); // load from micro sd
#endif
    str[MACRO_COMMAND_SIZE] = '\0';

    if (check[MACRO_COMMAND_SIZE - 1] == ',') // macro contains macro command , remove command from macro
    {
        if (loadDefaults) // read from progmem
            strcpy_P(str, RETRIEVE_PROFILE(findMacroID(profileId, buttonId)) + MACRO_COMMAND_SIZE);
#if SD_ENABLED
        else // read from micro_sd
            strncpy(str, sd.readLine(findMacroID(profileId, buttonId)) + MACRO_COMMAND_SIZE, MACRO_MAX_SIZE);
#endif
        switch (check[0])
        {
        case 'P': // paste following string
#if DEBUG
            Serial.print("Entering text:");
            Serial.println(str);
#endif
            Keyboard.print(str);
            break;
        case 'W': // open windows program
            keyboardMacro(2, KEY_RIGHT_GUI, 'r');
#if DEBUG
            Serial.print("WIN+R:");
            Serial.println(str);
#endif
            delay(30);
            Keyboard.println(str);
            break;
        case 'O': // press keys one by one
#if DEBUG
            Serial.print("Pressing the following keys one by one");
            Serial.println(str);
#endif
            executeMacro(str, true);
            break;
        case 'E': // press extra keys
            executeExtraKey(str);
            break;
        }
    }
    else // macro doesn't contain macro command
    {
        if (loadDefaults)
            strcpy_P(str, RETRIEVE_PROFILE(findMacroID(profileId, buttonId)));
#if SD_ENABLED
        else
            strncpy(str, sd.readLine(findMacroID(profileId, buttonId)), MACRO_MAX_SIZE);
#endif
        executeMacro(str);
    }
}
#endif