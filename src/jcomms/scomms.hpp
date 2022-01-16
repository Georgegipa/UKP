#include <Arduino.h>

class scomms
{
private:
    /* data */
    const char* protocolPrefix = "->";
    void respond(char request);
public:
    void begin(int baudRate);
    void runtime();
};


extern scomms JC;