# UKP
(Universal Keypad Protocol)

A simple macro keyboard with profile support and more!

For microcontrollers supporting builtin USB-HID (like the arduino micro) UKP is used.

For microcontrollers which don't have support for USB-HID(like the arduino uno) SKP is used.

### **SKP requires Serial communication with the host computer as well as a companion app to be installed!**

## Features
* Support for multiple profiles.
* Fully customizable
* Support for macros and advanced macros ([macro commands](#macro-commands))
* Display current profile in a number of different ways:
    * Binary output (speaker or led)
    * 7 Segment display

## Project Roadmap
* ~~Create a keypad with multiple profiles~~ (v0.2+)
* add option for enable/disable of binary output
* fix MICRO_SD_ENABLED not working correctly
* Revamp Macros logic & MacrosEngine
    * ~~Accept more complicated commands(open programs,enter strings)~~ (v0.5+)
    * Accept  even more advanced actions
    * Accept media keys
    * Accept mouse actions
* More display options:
    * ~~Display Profile number on onboard led~~ (v0.3.2+)
    * ~~Add support for 7segment display~~ (v0.4+)
    * Add support for oled display
* Load Profiles from micro_sd

# How to use UKP
UKP supports 2 categories of macros:
* button combinations
* and [macro commands](#macro-commands)

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

# MACRO COMMANDS 
## THINGS TO KNOW BEFORE USING
### Macro commands contain 1 letter (**are case sensitive!**) and are followed by a comma (,).
* **If no commands are detected ,then the string is treated as a normal macro!**
* **Macro commands are not always executed when the button is held and thus can cause errors!**
## USAGE
With release v0.5+ UKP now supports the following commands:

**(str represents the following string)**
* W,str
    * Press WIN+R and paste the following str. Used for opening programs and services
* P,str 
    * Enter str to output 

more coming soon...

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

A3  --->   button3

D9  --->   led

D8  --->   kill_switch
```

# Adding/Removing Components

## Changing the number of butt
To change the number of buttons:
* navigate to definitions.h and the definition of **BUTTONS** to the desired number then
* navigate to button/button_pins.h and add the corresponding pins that will be assigned to the buttons

## Enabling/Disabling KILL_SWITCH
This component enables the keypad to be enabled/disabled based on the state of a connected switch. 

Enabling KILL_SWITCH:
* navigate to definitions.h and the definition of **KILL_SWITCH** to the desired number

 **Warning** setting this to 0 disables the KILL_SWITCH component completely! 

## Enabling/Disabling outputs
The following outputs are currently supported:
* Binary output(led or piezo buzzer).
* Directly connected 7 segment display (due to the number of available pins on the arduino micro , enabling this display will decrease the available pins).

# Changing Default Profiles
To change the default profiles which are stored in arduino's flash:
* navigate to macrosengine/default_profiles.h
* add a new macro with a unique name : MACRO name[] = "your_macro";
* add the newly added macro to the defaultProfiles

## Example adding a new a new macro
* add a new macro:
    - MACRO macro_8[] = "ALT+TAB";
* add the name of the newly added macro to the defaultProfiles table
    - ... macro_7,macro_8 };