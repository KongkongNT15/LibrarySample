#include "pch.h"

int GetUTF8MultiByteCharLength(int c)
{
    //���̒l�͑��݂��Ȃ�
    if (c < 0) return EOF;
    if (c < 0x80) return 1;
    //����̓}���`�o�C�g�����̂Q�o�C�g�ڈȍ~�Ȃ̂ŃG���[
    if (c < 0xC0) return EOF;
    if (c < 0xE0) return 2;
    if (c < 0xF0) return 3;
    if (c < 0xF8) return 4;
    if (c < 0xFC) return 5;
    if (c < 0xFE) return 6;

    return EOF;
}