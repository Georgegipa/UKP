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

inline int intfromPROGMEM(const int arr[],const int moved )
{
    return pgm_read_byte(arr + moved);
}