#include "pch.h"

size_t GetLineA(char* buffer, size_t bufferCount)
{
    size_t maxLength = bufferCount - 1;
    size_t count = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (count == maxLength) break;

        buffer[count] = c;
        count++;
    }

    buffer[count] = '\0';

    return count;
}