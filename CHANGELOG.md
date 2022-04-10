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

## [0.9.0] - 2022-04-10
### Added
* Proper sdcard support
    * read and parse lines to macrosengine
    * option to change default sdcard file
* Option to select behavior if sdcard is not available
    * LOAD_BEHAVIOR added to config.h
## [0.8.6c] - 2022-04-10
### Changed
* MacrosEngine 3.0
    * now only analyzes strings
    * moved button and profile analysis to separate files(macroretriever)
## [0.8.6b] - 2022-04-08
### Changed
* Mouse scroll behavior
    * SCRUP,SCRDW -> SCRU,SCRD
    * now caseinsensitive 
## [0.8.6] - 2022-04-07
### Changed
* Simplified bindings name for basic and extra keys
* Moved f keys logic to macrosengine
### Removed
* F keys from bindings
## [0.8.5] - 2022-03-01
### Added
* SSprintf that functions like printf for logging purposes
* The ability to have profiles enabled without a profile button defined
### Changed
* Moved helpers to settings.h (accessible from the whole project)
### Removed
* LOG 
    * replaced by SSprintf
## [0.8.4] - 2022-02-28
### Added
* Extra keys are now processed like basic macros
    * H , O macro command supported added
### Removed
* E macro command
## [0.8.3c] - 2022-02-27
### Added
* variadic LOG function to replace debug serial prints
### Removed
* findExtraKey
### Changed
* BUTTONS now defines the number of BUTTON_PINS
* replaced findExtraKey logic with processExtraKey
## [0.8.3b] - 2022-02-27
### Added
* In debug mode if a HID compatible mc is connected led flashes until connected over serial
### Changed
* RETRIEVE_PROFILE now supports all char PROGMEM arrays
## [0.8.3] - 2022-02-26
P macro command
### Added
* P macro command to change profiles with a macro
* New profile class to control profiles globally
### Changed
* W macro command changed to R
* P macro command changed to W
## [0.8.2] - 2022-02-26
Bug fix 
### Added
* strncpy_PT a null terminated strncpy_P
### Removed
* unused code
### Fixed
* parseMacro on macrosengine binding wrong buttons to profiles
## [0.8.1] - 2022-02-26
Scrolling , profile remapping 
### Removed
* helpers.h
* _7segments_leds.h
### Changed
* moved HID_ENABLED->settings.h 
* moved 7segments leds pins to config.h
* UKPmanager no longer requires currentProfile 
* macrosengine reversed profileId and buttonId to only require buttonId if PROFILES are disabled
* replaced strncpy with strncpy_T in macrosengine
## [0.8.0] - 2022-02-25
Scrolling , profile remapping 
### Added
* Support for Joysticks(not binded yet to macros)
* Profile Button is now remappable
* Scrolling support with SCRUPx SCRDWx 
* printtobuild to display which version is being build for selected config
* Error if no inputs are defined
* strncpy_T a null terminated strncpy
### Changed
* Moved macros.h->settings.h
* Moved all defined macros to settings.h
* Replaced strcmp with strcasecmp to be safe against lower case letters
* Renamed Extra keys
### Removed
* Unnecessary defined inline functions defined by Arduino.h
### Fixed
* Multiple issues where project would fail to build due to being unable to find excluded headers
## [0.7.2] - 2022-02-20
DynamicInput 
### Added
* DynamicInput (better way to control inputs)
### Removed
* interrupts & code using interrupts
* button_pins.h
* button input from UKPmanager
### Changed
* buttons_pins moved to config.h
* moved button config to button.hpp
## [0.7.1] - 2022-02-19
Support for more keyCodes
## Added 
* Browser Controls
* Open calculator, media player, file explorer, email
## [0.7.0] - 2022-02-19
Support for more KeyCodes
### Added
* Support for extraKeys using a modified version of NicoHood HID
### Removed
* definitions.h
* extra_button_codes.h
### Changed
* Renaned definitions.h -> config.h
* Moved extern variabled to global_varibles.h
## [0.6.0]
SD card support
### **alpha 5** - 2022-1-20
### Changed
* renamed MICRO_SD_ENABLED -> SD_ENABLED
### Fixed
* SD_ENABLED behavior
* LED pin behavior
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
* Removed KEYS_ in front of modifier keys to save memory 