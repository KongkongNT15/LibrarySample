#include "pch.h"

static int isConsole = 0;

void getline(char* buffer, size_t maxLength)
{
    size_t i, length;
    length = maxLength - 1;
    i = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {

        if (i == length) break;

        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';
}

int IsEqual(const char* left, const char* right)
{
    return strcmp(left, right) == 0;
}

int IsConsole()
{
    return isConsole;
}

void SetIsConsole(int value)
{
    isConsole = value;
}

int ExitFailure()
{
    fputs(ERROR_MESSAGE, stderr);
    return -1;
}

int RunSample(const char* folder, const char* func)
{
    if (IsEqualFolderName("stdbool.h")) return stdbool__h__run(func);
    if (IsEqualFolderName("stdio.h")) return stdio__h__run(func);

    return ExitFailure();
}