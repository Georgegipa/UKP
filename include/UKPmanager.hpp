#pragma once
#include <Arduino.h>
#include "config/definitions.h"
#include "button.hpp"
#include "binary_output.hpp"
#include "_7segment.hpp"

class UKPmanager
{
private:
    button btn[BUTTONS];
    binary_output out;
    _7segment seg;
//if profiles are enabled track when they change
#if PROFILES
    int lastProfileState;
    int currentProfile;
    void profileChanged();
    void manageButtonMacros(int &buttonId);    
#endif
    int pinTriggered;
public:
    void begin();
    ~UKPmanager();
    void runtime();
};

extern UKPmanager UKP;