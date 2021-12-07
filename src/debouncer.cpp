#include "debouncer.hpp"

bool debouncer::debounce()
{
    
    if ((millis() - last_trigger) > DEBOUNCEDELAY)
    {
        last_trigger=millis();
        return 1;
    }
    return 0;
}