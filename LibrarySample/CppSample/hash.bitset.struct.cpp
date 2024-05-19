#include "pch.h"
using namespace std;

//_C
static int f0(void)
{
    bitset<32> bs;

    if (IsConsole) cout << "ビット値を入力: ";
    cin >> bs;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        return 1;
    }

    cout << "bs:         " << bs << endl;
    cout << "ハッシュ値: " << hash<bitset<32>>()(bs) << endl;

    return 0;
}

int hash__bitset__struct__run(FUNCNAME)
{
    if (IsEqualFuncName("_C")) return f0();

    return NotFound(FUNCNAMEVALUE);
}