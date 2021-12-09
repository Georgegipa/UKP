#include "extra_button_codes.h"
#include <Mouse.h>

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

/* void KeyboardMacro(int keys[])
{
    //determine the number of elements
    int len= sizeof(keys)/sizeof(keys[0]);
    for(int i=0; i< len ; i++){
        Keyboard.press(keys[i]);
    }
    Keyboard.releaseAll();
}
 */


//to do add a limit of 6 max tokens
int *MacroParser(char *str)
{
    static int tokens[6];//number of max keys that can be pressed at the same time
    int token_length = 0, len = 0;
    memset(tokens, 0, sizeof(tokens));
    Serial.print("Got string:");
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

        //add the ascii code of the button to be pressed
        if (token_length == 1)
            tokens[len] = (int)*token;
        else if (token_length > 1) //convert modifier keys
        {
            int key = find_key(token);
            if (key != -1)
                tokens[len] = key;
        }
        token = strtok(NULL, "+");
        len++;
    }
#if DEBUG_OPTIONS_ENABLED
    Serial.print("Macro's len is: ");
    Serial.println(len);
    for (int i = 0; i < 6 ; i++)
    {
        Serial.println(tokens[i]);
    }
#endif

    return tokens;
}
