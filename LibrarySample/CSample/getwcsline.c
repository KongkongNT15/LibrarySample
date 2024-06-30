#include "pch.h"

size_t getwcsline(wchar_t* buffer, size_t bufferLength)
{
    size_t i, length;
    length = bufferLength - 1;
    i = 0;
    wint_t c;

    while ((c = getwchar()) != L'\n' && c != WEOF) {

        if (i == length) break;

        buffer[i] = c;
        i++;
    }

    buffer[i] = L'\0';

    return i;
}