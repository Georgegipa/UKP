#include <Arduino.h>
//TODO:add documentation
inline int toLowerCase(char a)
{
    return ((a >= 'A') && (a <= 'Z')) ? a += 32 : a;
}

inline int toUpperCase(char a)
{
    return ((a >= 'a') && (a <= 'z')) ? a -= 32 : a;
}

inline bool isDigit(char a)
{
    return ((a >= '0') && (a <= '9')) ? true : false;
}

inline int intfromPROGMEM(const int arr[],const int index )
{
    return pgm_read_byte(arr + index);
}