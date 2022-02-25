#pragma once
#include <Arduino.h>
#include "settings.h"
#include "binary_output/binary_output.hpp"
#include "DynamicInput/DynamicInput.hpp"

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
    int lastProfileState;
    void profileChanged();
#endif
#ifdef KILL_SWITCH
    boolean killSwitch();
#endif
    int currentProfile;
    void manageButtonMacros(int &buttonId);
    int pinTriggered; // save the button id of the last pressed button
public:
    void begin();
    void runtime();
};

extern UKPmanager manager;