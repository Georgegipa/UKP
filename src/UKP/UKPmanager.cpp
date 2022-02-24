#include "UKP/UKPmanager.hpp"

#ifdef HID_ENABLED
#include "macrosengine/macrosengine.hpp"
#endif

UKPmanager manager;
/**
 * @brief Initialize all the components needed to di
 *
 */
void UKPmanager::begin()
{
    out.begin(LED_PIN); // start binary display(led and buzzer)
#ifdef HID_ENABLED
    MA.begin(); // start macrosengine, also loads sd card
#if SEVEN_SEGMENT
    seg.begin(); // start 7 segment display
#endif
    // disable the builtin leds
#ifdef KILL_SWITCH
    pinMode(KILL_SWITCH, INPUT);
#endif
#if BUILTIN_LEDS_ENABLED == 0
    pinMode(LED_BUILTIN_RX, INPUT);
    pinMode(LED_BUILTIN_TX, INPUT);
#endif
#if PROFILES
    lastProfileState = currentProfile;
#if SEVEN_SEGMENT
    seg.displayProfile(currentProfile);
#endif
    currentProfile = 0;

#endif
#endif
#if DEBUG
    while (!Serial)
        ; // wait for serial
#ifdef KILL_SWITCH
    Serial.print("Kill switch enabled on pin:");
    Serial.println(KILL_SWITCH);
#endif
    Serial.print("Number of buttons intialized:");
    Serial.println(button::buttonSum);
    Serial.print("Number of profiles intialized:");
    Serial.println(defaultProfilesSum);
#endif
}

#if PROFILES
/**
 * @brief Check if a profile has changed and update the outputs(displays, leds)
 *
 */
void UKPmanager::profileChanged()
{
#if DEBUG
    Serial.print(F("Current Profile changed to: "));
    Serial.println(currentProfile);
#endif
    lastProfileState = currentProfile;
    out.flashing(currentProfile + 1);
#if SEVEN_SEGMENT
    seg.displayProfile(currentProfile);
#endif
}
#endif

/**
 * @brief Send correct button id by checking if profiles are enabled
 * If profiles are enabled increment by 1 if profile button was pressed
 *
 * @param button_pin the button which triggered a macro
 */
void UKPmanager::manageButtonMacros(int &button_pin)
{
    // if button isn't profile button , or profiles are disabled , then execute macro
#ifdef HID_ENABLED
    if (button_pin || (!PROFILES))
    {
        //MA.parseMacro(currentProfile, button_pin - (IF_TRUE(PROFILES)));

        switch (button_pin)
        {
        case 1:
            Mouse.move(0, 0, 100);
            break;
        case 2:
            Mouse.move(0, 0, -1);
            break;
        default:
            break;
        }
    }
    else
    { // change profile
        if (currentProfile < defaultProfilesSum - 1)
            currentProfile++;
        else
            currentProfile = 0;
    }
#else
    Serial.print("->Pressed:");
    Serial.print(button_pin);
#endif
}

#ifdef KILL_SWITCH
bool UKPmanager::killSwitch()
{
    // kill switch must set high in order to allow macros
    bool killSwitchState = digitalRead(KILL_SWITCH);
    if (!killSwitchState)
        out.setHigh();
    else
        out.setLow();

    return killSwitchState;
}
#endif

void UKPmanager::runtime()
{
#ifdef KILL_SWITCH
    if (killSwitch())
#endif
    {
        auto d = Input.inputPolling();
        switch (d.type)
        {
        case type_button:
            manageButtonMacros(d.id);
            break;
        default:
            break;
        }
    }
#if PROFILES
    if (lastProfileState != currentProfile)
        profileChanged();
#endif
}
