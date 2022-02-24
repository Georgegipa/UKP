#include <Arduino.h>
//TODO:add documentation

inline int intfromPROGMEM(const int arr[],const int index )
{
    return pgm_read_byte(arr + index);
}