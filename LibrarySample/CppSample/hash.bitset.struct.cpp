#include "pch.h"
using namespace std;

//_C
static int f0(void)
{
    bitset<32> bs;

    if (IsConsole) cout << "�r�b�g�l�����: ";
    cin >> bs;

    if (!cin) {
        cerr << "�l��ǂݎ��܂���ł���" << endl;
        return 1;
    }

    cout << "bs:         " << bs << endl;
    cout << "�n�b�V���l: " << hash<bitset<32>>()(bs) << endl;

    return 0;
}

int hash__bitset__struct__run(FUNCNAME)
{
    if (IsEqualFuncName("_C")) return f0();

    return NotFound(FUNCNAMEVALUE);
}