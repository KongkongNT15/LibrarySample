#include "pch.h"

int ExitFailure()
{
    fputs(ERROR_MESSAGE, stderr);
    return -1;
}