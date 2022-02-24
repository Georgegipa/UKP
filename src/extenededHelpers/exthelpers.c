#include "exthelpers.h"

/**
 * @brief strncpy terminated
 * WARNING EXTREMELY DANGEROUS IF BUF IS SMALLER THAN INTENDED
 * 
 * @param buf should be size+1
 * @param str 
 * @param size 
 */
void strncpy_T(char *buf,char str[],int size)
{
    strncpy(buf,str,size);
    buf[size+1]='\0';
}