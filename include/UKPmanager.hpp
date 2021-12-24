#pragma once
#include <Arduino.h>
#include "button.hpp"
#include "binary_output.hpp"
#include "_7segment.hpp"
#include "options.hpp"

class UKPmanager
{
private:
    button btn[BUTTONS];
    binary_output out;
    _7segment seg;
//if profiles are enabled track when they change
#if PROFILES
    int last_profile_state;
    void profile_changed();
    void manageButtonMacros(int &button_pin);
    int current_profile;
#endif
    int pin_triggered;
public:
    void init();
    ~UKPmanager();
    void runtime();
};

extern UKPmanager UKP;