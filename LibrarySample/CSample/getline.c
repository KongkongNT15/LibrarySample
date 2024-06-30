#include "pch.h"

size_t getline(char* buffer, size_t bufferLength)
{
    size_t i, length;
    length = bufferLength - 1;
    i = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {

        if (i == length) break;

        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';

    return i;
}