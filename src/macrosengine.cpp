#include "macrosengine.hpp"
#include "options.hpp"
#include "helper_functions.h"

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
#if DEBUG_OPTIONS_ENABLED
    Serial.print(F("Got:"));
    Serial.println(word);
#endif
    for (int i = 0; i < num_of_bindings; i++)
    {
        strcpy_P(buf, (char *)pgm_read_word(&(bindings[i]))); //retrieve current string from progmem
        res = strcmp(buf, word);                              //if str1==str2 then strcmp returns 0
#if 0
        Serial.print("Key code: ");
        Serial.print(code);
        Serial.print(F(" ,strcmp:"));
        Serial.print(res); //print strcmp result
        Serial.print(F(" key: "));
        Serial.println(buf);
#endif
        if (!res)
        {
            return pgm_read_byte(key_codes + i); //retrieve key's code from progmem
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

void macrosengine::ExecuteMacro(int profile_id, int button_id)
{
    char str[MACRO_MAX_SIZE];
    strcpy(str, profiles[profile_id][button_id]);

    int token_length = 0, key;

    Serial.print(F("Macro loaded:"));
    Serial.println(str);
    char *token = strtok(str, "+");
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

#if DEBUG_OPTIONS_ENABLED
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