#include "UKPmanager.hpp"
#include "macrosengine.hpp"

UKPmanager UKP;

void UKPmanager::begin()
{
    Serial.begin(9600);
    MA.begin();//start macrosengine, also loads sd card
    out.begin(9);
    seg.begin();
    //disable the builtin leds
#if KILL_SWITCH
    pinMode(KILL_SWITCH, INPUT);
#endif
#if BUILTIN_LEDS_ENABLED == 0
    pinMode(LED_BUILTIN_RX, INPUT);
    pinMode(LED_BUILTIN_TX, INPUT);
#endif
#if PROFILES
    lastProfileState = currentProfile;
    seg.displayProfile(currentProfile);
    currentProfile = 0;
    
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
    Serial.println(button::buttonSum);
    Serial.print("Number of profiles intialized:");
    Serial.println(defaultProfilesSum);
#endif
}

#if PROFILES
void UKPmanager::profileChanged()
{
#if DEBUG
    Serial.print(F("Current Profile changed to: "));
    Serial.println(currentProfile);
#endif
    lastProfileState = currentProfile;
    out.flashing(currentProfile + 1);
    seg.displayProfile(currentProfile);
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
        MA.parseMacro(currentProfile, button_pin - (IF_TRUE(PROFILES)));
    else
    { //change profile
        if (currentProfile < defaultProfilesSum - 1)
            currentProfile++;
        else
            currentProfile = 0;
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
        pinTriggered = btn[i].state();
        if (pinTriggered != -1)
            manageButtonMacros(pinTriggered);
    }
#if PROFILES
    if (lastProfileState != currentProfile)
        profileChanged();
#endif
}