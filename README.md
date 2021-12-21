# UKP
(Universal KeyPad)

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

# Supported Modifier Keys
* CTRL
* SHIFT
* ALT
* GUI (windows key)
* UP_ARROW
* DOWN_ARROW
* LEFT_ARROW
* RIGHT_ARROW
* BACKSPACE
* TAB
* RETURN
* ESC
* INSERT
* DELETE
* PAGE_UP
* PAGE_DOWN
* HOME
* END
* CAPS_LOCK
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
### Macro commands contain 1 letter (**are case sensitive!**) and followed by comma (,).
* **If no commands are detect the string is treated as a macro!**
* **Macro commands are not always executed when the button is held and thus cause errors!**
## USAGE
With release v0.5+ UKP now supports the following commands:

**(str represents the following string)**
* W,str
    * Press WIN+R and paste the following str. Used for opening programs and services
* P,str 
    * Enter str to output 
    * more coming soon...
