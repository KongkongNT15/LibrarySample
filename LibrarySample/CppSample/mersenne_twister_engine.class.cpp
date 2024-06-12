#include "pch.h"
using namespace std;

//mersenne_twister_engine
static int f0(void)
{
    mt19937 mt;

    for (int i = 0; i < 10; i++) {
        cout << mt() << endl;
    }

    return 0;
}

//mersenne_twister_engine1
static int f1(void)
{
    unsigned seed;

    if(IsConsole) cout << "シード値: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    mt19937 mt{ seed };

    for (int i = 0; i < 10; i++) {
        cout << mt() << endl;
    }

    return 0;
}

//seed
static int f2(void)
{
    mt19937 mt;
    unsigned seed;

    if (IsConsole) cout << "シード値1: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値1を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    mt.seed(seed);

    for (int i = 0; i < 10; i++) {
        cout << mt() << endl;
    }
    cout << endl;

    if (IsConsole) cout << "シード値2: ";
    cin >> seed;

    if (!cin) {
        cerr << "シード値2を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    mt.seed(seed);

    for (int i = 0; i < 10; i++) {
        cout << mt() << endl;
    }

    return 0;
}

//discard
static int f3(void)
{
    mt19937 mt;
    unsigned long long nSkip;

    if (IsConsole) cout << "空回しする回数: ";
    cin >> nSkip;

    if (!cin) {
        cerr << "値を読み取れませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    mt.discard(nSkip);

    for (int i = 0; i < 10; i++) {
        cout << mt() << endl;
    }

    return 0;
}

//_LL
static int f4(void)
{
    mt19937 mt;

    cout << mt << endl;

    return 0;
}

//_RR
static int f5(void)
{
    mt19937 mt;
    
    try {
        if (IsConsole) cout << "シーケンスを入力: ";
        cin >> mt;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
        cerr << "状態が正しく設定されませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    if (!cin) {
        cerr << "状態が正しく設定されませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return 1;
    }

    for (int i = 0; i < 10; i++) {
        cout << mt() << endl;
    }

    return 0;
}

//max
static int f6(void)
{
    cout << mt19937::max() << endl;
    cout << mt19937_64::max() << endl;

    return 0;
}

//min
static int f7(void)
{
    cout << mt19937::min() << endl;
    cout << mt19937_64::min() << endl;

    return 0;
}

int mersenne_twister_engine__class__run(FUNCNAME)
{
    if (IsEqualFuncName("mersenne_twister_engine")) return f0();
    if (IsEqualFuncName("mersenne_twister_engine1")) return f1();
    if (IsEqualFuncName("_LL")) return f4();
    if (IsEqualFuncName("_RR")) return f5();
    if (IsEqualFuncName("discard")) return f3();
    if (IsEqualFuncName("max")) return f6();
    if (IsEqualFuncName("min")) return f7();
    if (IsEqualFuncName("seed")) return f2();

    return NotFound(FUNCNAMEVALUE);
}