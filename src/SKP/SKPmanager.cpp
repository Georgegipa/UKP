#include "SKPmanager.hpp"
#ifndef HID_ENABLED
#include "DynamicInput/DynamicInput.hpp"
#include "scomms/scomms.hpp"
SKPmanager manager;

void SKPmanager::begin()
{
    SC.begin(BAUD_RATE);
}

void SKPmanager::runtime()
{
    auto d = Input.inputPolling();
    if (d.type != type_none)
        SC.sendReport(d);
    SC.runtime();
}

#endif