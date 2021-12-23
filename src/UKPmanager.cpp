#include "UKPmanager.hpp"

UKPmanager UKP;

void UKPmanager::init()
{
    Serial.begin(9600);
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
    Serial.println(num_of_profiles);
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
        btn[i].state();
    }
#if PROFILES
    if (last_profile_state != current_profile)
        profile_changed();
#endif
}
