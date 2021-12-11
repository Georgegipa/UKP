#include "macros.h"

force_inline inline int toLowerCase(char a)
{
    return ((a >= 'A') && (a <= 'Z')) ? a += 32 : a;
}

force_inline inline int toUpperCase(char a)
{
    return ((a >= 'a') && (a <= 'z')) ? a -= 32 : a;
}