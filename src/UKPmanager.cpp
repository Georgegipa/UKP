#include "UKPmanager.hpp"

UKPmanager UKP;

void UKPmanager::init()
{
    Serial.begin(9600);
    out.init(10);
    seg.init();
    //disable the builtin leds
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
        btn[i].state();
    }
#if PROFILES
    if (last_profile_state != current_profile)
        profile_changed();
#endif
}
