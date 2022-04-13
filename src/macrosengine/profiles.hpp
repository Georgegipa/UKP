#pragma once
#include "settings.h"
extern int maxProfiles;
#ifdef PROFILES

class profiles
{
public:
    void operator++(int);
    void operator--(int);
    void operator[](int i);
    void reset();
};
extern profiles Profile;
extern int currentProfile;
#endif