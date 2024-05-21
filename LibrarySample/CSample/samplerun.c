#include "pch.h"

static int isConsole = 0;

size_t getline(char* buffer, size_t bufferLength)
{
    size_t i, length;
    length = bufferLength - 1;
    i = 0;
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {

        if (i == length) break;

        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';

    return i;
}

size_t getwcsline(wchar_t* buffer, size_t bufferLength)
{
    size_t i, length;
    length = bufferLength - 1;
    i = 0;
    wint_t c;

    while ((c = getwchar()) != L'\n' && c != WEOF) {

        if (i == length) break;

        buffer[i] = c;
        i++;
    }

    buffer[i] = L'\0';

    return i;
}

int IsEqual(const char* left, const char* right)
{
    return strcmp(left, right) == 0;
}

int IsConsole()
{
    return isConsole;
}

void SetIsConsole(int value)
{
    isConsole = value;
}

int NotFound(const char* name)
{
    fprintf(stderr, "%sが見つかりませんでした\n", name);
    return 1;
}

int ExitFailure()
{
    fputs(ERROR_MESSAGE, stderr);
    return -1;
}

int IsShiftJisMultiByteChar(int c)
{
    return (0x81 <= c && c <= 0x9F) || (0xE0 <= c && c <= 0xEC);
}

int GetUTF8MultiByteCharLength(int c)
{
    //負の値は存在しない
    if (c < 0) return EOF;
    if (c < 0x80) return 1;
    //これはマルチバイト文字の２バイト目以降なのでエラー
    if (c < 0xC0) return EOF;
    if (c < 0xE0) return 2;
    if (c < 0xF0) return 3;
    if (c < 0xF8) return 4;
    if (c < 0xFC) return 5;
    if (c < 0xFE) return 6;

    return EOF;
}

int RunSample(const char* folder, const char* func)
{
    if (IsEqualFolderName("assert.h")) return assert__h__run(func);
    if (IsEqualFolderName("ctype.h")) return ctype__h__run(func);
    if (IsEqualFolderName("errno.h")) return errno__h__run(func);
    if (IsEqualFolderName("float.h")) return float__h__run(func);
    if (IsEqualFolderName("inttypes.h")) return inttypes__h__run(func);
    if (IsEqualFolderName("iso646.h")) return iso646__h__run(func);
    if (IsEqualFolderName("stdbool.h")) return stdbool__h__run(func);
    if (IsEqualFolderName("stdio.h")) return stdio__h__run(func);
    if (IsEqualFolderName("stdnoreturn.h")) return stdnoreturn__h__run(func);

    return ExitFailure();
}