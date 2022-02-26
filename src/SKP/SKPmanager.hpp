#pragma once
#include "settings.h"
#ifndef HID_ENABLED
#include <Arduino.h>

class SKPmanager
{
private:
    /* data */
public:
    void begin();
    void runtime();
};

extern SKPmanager manager;

#endif