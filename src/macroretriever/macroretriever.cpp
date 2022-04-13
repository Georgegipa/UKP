#include "macroretriever.hpp"
#ifdef HID_ENABLED
#include "default_macros.h"
#include "macrosengine/profiles.hpp"
int maxProfiles = FLASH_PROFILES;
#include "macrosengine/macrosengine.hpp"
macroretriever Retriever;

void macroretriever::begin()
{
#if SD_ENABLED
    if (!SD.begin(10))
    {
        SSprintf("Card Mount Failed\n");
        sdCardFailed = 1;
        return;
    }
    else
    {
        SSprintf("Successfully mounted microSD\n");

#if DEBUG
        SDFileInfo();
#endif
        // find out how many lines are in a file
        maxProfiles = (getFileInfo() / (BUTTON_SUM - 1));
    }
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
    if (sdCardFailed) // if the file open has failed once dont try to open it again
    {
        strcpy_P(str, RETRIEVE_PROFILE(defaultMacros, findMacroID(profileId, buttonId)));
        return str;
    }
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
        if (!strcasecmp(fileName, DEFAULT_FILE)) // if the default file is not found, then sd is disconnected
        {
            sdCardFailed = 1;
            Profile.reset();
            maxProfiles = FLASH_PROFILES;
        }
        SSprintf("Times failed: %d\n", sdCardFailed);
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
    if (lineLen(lineNumber, fileName) > MACRO_MAX_SIZE)
    {
        LongMacro(pos, fileName);
        str[0] = '\0';
        return str;
    }
    File f = SD.open(fileName);
    memset(str, 0, sizeof(str));
    SSprintf("Line length:%d\n", lineLen(lineNumber, fileName));
    f.seek(pos);
    f.readBytesUntil('\n', str, MACRO_MAX_SIZE);
    replaceCarriageReturn();
    SSprintf("%s", str);
    f.close();
    return str;
}

// remove the \r from the end of the string if it exists
void macroretriever::replaceCarriageReturn(char replacement)
{
    if (str[strlen(str) - 1] == '\r')
        str[strlen(str) - 1] = replacement;
}

// check line length
int macroretriever::lineLen(int line, const char *filename)
{
    int pos = retrieveLinePos(line, filename);
    if (pos == -1)
    {
        return -1;
    }
    File f = SD.open(filename);
    f.seek(pos);
    int len = f.readStringUntil('\n').length();
    f.close();
    return len;
}

// Splits and loads strings longer than the max macro size
void macroretriever::LongMacro(int original_pos, const char *filename)
{
    File f = SD.open(filename);
    f.seek(original_pos);
    memset(str, 0, sizeof(str));
    int readBytes = f.readBytesUntil('\n', str, MACRO_MAX_SIZE);
    SSprintf("%d %s\n", readBytes, str);
    int pos = f.position();
    f.close();
    MA.parseMacro(str);
    while (readBytes >= 50) // while the next line is shorter than the current one
    {
        f = SD.open(filename);
        f.seek(pos);
        // read the next part of the string
        memset(str, 0, sizeof(str));
        readBytes = f.readBytesUntil('\n', str, MACRO_MAX_SIZE);
        replaceCarriageReturn('\n');
        MA.KeyboardPrint(str);
        SSprintf("%d %s\n", readBytes, str);
        pos = f.position();
        f.close();
    }
}

// print file contents to serial monitor
int macroretriever::getFileInfo(const char *fileName)
{
    int linecount = 0;
    File f = SD.open(fileName);
    if (!f)
    {
        SSprintf("Error opening file\n");
        return -1;
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
    return linecount;
}

#if DEBUG

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
    root.close();
}

#endif
#endif
#endif