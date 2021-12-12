#include "UKPmanager.hpp"

UKPmanager UKP;

void UKPmanager::init()
{
    Serial.begin(9600);
#if DEBUG
    while (!Serial); //wait for serial
    Serial.print("Number of buttons intialized:");
    Serial.println(button::numofbuttons);
    Serial.print("Number of profiles intialized:");
    Serial.println(num_of_profiles);
#endif
}

UKPmanager::~UKPmanager()
{
#if INTERRUPTS_ENABLED
    for (int i = 0; i < BUTTONS; i++)
    {
        btn[i].~button();
    }
#endif
}

void UKPmanager::runtime()
{
    for (int i = 0; i < BUTTONS; i++)
    {
        btn[i].state();
    }
}
