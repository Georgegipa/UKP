#include "UKP/UKPmanager.hpp"

#ifdef HID_ENABLED
#include "macrosengine/macrosengine.hpp"
#include "DynamicInput/DynamicInput.hpp"

#ifdef APP_CONTROL
#include "scomms/scomms.hpp"
#endif

UKPmanager manager;

/**
 * @brief Initialize all the components related to UKP and are enabled in the config.h file.
 * 
 */
void UKPmanager::begin()
{
    out.begin(LED_PIN); // start binary display(led and buzzer)
    MA.begin();         // start macrosengine, also loads sd card
#ifdef APP_CONTROL
    SC.begin(BAUD_RATE);
#endif
#if PROFILES
    lastProfileState = currentProfile;
    currentProfile = 0;
#endif
#if SEVEN_SEGMENT
    seg.begin(); // start 7 segment display
    seg.displayProfile(currentProfile);
#endif
#ifdef KILL_SWITCH
    pinMode(KILL_SWITCH, INPUT);
#endif
#if BUILTIN_LEDS_ENABLED == 0 // disable the builtin leds
    pinMode(LED_BUILTIN_RX, INPUT);
    pinMode(LED_BUILTIN_TX, INPUT);
#endif

#if DEBUG
#ifndef APP_CONTROL
    Serial.begin(BAUD_RATE);
#endif
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

/**
 * @brief Change the profile is profiles are enabled.
 * When the last profile is reach , the counter resets.
 */
inline void UKPmanager::changeProfile()
{
    currentProfile < defaultProfilesSum - 1 ? currentProfile++ : currentProfile = 0;
}

#endif

/**
 * @brief Send correct button id by checking if profiles are enabled
 * If profiles are enabled increment by 1 if profile button was pressed
 * If a profile button is defined then the first button changes profiles
 * @param button_pin the button which triggered a macro
 */
void UKPmanager::manageButtonMacros(int &button_pin)
{
    if (button_pin)
#if PROFILES
        MA.parseMacro(button_pin - 1, currentProfile);
    else
        changeProfile();
#else
        MA.parseMacro(button_pin);
#endif
}

#ifdef KILL_SWITCH
/**
 * @brief Control outputs based on the state of the kill kill_switch.
 * 
 * @return The state of the kill_switch pin.
 */
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

/**
 * @brief Continuously check state of components.
 * 
 */
void UKPmanager::runtime()
{
#ifdef KILL_SWITCH
    if (killSwitch())
#endif
    {
        auto d = Input.inputPolling();
#ifdef APP_CONTROL
        if (d.type != type_none)
            SC.sendReport(d);
#endif
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
#ifdef APP_CONTROL
    SC.runtime();
#endif
}
#endif