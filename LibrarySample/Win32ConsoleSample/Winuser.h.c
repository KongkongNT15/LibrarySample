#include "pch.h"
#include "../Macros/WinUser.macro.h"

//GetDpiForSystem
static int f0(void)
{
    unsigned dpi = GetDpiForSystem();

    printf("ƒVƒXƒeƒ€‚ÌDPI: %u\n", dpi);
    printf("Šg‘å—¦: %.0lf%%\n", dpi * 100.0 / 96.0);

    return 0;
}

int RunWinuserSample(const char* tag)
{
    if (IsEqualStringA(tag, "GetDpiForSystem")) return f0();

    if (IsEqualStringA(tag, TAG_MACRO)) return macro();

    return RunNotFound(tag);
}