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
#if PROFILES
    int lastProfileState;
    void profileChanged();
#endif
#ifdef KILL_SWITCH
    bool killSwitch();
#endif
    void manageButtonMacros(int &buttonId);
public:
    void begin();
    void runtime();
};

extern UKPmanager manager;
#endif