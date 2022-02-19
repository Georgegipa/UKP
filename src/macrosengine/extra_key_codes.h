#include <Arduino.h>
#include "extendedHID/Consumer2_Keycodes.h"
#include "macros.h"

namespace extraKeys
{
    MACRO binding_0[] = "PLAY_PAUSE";
    MACRO binding_1[] = "VOLUME_MUTE";
    MACRO binding_2[] = "VOLUME_UP";
    MACRO binding_3[] = "VOLUME_DOWN";
    MACRO binding_4[] = "NEXT";
    MACRO binding_5[] = "PREVIOUS";
    MACRO binding_6[] = "STOP";
    MACRO binding_7[] = "BRIGHTNESS_UP";
    MACRO binding_8[] = "BRIGHTNESS_DOWN";

    MACRO_ARRAY bindings[] = {
        binding_0,
        binding_1,
        binding_2,
        binding_3,
        binding_4,
        binding_5,
        binding_6,
        binding_7,
        binding_8};

    const ConsumerKeycode key_codes[] =
        {
            MEDIA_PLAY_PAUSE,
            MEDIA_VOLUME_MUTE,
            MEDIA_VOLUME_UP,
            MEDIA_VOLUME_DOWN,
            MEDIA_NEXT,
            MEDIA_PREVIOUS,
            MEDIA_STOP,
            CONSUMER_BRIGHTNESS_UP,
            CONSUMER_BRIGHTNESS_DOWN};

    MACRO_INT bindingsSum = ARR_SIZE(key_codes);    // number of all bindings
    MACRO_INT bindingMaxSize = ARR_SIZE(binding_3); // size of the longest binding
}