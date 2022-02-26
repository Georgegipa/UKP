#pragma once
#include "settings.h"
#ifdef HID_ENABLED
#include <Arduino.h>
#include "binary_output/binary_output.hpp"

#if SEVEN_SEGMENT
#include "7segment/_7segment.hpp"
#endif

class UKPmanager
{
private:
    binary_output out;
#if SEVEN_SEGMENT
    _7segment seg;
#endif
// if profiles are enabled track when they change
#if PROFILES
    int currentProfile;
    int lastProfileState;
    void profileChanged();
    inline void changeProfile();
#endif
#ifdef KILL_SWITCH
    boolean killSwitch();
#endif
    void manageButtonMacros(int &buttonId);
    int pinTriggered; // save the button id of the last pressed button
public:
    void begin();
    void runtime();
};

extern UKPmanager manager;
#endif