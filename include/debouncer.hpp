#pragma once
#include <Arduino.h>

class debouncer
{
private:
    unsigned long last_trigger=0;
public:
    /* static void start();
    static void stop(); */
    bool debounce();
};
