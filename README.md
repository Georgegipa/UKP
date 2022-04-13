# UKP
### (Usb KeyPad)

A simple modular macro keyboard with profile support and more!
<!-- 
SKP as well as its companion app is under heavy development!
For microcontrollers supporting builtin USB-HID (like the arduino micro) UKP is used.

For microcontrollers which don't have support for USB-HID(like the arduino uno) SKP is used.

### **SKP requires Serial communication with the host computer as well as a companion app to be installed!** -->

## Features
* Support for multiple [profiles](#profiles).
* Customizable ([customizing UKP](#addingremoving-components))
* Support for [macros](#basic-macros) 
* Support for [advanced macros](#macro-commands)
* Support for Media Keys, Browser Actions , volume-brightness control and more
* Display current profile in a number of different ways:
    * Binary output (speaker or led)
    * 7 Segment display
* Load Profiles from a SD card
* Case insensitive macros

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
    * ~~better micro sd detection~~ (v0.9+)
    * bind profiles to files (1.txt -> profile 1 ....)
* More input options
    * add keypad support
    * add potentiometer support
    * add joystick support
    * add support for mixed inputs

# How to use UKP
UKP supports 2 categories of macros:
* [basic macros](#basic-macros) (which are button combinations)
* [macro commands](#macro-commands)
    * [Generic macro commands](#generic-macro-commands)
    *  [Basic Macro Behavior modifying macro commands](#change-basic-macro-behavior)

# Basic Macros
**This is the default behavior if no macro command is specified!**

A basic macro is the collection of keys which are going to be held down and then be released.

Basic macro rules:
* The keys which are going to be pressed must be separated with the use of: **+**.
* Letters should be capital.
* If the given modifier or key is not found then it is not pressed


## Supported Keys and Commands
* [Extra keys](#supported-extra-keys).
    * Due to the api used up to 4 extra keys can be used at once
* [Modifier keys](#supported-modifier-keys).
* [Mouse Modifier](#extra-mouse-modifiers).

Learn more on how to change default macros [here](#changing-default-macros).

# MACRO COMMANDS 
## THINGS TO KNOW BEFORE USING
### Macro commands contain 1 letter and are followed by a comma (,).
* **If no commands are detected ,then the string is treated as a normal macro!**
* **Macro commands are not always executed when the button is held and thus can cause errors!**
## Supported macro commands
### Generic macro commands
**str represents the following string!**
* R,str
    * Windows RUN.Press WIN+R , paste the following str and then press enter.
        * Used for opening programs and services.
    * R stands for **RUN**
* W,str 
    * Write str to output 
    * W stands for **Write**
* P,x
    * **DOES NOTHING IF PROFILES ARE DISABLED!**
    * Switch to x-number profile (if this greater than the max Profiles , then its set to max)
    * If x is + or - then go to the next or previous profile.
    * If x is set to a negative number of any other character nothing happens.
    * P stands for **Profiles**

### Change basic macro behavior
The following macro commands can be appended in front of the basic macros to alter their behavior.

**Changing the behavior of basic macros doesn't have an effect on [Mouse Modifier](#extra-mouse-modifiers).**

**Keeping keys pressed can cause unwanted behavior.**

* O,[basic_macro](#basic-macros) 
    * Each button is released as soon as it is pressed.
    * ℹ O stands for press **Once**
* H,[basic_macro](#basic-macros)
    * **Avoid removing the board while a key is pressed! Release it first and then remove board**
    * Hold a key held down until another key is pressed
     * ℹ H stands for **Hold**

more coming soon...

## Supported Modifier Keys
* CTRL                                  
* SHIFT                             
* ALT
* WIN           (windows key)           
* UP            (up arrow key)
* DOWN          (down arrow key)        
* LEFT          (left arrow key)
* RIGHT         (right arrow key)
* BKSP          (backspace key)
* TAB
* ENTER
* ESC
* INS           (insert key)
* DEL           (delete key)
* PU            (page up)
* PD            (page down)
* HOME
* END
* CL            (caps lock)
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

## Extra Mouse Modifiers
**x is a number between 1 and 127!**
* SCRUx 
    * Scroll up x pixels
* SCRDx 
    * Scroll down x pixels

## Supported Extra Keys

### Volume and Brightness Control
```  
* VOL_M         (mute volume)                   🔇      
* VOL_U         (volume UP)                     🔊      
* VOL_D         (volume DOWN)                   🔉       
* BRT_U         (brightness UP)                 🔆      
* BRT_D         (brightness DOWN)               🔅      
```

### Media Playback Controls
```
* M_PLAY        (play/pause media)              ⏯      
* M_STOP        (stop currently playing media)  ⏹     
* M_NEXT        (play next track)               ⏭      
* M_PREV        (play pervious track)           ⏮   
```

### Open Basic Apps
```
* MEDIA         (opens default media player)    📺      
* EMAIL         (opens default email program)   📧      
* CALC          (opens calculator)              🧮      
* FILES         (opens file explorer)           📁   
```

### Browser Controls
(this is a sub-category of extra keys and behavior is the same)
```
* B_HOME        (redirect to home page*)         🏠      
* B_PREV        (go back a page)                ◀     
* B_NEXT        (go forward a page)              ▶          
* B_REF         (refresh current page)          🔃      
* B_FAV         (open bookmarks/favorites)      ⭐          
```
**\*if browser isn't open a window on home tab is opened**

# PROFILES
Once all macros are defined , UKP generates the number of profiles which are going to be used by the input devices. 
* The number of profiles is generated by the following function: number of macros / BUTTONS
* If the above division has a remainder,  the remaining macros aren't used.
* Profiles can be changed using the P macro command
* Profiles are enabled in config.h by setting the pin number to the number corresponding to the profiles button.
    * Only one button can be used to change Profiles
    * Setting PROFILE_BUTTON to -1 disables PROFILES
    * Setting PROFILE_BUTTON to -2 disables PROFILE_BUTTON

# Adding/Removing Components
The configuration is done in config.h
## Changing the number of buttons
To change the number of buttons:
* navigate to config.h and the definition of **BUTTONS** to the desired number then
* below on BUTTON_PINS definition add the pins corresponding to the number of buttons separated by a comma (,).
* If you want a specific button to change between profiles set its pin to PROFILE_BUTTON.
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
* navigate to default_macros.h
* add a new macro with a unique name : MACRO name[] = "your_macro";
    * your_macro should be replaced by your desired macro [instructions1](#basic-macros) and [instructions2](#macro-commands)
* add the newly added macro name to the defaultMacros

## Example adding a new macro
* add a new macro:
    - MACRO macro_8[] = "ALT+TAB";
* add the name of the newly added macro to the defaultMacros table
    - ... macro_7,macro_8 };
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