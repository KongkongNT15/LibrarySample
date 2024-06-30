#include "pch.h"

int IsShiftJisMultiByteChar(int c)
{
    return (0x81 <= c && c <= 0x9F) || (0xE0 <= c && c <= 0xEC);
}