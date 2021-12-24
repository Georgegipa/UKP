#include "macrosengine.hpp"
#include "helpers.h"
#include "config/definitions.h"
#include "config/default_profiles.h"
#define RETRIEVE_PROFILE(POS) (char *)pgm_read_word(&(default_profiles[POS]))
const int default_profiles_num = (PROFILES ? (dp_num / (BUTTONS - 1)) : 1);
macrosengine MA;

macrosengine::macrosengine()
{
    Keyboard.begin();
    Mouse.begin();
}

macrosengine::~macrosengine()
{
    Keyboard.end();
    Mouse.end();
}

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

inline int macrosengine::findMacroID(int profile_id, int button_id)
{
    return (((PROFILES ? BUTTONS - 1 : BUTTONS) * profile_id) + (button_id));
}

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

void macrosengine::ParseMacro(int profile_id, int button_id, bool load_default_profile)
{
    char str[MACRO_MAX_SIZE + MACRO_COMMAND_SIZE];
    if (load_default_profile)
    {
        strncpy_P(str, RETRIEVE_PROFILE(findMacroID(profile_id, button_id)), MACRO_COMMAND_SIZE);
        str[MACRO_COMMAND_SIZE] = '\0';
    }
    else
        ; //load from micro sd

    if (str[MACRO_COMMAND_SIZE - 1] == ',') //macro contains macro command , remove command from macro
    {
        switch (str[0])
        {
        case 'P': //paste following string
            strcpy_P(str, RETRIEVE_PROFILE(findMacroID(profile_id, button_id)) + MACRO_COMMAND_SIZE);
#if DEBUG
            Serial.print("Entering text:");
            Serial.println(str);
#endif
            Keyboard.print(str);
            break;
        case 'W': //open windows programm
            strcpy_P(str, RETRIEVE_PROFILE(findMacroID(profile_id, button_id)) + MACRO_COMMAND_SIZE);
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
        strcpy_P(str, RETRIEVE_PROFILE(findMacroID(profile_id, button_id)));
        ExecuteMacro(str);
    }
}