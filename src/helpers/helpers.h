#pragma once
#include "settings.h"
#include <Arduino.h>
#include <string.h>

void strncpy_T(char *buf,char str[],int size);

/**
 * @brief Read a PROGMEM_INT (const int PROGMEM array) like a normal array.
 * A replacement for array reading array[i] -> intfromPROGMEM(array,i)
 * 
 * @param arr The PROGMEM_INT to read from
 * @param index The index value of the PROGMEM_INT array to read.
 * @return int The value strored in PROGMEM_INT array.
 */
inline int intfromPROGMEM(const int arr[],const int index)
{
    return pgm_read_byte(arr + index);
}