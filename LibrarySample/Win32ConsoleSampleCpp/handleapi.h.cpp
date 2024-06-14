#include "pch.h"
#include "../Macros/handleapi.macro.h"

int Kongkong::Handleapi::RunSample(const char* tag)
{
    if (IsEqualStringA(tag, TAG_MACRO)) return macro();

    return 0;
}