#include "pch.h"

int NotFound(const char* name)
{
    fprintf(stderr, "%s��������܂���ł���\n", name);
    fputs("�ӂ��I�H����\n", stderr);

    return -1;
}