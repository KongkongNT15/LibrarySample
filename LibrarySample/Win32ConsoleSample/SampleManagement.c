#include "pch.h"

static int isConsole = 0;

int IsConsole()
{
    return isConsole;
}

void SetIsConsole(int value)
{
    isConsole = value;
}

int IsEqualStringA(const char* left, const char* right)
{
    return strcmp(left, right) == 0;
}

int IsEqualStringW(const wchar_t* left, const wchar_t* right)
{
    return wcscmp(left, right) == 0;
}

int NotFound(const char* tag)
{
    fprintf(stderr, "\"%s\"‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½\n", tag);

    return -1;
}

int RunSample(const char* headerTag, const char* sampleTag)
{
    if (IsEqualStringA(headerTag, "handleapi.h")) return RunHandleapiSample(sampleTag);
    if (IsEqualStringA(headerTag, "Winuser.h")) return RunWinuserSample(sampleTag);

    return NotFound(headerTag);
}