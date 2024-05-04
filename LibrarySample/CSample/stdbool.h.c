#include "pch.h"

static int macro(void)
{
    puts("bool");
    puts(Macro(bool));
    puts("ê^ãUå^");

    puts("false");
    puts(Macro(false));
    puts("ãU");

    puts("true");
    puts(Macro(true));
    puts("ê^");
    
    return 0;
}

int stdbool__h__run(FUNCNAME)
{
    if (IsEqualFuncName(MACRO_FUNCTION)) return macro();
    return ExitFailure();
}