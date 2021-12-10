#include "extra_button_codes.h"
#include <Mouse.h>
#include "options.hpp"

void InitActions()
{
    Keyboard.begin();
    Mouse.begin();
}

void KeyboardMacro(int num_args, ...)
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

//number of max keys is limited by MACRO_MAX_SIZE
void ExecuteMacro(int profile_id, int button_id)
{
    static char str[MACRO_MAX_SIZE];
    strcpy(str, profiles[profile_id][button_id]);

    int token_length = 0, key;

    Serial.print(F("Macro loaded:"));
    Serial.println(str);
    char *token = strtok(str, "+");
    while (token != NULL)
    {
        token_length = strlen(token);

#if DEBUG_OPTIONS_ENABLED
        Serial.print("Token is:");
        Serial.print(token);
        Serial.print(" with lenght of :");
        Serial.print(token_length);
        Serial.print(" and an integer value of: ");
        Serial.println((int)*token);
#endif
        if (token_length == 1)//convert char to int and then press button
        {
            key = (int)*token;
            Keyboard.press(key);
        }
        else if (token_length > 1) //convert modifier keys
        {
            key = find_key(token);
            if (key != -1)
            {
                Keyboard.press(key);
            }
        }
        token = strtok(NULL, "+");
    }
    Keyboard.releaseAll();
}