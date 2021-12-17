#pragma once
#include <Arduino.h>
#include "button.hpp"
#include "options.hpp"
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
    int last_profile_state;
    void profile_changed();
#endif
public:
    void init();
    ~UKPmanager();
    void runtime();
};

extern UKPmanager UKP;