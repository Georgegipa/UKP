#include "UKPmanager.hpp"
#include "macrosengine.hpp"

UKPmanager UKP;

void UKPmanager::init()
{
    Serial.begin(9600);
    MA.init();//start macrosengine, also loads sd card
    out.init(9);
    seg.init();
    //disable the builtin leds
#if KILL_SWITCH
    pinMode(KILL_SWITCH, INPUT);
#endif
#if BUILTIN_LEDS_ENABLED == 0
    pinMode(LED_BUILTIN_RX, INPUT);
    pinMode(LED_BUILTIN_TX, INPUT);
#endif
#if PROFILES
    last_profile_state = current_profile;
    seg.displayProfile(current_profile);
    current_profile = 0;
    
#endif
#if DEBUG
    while (!Serial)
        ; //wait for serial
    if (KILL_SWITCH)
    {
        Serial.print("Kill switch enabled on pin:");
        Serial.println(KILL_SWITCH);
    }
    Serial.print("Number of buttons intialized:");
    Serial.println(button::numofbuttons);
    Serial.print("Number of profiles intialized:");
    Serial.println(default_profiles_num);
#endif
}

#if PROFILES
void UKPmanager::profile_changed()
{
#if DEBUG
    Serial.print(F("Current Profile changed to: "));
    Serial.println(current_profile);
#endif
    last_profile_state = current_profile;
    out.flashing(current_profile + 1);
    seg.displayProfile(current_profile);
}
#endif

UKPmanager::~UKPmanager()
{
#if INTERRUPTS_ENABLED
    for (int i = 0; i < BUTTONS; i++)
    {
        btn[i].~button();
    }
#endif
}

void UKPmanager::manageButtonMacros(int &button_pin)
{
    //if button isn't profile button , or profiles are  disabled , then execute macro
    if (button_pin || (!PROFILES))
        MA.ParseMacro(current_profile, button_pin - (IF_TRUE(PROFILES)));
    else
    { //change profile
        if (current_profile < default_profiles_num - 1)
            current_profile++;
        else
            current_profile = 0;
    }
}

void UKPmanager::runtime()
{
    for (int i = 0; i < BUTTONS; i++)
    {
#if KILL_SWITCH
        //kill switch must set high in order to allow macros
        if (!digitalRead(KILL_SWITCH))
        {
            out.setHigh();
            continue;
        }
        else
        {
            out.setLow();
        }
#endif
        pin_triggered = btn[i].state();
        if (pin_triggered != -1)
            manageButtonMacros(pin_triggered);
    }
#if PROFILES
    if (last_profile_state != current_profile)
        profile_changed();
#endif
}
