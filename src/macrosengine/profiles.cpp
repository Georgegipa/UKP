#include "profiles.hpp"
#if PROFILES

profiles PR;
int currentProfile = 0;

void profiles::operator++(int)
{
    currentProfile < defaultProfilesSum - 1 ? currentProfile++ : currentProfile = 0;
}

void profiles::operator--(int)
{
    currentProfile < 0 ? currentProfile = defaultProfilesSum : currentProfile--;
}

void profiles::operator[](int i)
{
    if (i > defaultProfilesSum)
        currentProfile = defaultProfilesSum;
    else if (i < 0)
        currentProfile = 0;
    else
        currentProfile = i;
}
#endif