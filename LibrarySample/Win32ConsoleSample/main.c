#include "pch.h"

//argv[0] �A�v����
//argv[1] �t�H���_�[
//argv[2] �֐���
//argv[3] true: �R���\�[��, false: �A�v�����p�C�v
int main(int argc, char** argv)
{
    if (argc != 4) {
        fputs("�R�}���h���C�������̐�������������܂���\n", stderr);
        return -1;
    }

    if (IsEqualStringA(argv[3], "true")) SetIsConsole(1);
    else if (IsEqualStringA(argv[3], "false")) SetIsConsole(0);
    else {
        fputs("�R���\�[���ݒ肪����������܂���\n", stderr);
        return -1;
    }

    return RunSample(argv[1], argv[2]);
}