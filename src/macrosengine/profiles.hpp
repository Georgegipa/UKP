#pragma once
#include "settings.h"
extern const int defaultProfilesSum;
#ifdef PROFILES
#include <Arduino.h>

class profiles
{
public:
    void operator++(int);
    void operator--(int);
    void operator[](int i);
};
extern profiles Profile;
extern int currentProfile;
#endif