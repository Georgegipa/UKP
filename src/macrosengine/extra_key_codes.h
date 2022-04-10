#include "settings.h"
#include "extendedHID/Consumer2_Keycodes.h"

namespace extraKeys
{
    MACRO binding_0[] = "M_PLAY";
    MACRO binding_1[] = "M_NEXT";
    MACRO binding_2[] = "M_PREV";
    MACRO binding_3[] = "M_STOP";
    MACRO binding_4[] = "VOL_M";
    MACRO binding_5[] = "VOL_U";
    MACRO binding_6[] = "VOL_D";
    MACRO binding_7[] = "BRT_U";
    MACRO binding_8[] = "BRT_D";
    MACRO binding_9[] = "MEDIA";   // opens default media player
    MACRO binding_10[] = "EMAIL";  // opens default email app
    MACRO binding_11[] = "CALC";   // opens calculator
    MACRO binding_12[] = "FILES";  // open windows file explorer
    MACRO binding_13[] = "B_HOME"; // if browser is open redirects to home ,else opens new window on home tab
    MACRO binding_14[] = "B_PREV";
    MACRO binding_15[] = "B_NEXT";
    MACRO binding_16[] = "B_REF";
    MACRO binding_17[] = "B_FAV";

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
            MEDIA_NEXT,
            MEDIA_PREVIOUS,
            MEDIA_STOP,
            MEDIA_VOLUME_MUTE,
            MEDIA_VOLUME_UP,
            MEDIA_VOLUME_DOWN,
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
    PROGMEM_INT bindingMaxSize = ARR_SIZE(binding_0); // size of the longest binding
}