#include "pch.h"

static int macro(void)
{
    PutMacro(CharLower, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(MessageBox, CALL_BY_ANSI_OR_UNICODE);

    return 0;
}

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

    return NotFound(tag);
}