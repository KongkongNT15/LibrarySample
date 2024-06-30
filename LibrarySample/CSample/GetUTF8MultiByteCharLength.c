#include "pch.h"

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