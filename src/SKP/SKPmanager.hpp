#pragma once
#include "settings.h"
#ifndef HID_ENABLED

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