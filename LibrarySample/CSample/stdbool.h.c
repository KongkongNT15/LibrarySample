#include "pch.h"

static int macro(void)
{
    puts("bool");
    puts(Macro(bool));
    puts("�^�U�^");

    puts("false");
    puts(Macro(false));
    puts("�U");

    puts("true");
    puts(Macro(true));
    puts("�^");
    
    return 0;
}

int stdbool__h__run(FUNCNAME)
{
    if (IsEqualFuncName(MACRO_FUNCTION)) return macro();
    return ExitFailure();
}