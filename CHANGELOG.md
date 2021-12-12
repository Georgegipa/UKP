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