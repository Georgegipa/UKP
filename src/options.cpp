#include "options.hpp"
const int button_pins[BUTTONS] = {15, 14, 16};

//The following macros are enabled if micro_sd is disable or is not detected
#if MICRO_SD_ENABLED == 0
char profiles[][BUTTONS][MACRO_MAX_SIZE]{
    {"KEY_LEFT_CTRL+V",
     "KEY_LEFT_CTRL+C",
     "KEY_LEFT_CTRL+X"},
    {"KEY_LEFT_CTRL+Z",
     "KEY_LEFT_CTRL+Y",
     "KEY_LEFT_ALT+KEY_TAB"}};
#endif

int num_of_profiles=ARR_SIZE(profiles);