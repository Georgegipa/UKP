#include <Arduino.h>
#include "extendedHID/Consumer2_Keycodes.h"
#include "settings.h"

namespace extraKeys
{
    MACRO binding_0[] = "PLAY_PAUSE";
    MACRO binding_1[] = "VOL_MUTE";
    MACRO binding_2[] = "VOL_UP";
    MACRO binding_3[] = "VOL_DOWN";
    MACRO binding_4[] = "NEXT_TRACK";
    MACRO binding_5[] = "PREV_TRACK";
    MACRO binding_6[] = "STOP";
    MACRO binding_7[] = "BR_UP";
    MACRO binding_8[] = "BR_DOWN";
    MACRO binding_9[] = "MEDIA";   // opens default media player
    MACRO binding_10[] = "EMAIL";  // opens default email app
    MACRO binding_11[] = "CALC";   // opens calculator
    MACRO binding_12[] = "FILES";  // open windows file explorer
    MACRO binding_13[] = "B_HOME"; // if browser is open redirects to home ,else opens new window on home tab
    MACRO binding_14[] = "B_BACK";
    MACRO binding_15[] = "B_FORWARD";
    MACRO binding_16[] = "B_REFRESH";
    MACRO binding_17[] = "B_BOOKMARKS";

    MACRO_ARRAY bindings[] = {
        binding_0,
        binding_1,
        binding_2,
        binding_3,
        binding_4,
        binding_5,
        binding_6,
        binding_7,
        binding_8,
        binding_9,
        binding_10,
        binding_11,
        binding_12,
        binding_13,
        binding_14,
        binding_15,
        binding_16,
        binding_17};

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
            CONSUMER_BRIGHTNESS_DOWN,
            CONSUMER_CONTROL_CONFIGURATION,
            CONSUMER_EMAIL_READER,
            CONSUMER_CALCULATOR,
            CONSUMER_EXPLORER,
            CONSUMER_BROWSER_HOME,
            CONSUMER_BROWSER_BACK,
            CONSUMER_BROWSER_FORWARD,
            CONSUMER_BROWSER_REFRESH,
            CONSUMER_BROWSER_BOOKMARKS};

    PROGMEM_INT bindingsSum = ARR_SIZE(key_codes);    // number of all bindings
    PROGMEM_INT bindingMaxSize = ARR_SIZE(binding_3); // size of the longest binding
}