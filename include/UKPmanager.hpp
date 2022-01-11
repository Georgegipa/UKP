#pragma once
#include <Arduino.h>
#include "config/definitions.h"
#include "button.hpp"
#include "binary_output.hpp"
#if SEVEN_SEGMENT
#include "_7segment.hpp"
#endif
class UKPmanager
{
private:
    button btn[BUTTONS];
    binary_output out;
#if SEVEN_SEGMENT
    _7segment seg;
#endif
//if profiles are enabled track when they change
#if PROFILES
    int lastProfileState;
    int currentProfile;
    void profileChanged();
    void manageButtonMacros(int &buttonId);
#endif
#if KILL_SWITCH
    boolean killSwitch();
#endif
    int pinTriggered; //save the button id of the last pressed button
public:
    void begin();
    ~UKPmanager();
    void runtime();
};

extern UKPmanager UKP;