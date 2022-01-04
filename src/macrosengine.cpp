#include "macrosengine.hpp"
#include "helpers.h"
#include "config/default_profiles.h"
#define RETRIEVE_PROFILE(POS) (char *)pgm_read_word(&(default_profiles[POS]))
const int default_profiles_num = (PROFILES ? (dp_num / (BUTTONS - 1)) : 1);
macrosengine MA;

void macrosengine::init()
{
    Keyboard.begin();
    Mouse.begin();
#if MICRO_SD_ENABLED
    sd.init();
#endif
}

macrosengine::~macrosengine()
{
    Keyboard.end();
    Mouse.end();
}

/**
 * @brief Find the corresponding code for modifier key from "extra_button_codes.h"
 * 
 * @param word to find inside extra_button_codes.h
 * @return The modifier key's integer value
 */
int macrosengine::find_key(char *word)
{
    char buf[binding_max_size];
    int res;
#if DEBUG
    Serial.print(F("Got:"));
    Serial.println(word);
#endif
    for (int i = 0; i < num_of_bindings; i++)
    {
        strcpy_P(buf, (char *)pgm_read_word(&(bindings[i]))); //retrieve current string from progmem
        res = strcmp(buf, word);                              //if str1==str2 then strcmp returns 0
        if (!res)
        {
            return intfromPROGMEM(key_codes, i); //retrieve key's code from progmem
        }
    }
    return -1;
}

void macrosengine::KeyboardMacro(int num_args, ...)
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
 * @param profile_id the currnetly selected profile
 * @param button_id the pressed button
 */
inline int macrosengine::findMacroID(int profile_id, int button_id)
{
    return (((PROFILES ? BUTTONS - 1 : BUTTONS) * profile_id) + (button_id));
}

/**
 * @brief Splits the given array. Then executes the given macros.
 * 
 * @param *macro A char* containing the keys which are going to be pressed.
 */
void macrosengine::ExecuteMacro(char *macro)
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
        if (token_length == 1) //convert char to int and then press button
        {
            key = toLowerCase(*token);
        }
        else if (token_length > 1) //convert modifier keys
        {
            key = find_key(token);
        }

#if DEBUG
        Serial.print("Token is:");
        Serial.print(token);
        Serial.print(" with lenght of :");
        Serial.print(token_length);
        Serial.print(" and an integer value of: ");
        Serial.println(key);
#endif
        if (key != -1)
            Keyboard.press(key);
        token = strtok(NULL, "+");
    }
    Keyboard.releaseAll();
}

/**
 * @brief Reads,analyzes and executes all the supported macro types (see README).
 * 
 * @param profile_id The currently selected profile
 * @param button_id The button pressed
 * @param load_default_profile True to load the default profiles/False load from sd.(if sd card is not enabled this parameter doesn't do anything)
 */
void macrosengine::ParseMacro(int profile_id, int button_id, bool load_defaults)
{
    char str[MACRO_MAX_SIZE], check[MACRO_COMMAND_SIZE + 1];
    if (!MICRO_SD_ENABLED) //if sd card is disabled only default profiles can be loaded
        load_defaults = 1;
    else //check if file can be read
        ;
    //first start by checking if a macro command exists
    if (load_defaults)
        strncpy_P(check, RETRIEVE_PROFILE(findMacroID(profile_id, button_id)), MACRO_COMMAND_SIZE);
#if MICRO_SD_ENABLED
    else
        strncpy(check, sd.readLine(findMacroID(profile_id, button_id)), MACRO_COMMAND_SIZE); //load from micro sd
#endif
    str[MACRO_COMMAND_SIZE] = '\0';

    if (check[MACRO_COMMAND_SIZE - 1] == ',') //macro contains macro command , remove command from macro
    {
        if (load_defaults) //read from progmem
            strcpy_P(str, RETRIEVE_PROFILE(findMacroID(profile_id, button_id)) + MACRO_COMMAND_SIZE);
        else // read from micro_sd
            strncpy(str,sd.readLine(findMacroID(profile_id, button_id))+ MACRO_COMMAND_SIZE,MACRO_MAX_SIZE);
        switch (check[0])
        {
        case 'P': //paste following string
#if DEBUG
            Serial.print("Entering text:");
            Serial.println(str);
#endif
            Keyboard.print(str);
            break;
        case 'W': //open windows programm
            KeyboardMacro(2, KEY_RIGHT_GUI, 'r');
#if DEBUG
            Serial.print("WIN+R:");
            Serial.println(str);
#endif
            delay(30);
            Keyboard.println(str);
            break;
        }
    }
    else //macro doesn't contain macro command
    {
        if (load_defaults)
            strcpy_P(str, RETRIEVE_PROFILE(findMacroID(profile_id, button_id)));
        else 
            strncpy(str,sd.readLine(findMacroID(profile_id, button_id)),MACRO_MAX_SIZE);
        ExecuteMacro(str);
    }
}