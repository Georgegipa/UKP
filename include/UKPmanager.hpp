#pragma once
#include <Arduino.h>
#include "button.hpp"
#include "options.hpp"

class UKPmanager
{
private:
    button btn[BUTTONS];

public:
    void init();
    ~UKPmanager();
    void runtime();
};

extern UKPmanager UKP;