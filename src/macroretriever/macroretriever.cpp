#include "macroretriever.hpp"
#ifdef HID_ENABLED
#include "default_macros.h"
#include "macrosengine/profiles.hpp"
const int defaultProfilesSum = (PROFILES ? (dp_num / (BUTTON_SUM - 1)) : 1);
macroretriever Retriever;

void macroretriever::begin()
{
#if SD_ENABLED
    if (!SD.begin(10))
    {
        SSprintf("Card Mount Failed\n");
        return;
    }
    else
    {
        SSprintf("Successfully mounted microSD\n");
    }
#if DEBUG
    SDFileInfo();
    printFile(DEFAULT_FILE);
#endif
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
char *macroretriever::getMacro(int buttonId, int profileId)
{
    memset(str, 0, sizeof(str));
#if SD_ENABLED
    if (checkConnection() == 0 && LOAD_BEHAVIOR) // if file is not found and loadDefaults is true load macros from flash
        strcpy_P(str, RETRIEVE_PROFILE(defaultMacros, findMacroID(profileId, buttonId)));
    else
        strcpy(str, readLine(findMacroID(profileId, buttonId) + 1, DEFAULT_FILE));
#else
    strcpy_P(str, RETRIEVE_PROFILE(defaultMacros, findMacroID(profileId, buttonId)));
#endif
    return str;
}

#if SD_ENABLED

// check if a file exists
bool macroretriever::checkConnection(const char *fileName)
{
    File f = SD.open(fileName);
    if (!f)
    {
        SSprintf("Error opening file\n");
        return 0;
    }
    f.close();
    return 1;
}

int macroretriever::retrieveLinePos(int line, const char *fileName)
{
    File f = SD.open(fileName);
    int pos = -1;
    if (!f)
    {
        SSprintf("Error opening file\n");
        return pos;
    }
    int curline = 0;
    line--; // the first line doesn't contain \n
    if (line == 0)
    {
        pos = 0;
    }
    else
    {
        while (curline < line)
        {
            f.readStringUntil('\n');
            curline++;
        }
        pos = f.position();
    }
    f.close();
    return pos;
}

// read specified line from file
char *macroretriever::readLine(int lineNumber, const char *fileName)
{
    int pos = retrieveLinePos(lineNumber, fileName);
    if (pos == -1)
    {
        return NULL;
    }
    SSprintf("Reading line %d from file %s\n", lineNumber, fileName);
    File f = SD.open(fileName);
    memset(str, 0, sizeof(str));
    f.seek(pos);
    f.readBytesUntil('\n', str, MACRO_MAX_SIZE);
    // remove the \r from the end of the string if it exists
    if (str[strlen(str) - 1] == '\r')
        str[strlen(str) - 1] = '\0';
    SSprintf("%s", str);
    f.close();
    return str;
}
#if DEBUG
// print file contents to serial monitor
void macroretriever::printFile(const char *fileName)
{
    int linecount = 0;
    File f = SD.open(fileName);
    if (!f)
    {
        SSprintf("Error opening file\n");
        return;
    }
    while (f.available())
    {
        char c = f.read();
        if (c == '\n')
        {
            SSprintf("\n");
            linecount++;
        }
        else
            SSprintf("%c", c);
    }
    f.close();
    SSprintf("Lines: %d\n", linecount);
}

void macroretriever::SDFileInfo()
{
    SSprintf("\n");
    SSprintf("File List:\n");
    SSprintf("----------\n");
    File root = SD.open("/");
    if (!root)
    {
        SSprintf("Error opening root\n");
        return;
    }
    File f = root.openNextFile();
    while (f)
    {
        if (f.isDirectory())
        {
            SSprintf("[%s]\n", f.name());
        }
        else
        {
            if (strcasecmp(f.name(), DEFAULT_FILE) == 0)
                SSprintf("*%s\n", f.name());
            else
                SSprintf("%s\n", f.name());
        }
        f = root.openNextFile();
    }
    SSprintf("\n");
}

#endif
#endif
#endif