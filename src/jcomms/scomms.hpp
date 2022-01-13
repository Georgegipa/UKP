#include <Arduino.h>

class scomms
{
private:
    /* data */
    const char* prefix = "->";
    void respond(int request);
public:
    void begin(int baudRate);
    void runtime();
};


extern scomms JC;