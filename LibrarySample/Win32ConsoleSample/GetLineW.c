#include "pch.h"

size_t GetLineW(wchar_t* buffer, size_t bufferCount)
{
    size_t maxLength = bufferCount - 1;
    size_t count = 0;
    wchar_t c;

    while ((c = getwchar()) != L'\n' && c != WEOF) {
        if (count == maxLength) break;

        buffer[count] = c;
        count++;
    }

    buffer[count] = L'\0';

    return count;
}