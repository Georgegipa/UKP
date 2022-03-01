#include "helpers.h"

/**
 * @brief A null terminated strncpy
 * (Throws a warning if buf is smaller than desired length)
 *
 * @param buf The buffer in which the substring will be written
 * @param str The string to create the substring
 * @param size The size of the substring
 */
void strncpy_T(char *buf, char str[], int size)
{
    strncpy(buf, str, size); // return a warning if the buf is smaller than size+1
    buf[size] = '\0';
}

/**
 * @brief A terminated strncpy_P
 * (Throws a warning if buf is smaller than desired length)
 *
 * @param buf The buffer in which the substring will be written
 * @param str The string to create the substring
 * @param size The size of the substring
 */
void strncpy_PT(char *buf, char str[], int size)
{
    strncpy_P(buf, str, size); // return a warning if the buf is smaller than size+1
    buf[size] = '\0';
}

/**
 * @brief Behaves exactly like printf and prints results with Serial.print
 */
void SSprintf(const char *s, ...)
{
#if DEBUG
    va_list arg;
    va_start(arg, s);
    char buf[100];
    vsprintf(buf, s, arg);
    Serial.print(buf);
    va_end(arg);
#endif
}