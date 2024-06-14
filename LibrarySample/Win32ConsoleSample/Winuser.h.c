#include "pch.h"
#include "../Macros/WinUser.macro.h"

//GetDpiForSystem
static int f0(void)
{
    unsigned dpi = GetDpiForSystem();

    printf("�V�X�e����DPI: %u\n", dpi);
    printf("�g�嗦: %.0lf%%\n", dpi * 100.0 / 96.0);

    return 0;
}

int RunWinuserSample(const char* tag)
{
    if (IsEqualStringA(tag, "GetDpiForSystem")) return f0();

    if (IsEqualStringA(tag, TAG_MACRO)) return macro();

    return RunNotFound(tag);
}