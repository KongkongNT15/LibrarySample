#include "pch.h"

int RunNotFound(const char* tag)
{
    fprintf(stderr, "\"%s\"が見つかりませんでした\n", tag);
    fputs("ふぁ！？っく\n", stderr);

    return -1;
}