#include "settings.h"
#ifdef HID_ENABLED
#pragma once
#include <Arduino.h>
enum ConsumerKeycode : uint16_t
{
    HID_CONSUMER_UNASSIGNED = 0x00,
    //media controls
    MEDIA_NEXT = 0xB5,
    MEDIA_PREVIOUS = 0xB6,
    MEDIA_STOP = 0xB7,
    MEDIA_PLAY_PAUSE = 0xCD,
    MEDIA_PAUSE = 0xB0,
    MEDIA_VOLUME_MUTE = 0xE2,
    MEDIA_VOLUME_UP = 0xE9,
    MEDIA_VOLUME_DOWN = 0xEA,
    //works only on laptop displays
    CONSUMER_BRIGHTNESS_UP = 0x006F,
    CONSUMER_BRIGHTNESS_DOWN = 0x0070,    
    //open apps
    CONSUMER_CONTROL_CONFIGURATION = 0x183,
    CONSUMER_EMAIL_READER = 0x18A,
    CONSUMER_CALCULATOR = 0x192,
    CONSUMER_EXPLORER = 0x194,
    //control browser
    CONSUMER_BROWSER_HOME = 0x223,
    CONSUMER_BROWSER_BACK = 0x224,
    CONSUMER_BROWSER_FORWARD = 0x225,
    CONSUMER_BROWSER_REFRESH = 0x227,
    CONSUMER_BROWSER_BOOKMARKS = 0x22A
};

#endif