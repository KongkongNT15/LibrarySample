#include "pch.h"

int RunNotFound(const char* tag)
{
    fprintf(stderr, "\"%s\"��������܂���ł���\n", tag);
    fputs("�ӂ��I�H����\n", stderr);

    return -1;
}