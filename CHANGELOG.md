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

## [0.5.0] - 2021-12-17
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