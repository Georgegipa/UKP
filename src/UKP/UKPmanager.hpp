#pragma once
#include <Arduino.h>
#include "definitions.h"
#include "button/button.hpp"
#include "binary_output/binary_output.hpp"
#if SEVEN_SEGMENT
#include "_7segment.hpp"
#endif
class UKPmanager
{
private:
    button btn[BUTTONS];
    binary_output out;
#ifdef HID_ENABLED
#if SEVEN_SEGMENT
    _7segment seg;
#endif
//if profiles are enabled track when they change
#if PROFILES
    int lastProfileState;
    int currentProfile;
    void profileChanged();
#endif
#if KILL_SWITCH
    boolean killSwitch();
#endif
#endif
    void manageButtonMacros(int &buttonId);
    int pinTriggered; //save the button id of the last pressed button
public:
    void begin();
    ~UKPmanager();
    void runtime();
};

extern UKPmanager manager;