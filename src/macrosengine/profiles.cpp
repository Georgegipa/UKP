#include "profiles.hpp"
#if PROFILES
profiles PR;
int currentProfile = 0;

void profiles::operator++(int)
{
    currentProfile < maxProfiles - 1 ? currentProfile++ : currentProfile = 0;
}

void profiles::operator--(int)
{
    currentProfile < 0 ? currentProfile = maxProfiles : currentProfile--;
}

void profiles::operator[](int i)
{
    if (i > maxProfiles)
        currentProfile = maxProfiles;
    else if (i < 0)
        currentProfile = 0;
    else
        currentProfile = i;
}

void profiles::reset()
{
    currentProfile = 0;
}
#endif