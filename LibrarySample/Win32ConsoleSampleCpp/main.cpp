#include "pch.h"
using namespace std;
using namespace Kongkong;

//argv[0] �A�v����
//argv[1] �t�H���_�[
//argv[2] �֐���
//argv[3] true: �R���\�[��, false: �A�v�����p�C�v
int main(int argc, char** argv)
{
    if (argc != 4) {
        cerr << "�R�}���h���C�������̐�������������܂���" << endl;
        cerr << "�ӂ��I�H����" << endl;

        return -1;
    }

    if (argv[3] == "true"sv) IsConsole = true;
    else if (argv[3] == "false"sv) IsConsole = false;
    else {
        cerr << "�R���\�[���ݒ肪����������܂���" << endl;
        cerr << "�ӂ��I�H����" << endl;

        return -1;
    }

    return RunSample(argv[1], argv[2]);
}