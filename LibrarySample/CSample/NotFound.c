#include "pch.h"

int NotFound(const char* name)
{
    fprintf(stderr, "%sが見つかりませんでした\n", name);
    fputs("ふぁ！？っく\n", stderr);

    return -1;
}