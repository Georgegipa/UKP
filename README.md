# UKP
(Universal KeyPad)

A simple arduino pro micro macro keyboard with profile support and more!
## Features
* Support for multiple profiles.
* Fully customizable
* Support for macros and advanced macros ([macro commands](#macro-commands))
* Display current profile in a number of diffrent ways:
    * Binary output (speaker or led)
    * 7 Segment display

## Project Roadmap
* ~~Create a keypad with multiple profiles~~ (v0.2+)
* Revamp Macros logic & MacrosEngine
    * ~~Accept more complicated commands(open programms,enter strings)~~ (v0.5+)
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
**Note if using arduino pro micro 5v, micro sd module has to be 5v torelant!**
```
Arduino |   5V
Pro     | microSD 
Micro   | module

VCC  --->   VCC

D15  --->   SCK

D14  --->   MISO

D16  --->   MOSI

GND  --->   GND

D10  --->   CS
```