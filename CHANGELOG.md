# ChangeLog
All notable changes to this project will be documented in this file.

<!-- 
## [0.2.1] - 2021-12-11
Update description(template)
### Added
* 
### Removed
* 
### Changed
* 
### Fixed
*  -->

## [0.6.0] - 2022-1-4
SD card support
### **alpha 4** - 2022-1-18
### Added
* Option to change led pin
### Changed
* Simplified macros type 
### **alpha 3** - 2022-1-12
### Added
* Option in config to disable 7 segment display
### Changed
* Check if board natively supports USB_HID
* Definition for board name
* Refactor of platformio.ini to support more boards
### **alpha2** - 2022-1-12
### Added
* sd card option to check if file exists
### Changed
* simplified button print_state
### **alpha1** - 2022-1-4
### Added
* sd card support
### Changed
* simplified macro command recognition
## [0.5.3] - 2021-12-24
Revamped options 
### Removed
* options files
    * Options files have been replaced by all the files in the config  folder
### Changed
* moved button pins config options.hpp->button_pins.h
* moved definitions options.hpp->defintions.h
* changed profiles logic options.hpp->default_profiles.h
    * default_profiles are now stored in progmem
## [0.5.2] - 2021-12-23
Added kill switch
### Added
* Kill switch to disable-enable UKP actions, this help avoid accidental presses while debugging
### Changed
* Layout of default buttons for adding microSD support
## [0.5.1] - 2021-12-21
Removed duplicate modifier keys and replaced with simpler ones
### Changed
The following keys are no longer duplicates of left and right:
* CTRL
* SHIFT
* ALT
* GUI
## [0.5.0] - 2021-12-21
MacrosEngine API 2.0 
### Added
* ability to open windows programs with WIN+R
## [0.4.0] - 2021-12-17
7 segment display support & setHigh/Low functions for leds
### Added
* 7segment display class 
## [0.3.2] - 2021-12-13
Binary profile output
### Added
* binary output to use led or buzzer to display the new active profile
* option to disable builtin rx/tx leds
### Changed
* all profile display actions are now managed by UKPmanager 
## [0.3.1] - 2021-12-12
Disable profiles and profile button
### Added
* option to disable profiles and profile button
## [0.3.0] - 2021-12-12
UKPmanager
### Added
* UKPmanager a cleaner way to control and initialize UKP
### Changed
* Moved DEBOUNCEDELAY,MACRO_MAX_SIZE from platfomio.ini to options.hpp
## [0.2.5] - 2021-12-12
Memory Improvements
### Changed
* Button constructor now loads automatically button_pins
## [0.2.4] - 2021-12-11
Memory Improvements
### Changed
* Created class MacrosEngine for reading-executing macros
## [0.2.3] - 2021-12-11
Memory Improvements
### Changed
* Keycodes are now stored in progmem
### Fixed
* Debug options in actions.hpp not displaying correct key_codes
## [0.2.2] - 2021-12-11
### Added
* Profiles(**The first defined button is assigned to profiles!**)
## [0.2.1] - 2021-12-11
### Fixed
* Macros pressing shift when capitals letters when present in profiles
### Changed
* Removed KEYS_ infront of modifier keys to save memory 