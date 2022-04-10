#include "macroretriever.hpp"
#ifdef HID_ENABLED
#include "default_macros.h"
#include "macrosengine/profiles.hpp"
const int defaultProfilesSum = (PROFILES ? (dp_num / (BUTTON_SUM - 1)) : 1);
macroretriever Retriever;

void macroretriever::begin()
{
    #if SD_ENABLED
    sd.begin();
    #endif
}

/**
 * @brief Returns the position of the default_profiles array corresponding to the button pressed and the profile selected.
 * If profiles are enabled the total number of buttons is -1.
 * @param profile_id the currently selected profile
 * @param button_id the pressed button
 */
inline int macroretriever::findMacroID(int profile_id, int button_id)
{
    return (((PROFILES ? BUTTON_SUM - 1 : BUTTON_SUM) * profile_id) + (button_id));
}

/**
 * @brief Returns the string of the macro corresponding to the button pressed and the profile selected.
 * 
 * @param buttonId the pressed button
 * @param profileId the currently selected profile
 * @param loadDefaults if true, the default macro is returned if the macro is not found
 * @return char* the macro string
 */
char *macroretriever::getMacro(int buttonId, int profileId, bool loadDefaults)
{
    static char str[MACRO_MAX_SIZE];
    if (loadDefaults)
        strcpy_P(str, RETRIEVE_PROFILE(defaultMacros, findMacroID(profileId, buttonId)));
    #if SD_ENABLED
    else
        strncpy_T(str, sd.readLine(findMacroID(profileId, buttonId)), MACRO_COMMAND_SIZE); // load from micro sd
    #endif
    return str;
}
#endif