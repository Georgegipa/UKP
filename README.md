# UKP
(Universal Keypad Protocol)

A simple modular macro keyboard with profile support and more!
<!-- 
SKP as well as its companion app is under heavy development!
For microcontrollers supporting builtin USB-HID (like the arduino micro) UKP is used.

For microcontrollers which don't have support for USB-HID(like the arduino uno) SKP is used.

### **SKP requires Serial communication with the host computer as well as a companion app to be installed!** -->

## Features
* Support for multiple profiles.
* Customizable ([customizing UKP](#addingremoving-components))
* Support for [macros](#basic-macros) 
* Support for [advanced macros](#macro-commands)
* Support for Media Keys, Browser Actions , volume-brightness control and more
* Display current profile in a number of different ways:
    * Binary output (speaker or led)
    * 7 Segment display
* Load Profiles from micro_sd

## Project Roadmap
* ~~Create a keypad with multiple profiles~~ (v0.2+)
* More display options:
    * ~~Display Profile number on onboard led~~ (v0.3.2+)
    * ~~Add support for 7segment display~~ (v0.4+)
* Revamp Macros logic & MacrosEngine
    * ~~Accept more complicated commands(open programs,enter strings)~~ (v0.5+)
    * ~~Accept media keys~~ (v0.7+)
    * Accept mouse actions
        * ~~Support for scrolling~~ (v0.8+)
    * More macro commands
* SD improvements
    * better micro sd detection
    * bind profiles to files (1.txt -> profile 1 ....)
* More input options
    * add keypad support
    * add potentiometer support
    * add joystick support
    * add support for mixed inputs

# How to use UKP
UKP supports 2 categories of macros:
* [basic macros](#basic-macros) (which are button combinations)
* and [macro commands](#macro-commands)

## Basic Macros
**This is the default behavior if no macro command is specified!**

A basic macro is the collection of keys which are going to be held down and then be released.
Basic macro rules:
* The keys which are going to be pressed are separated with the use of: **+**.
* letters should be capital.
* the supported [Modifier keys](#supported-modifier-keys) are listed below.
* If the given modifier or key is not found then it is not pressed
* Combine any modifier key with mouse scroll with [Mouse Modifier](#extra-mouse-modifiers)

Learn more on how to change default macros [here](#changing-default-macros)

# MACRO COMMANDS 
## THINGS TO KNOW BEFORE USING
### Macro commands contain 1 letter and are followed by a comma (,).
* **If no commands are detected ,then the string is treated as a normal macro!**
* **Macro commands are not always executed when the button is held and thus can cause errors!**
## USAGE
With release v0.5+ UKP now supports the following commands:

**(str represents the following string)**
* R,str
    * Windows RUN.Press WIN+R and paste the following str. Used for opening programs and services
* W,str 
    * Write str to output 
* O,str
    * Functions like basic macro but instead of holding all the buttons pressed, instead each button is released as soon as it is pressed
* E,str
    * Press and then release the following [extra key](#supported-extra-keys)
* P,x
    * **DOES NOTHING IF PROFILES ARE DISABLED!**
    * Switch to x-number profile (if this greater than the max Profiles , then its set to max)
    * If x is + or - then go to the next or previous profile
    * If x is set to a negative number of any other character nothing happens

more coming soon...

## Supported Modifier Keys
* CTRL
* SHIFT
* ALT
* WIN   (windows key)
* UP    (up arrow key)
* DOWN  (down arrow key)
* LEFT  (left arrow key)
* RIGHT (right arrow key)
* BACKSPACE
* TAB
* RETURN
* ESC
* INSERT
* DELETE
* PUP   (page up)
* PDOWN (page down)
* HOME
* END
* CAPS (caps lock)
* F1
* F2
* F3
* F4
* F5
* F6
* F7
* F8
* F9
* F10
* F11
* F12
* F13
* F14
* F15
* F16
* F17
* F18
* F19
* F20
* F21
* F22
* F23
* F24

### Extra Mouse Modifiers
* SCRUPx Scroll up x pixels
* SCRDWx Scroll down x pixels

## Supported Extra Keys
* PLAY_PAUSE
* VOL_MUTE
* VOL_UP
* VOL_DOWN
* NEXT_TRACK
* PREV_TRACK
* STOP
* BR_UP (brightness UP)
* BR_DOWN (brightness DOWN)
* MEDIA (opens default media player)
* EMAIL
* CALC
* FILES
### Browser Controls
* B_HOME
* B_BACK
* B_FORWARD
* B_REFRESH
* B_BOOKMARKS

# Wiring
## Arduino and MicroSd module connections
**Note if using arduino micro 5v, micro sd module has to be 5v tolerant!**

```
Arduino | microSD
Micro   | module

VCC  --->   VCC

D15  --->   SCK

D14  --->   MISO

D16  --->   MOSI

GND  --->   GND

D10  --->   CS
```

The default connections for the buttons led & kill_switch are the following:
```
Arduino | Component
Micro   | 

A1  --->   button1

A2  --->   button2

D7  --->   button3

D9  --->   led

D8  --->   kill_switch
```

# Adding/Removing Components

## Changing the number of buttons
To change the number of buttons:
* navigate to config.h and the definition of **BUTTONS** to the desired number then
* below on BUTTON_PINS definition add the pins corresponding to the number of buttons separated by a comma (,).

## Changing the binary output pin
To change the binary output(led/piezo speaker) pin:
* navigate to config.h and the definition of **LED** to the desired number 

**Setting LED to 0 uses the arduino builtin led!**

## Enabling/Disabling KILL_SWITCH
This component enables the keypad to be enabled/disabled based on the state of a connected switch. 

## Enabling KILL_SWITCH:
* navigate to config.h and the definition of **SWITCH** to the desired number

 **Warning** setting this to 0 disables the KILL_SWITCH component completely! 

## Enabling/Disabling outputs
The following outputs are currently supported:
* Binary output(led or piezo buzzer).
* Directly connected 7 segment display (due to the number of available pins on the arduino micro , enabling this display will decrease the available pins).

# Changing Default Macros
To change the default macros which are stored in arduino's flash:
* navigate to macrosengine/default_macros.h
* add a new macro with a unique name : MACRO name[] = "your_macro";
    * your_macro should be replaced by your desired macro [instructions1](#basic-macros) and [instructions2](#macro-commands)
* add the newly added macro name to the defaultMacros

## Example adding a new macro
* add a new macro:
    - MACRO macro_8[] = "ALT+TAB";
* add the name of the newly added macro to the defaultMacros table
    - ... macro_7,macro_8 };