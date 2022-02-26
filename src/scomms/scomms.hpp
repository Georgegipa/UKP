#include <Arduino.h>
#include "DynamicInput/Inputs.h"
#define PROTOCOL_PREFIX F("->")
#define NOT_VALID_COMMAND F("NVC")

class scomms
{
private:
    void respond(char request);
public:
    void begin(int baudRate);
    void runtime();
    void sendReport(InputData data);
};


extern scomms SC;