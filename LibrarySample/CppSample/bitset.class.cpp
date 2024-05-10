#include "pch.h"
using namespace std;

//bitset1
static int f0(void)
{
    bitset<32> bs;

    cout << bs << endl;

    return 0;
}

//bitset2
static int f1(void)
{
    uint32_t value;

    if (IsConsole) cout << "整数を入力: ";
    cin >> value;

    if (cin.fail()) {
        cerr << "整数を読み取れませんでした" << endl;
        return 1;
    }

    cout << "value:" << endl;
    cout << value << endl;
    cout << endl;

    cout << "bitset:" << endl;
    cout << bitset<32>(value) << endl;

    return 0;
}

//bitset4
static int f2(void)
{
    bitset<8> bs{ "10011101" };

    cout << bs << endl;

    return 0;
}

//bitset3
static int f3(void)
{
    string str = "10011101";
    bitset<8> bs{ str };

    cout << bs << endl;

    return 0;
}

//bitset5
static int f4(void)
{
    bitset<8> bs1 = 0b10000000;

    bitset<8> bs2 = bs1;

    bs2[4] = true;

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;

    return 0;
}

//_NE
static int f5(void)
{
    bitset<128> bs1, bs2;

    if (IsConsole) cout << "bs1: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "bs1の値を正しく取り込めませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "bs2の値を正しく取り込めませんでした" << endl;
        return 1;
    }

    if (bs1 != bs2) cout << "bs1 != bs2" << endl;
    else cout << "bs1 == bs2" << endl;

    return 0;
}

//_EE
static int f6(void)
{
    bitset<128> bs1, bs2;

    if (IsConsole) cout << "bs1: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "bs1の値を正しく取り込めませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "bs2の値を正しく取り込めませんでした" << endl;
        return 1;
    }

    if (bs1 == bs2) cout << "bs1 == bs2" << endl;
    else cout << "bs1 != bs2" << endl;

    return 0;
}

//_E
static int f7(void)
{
    bitset<4> bs1 = 0b1011;
    bitset<4> bs2 = 0b0010;

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;
    cout << endl;

    bs1 = bs2;

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;

    return 0;
}

//_AE
static int f8(void)
{
    bitset<32> bs1, bs2;

    if (IsConsole) cout << "bs1を入力: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2を入力: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;
    cout << endl;

    bs1 &= bs2;

    cout << "bs1: " << bs1 << endl;

    return 0;
}

//_VE
static int f9(void)
{
    bitset<32> bs1, bs2;

    if (IsConsole) cout << "bs1を入力: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2を入力: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;
    cout << endl;

    bs1 |= bs2;

    cout << "bs1: " << bs1 << endl;

    return 0;
}

//_HE
static int f10(void)
{
    bitset<32> bs1, bs2;

    if (IsConsole) cout << "bs1を入力: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    if (IsConsole) cout << "bs2を入力: ";
    cin >> bs2;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;
    cout << endl;

    bs1 ^= bs2;

    cout << "bs1: " << bs1 << endl;

    return 0;
}

//_LLE
static int f11(void)
{
    bitset<32> bs{ "10111001101111100111011101000101" };
    size_t pos;

    if (IsConsole) cout << "シフトするビット数を入力: ";
    cin >> pos;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "値:" << endl;
    cout << bs << endl;

    bs <<= pos;

    cout << bs << endl;

    return 0;
}

//_RRE
static int f12(void)
{
    bitset<32> bs{ "10111001101111100111011101000101" };
    size_t pos;

    if (IsConsole) cout << "シフトするビット数を入力: ";
    cin >> pos;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "値:" << endl;
    cout << bs << endl;

    bs >>= pos;

    cout << bs << endl;

    return 0;
}

//set1
static int f13(void)
{
    bitset<12> bs = 0b101010101111;

    cout << bs << endl;

    bs.set();

    cout << bs << endl;

    return 0;
}

//set2
static int f14(void)
{
    bitset<8> bs;

    cout << bs << endl;

    bs.set(1);

    cout << bs << endl;

    return 0;
}

//reset1
static int f15(void)
{
    bitset<8> bs = 0b10111011;

    cout << bs << endl;

    bs.reset();

    cout << bs << endl;

    return 0;
}

//reset2
static int f16(void)
{
    bitset<8> bs = 255;

    cout << bs << endl;

    bs.reset(3);

    cout << bs << endl;

    return 0;
}

//_~
static int f17(void)
{
    bitset<128> bs1, bs2;

    if (IsConsole) cout << "値を入力: ";
    cin >> bs1;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    bs2 = ~bs1;

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;

    return 0;
}

//flip1
static int f18(void)
{
    bitset<128> bs;

    if (IsConsole) cout << "ビットを入力: ";
    cin >> bs;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "値:" << endl;
    cout << bs << endl;

    bs.flip();

    cout << bs << endl;

    return 0;
}

//flip2
static int f19(void)
{
    bitset<8> bs = 0b10101010;

    cout << bs << endl;

    bs.flip(1);
    bs.flip(6);

    cout << bs << endl;

    return 0;
}

//_I1
static int f20(void)
{
#if HAS_CPP23
    bitset<16> bs = 0b1010101010101010;

    bs[3] = true;
    bs[4] = true;

    for (size_t i = 0; i < bs.size(); ++i) {
        print("bs[{:02}] = {}\n", i, (unsigned)bs[i]);
    }

    return 0;
#else
    bitset<16> bs = 0b1010101010101010;

    bs[3] = true;
    bs[4] = true;

    for (size_t i = 0; i < bs.size(); ++i) {
        printf("bs[%02zu] = %u\n", i, (unsigned)bs[i]);
    }

    return 0;
#endif
}

//_I2
static int f21(void)
{
#if HAS_CPP23
    const bitset<16> bs = 0b1010101010101010;

    for (size_t i = 0; i < bs.size(); ++i) {
        print("bs[{:02}] = {}\n", i, (unsigned)bs[i]);
    }

    return 0;
#else
    const bitset<16> bs = 0b1010101010101010;

    for (size_t i = 0; i < bs.size(); ++i) {
        printf("bs[%02zu] = %u\n", i, (unsigned)bs[i]);
    }

    return 0;
#endif
}

//count 
static int f22(void)
{
    unsigned long long n;

    if (IsConsole) cout << "整数を入力: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    bitset<sizeof(unsigned long long) * 8> bs(n);

    cout << "n: " << endl;
    cout << n << endl;
    cout << endl;

    cout << "nのビット表現:" << endl;
    cout << bs << endl;
    cout << endl;

    cout << "true の個数:" << endl;
    cout << bs.count() << endl;

    return 0;
}

//size
static int f23(void)
{
    bitset<16> bs1;
    bitset<29> bs2;

    cout << "bs1.size: " << bs1.size() << endl;
    cout << "bs2.size: " << bs2.size() << endl;

    return 0;
}

//test
static int f24(void)
{
#if HAS_CPP23
    bitset<32> bs{ "10111001101111100111011101000101" };
    size_t index;

    if (IsConsole) cout << "インデックスを入力: ";
    cin >> index;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    try {
        print("bs[{}] = {}\n", index, (int)bs.test(index));
    }
    catch (out_of_range) {
        cerr << "無効なインデックスを指定しました" << endl;
        cerr << "指定したインデックス: " << index << endl;
        return 1;
    }

    return 0;
#else
    bitset<32> bs{ "10111001101111100111011101000101" };
    size_t index;

    if (IsConsole) cout << "インデックスを入力: ";
    cin >> index;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    try {
        printf("bs[%zu] = %d\n", index, (int)bs.test(index));
    }
    catch (out_of_range) {
        cerr << "無効なインデックスを指定しました" << endl;
        cerr << "指定したインデックス: " << index << endl;
        return 1;
    }

    return 0;
#endif
}

//all
static int f25(void)
{
    unsigned long long n;

    if (IsConsole) cout << "整数を入力: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    bitset<sizeof(unsigned long long) * 8> bs(n);

    cout << "n: " << endl;
    cout << n << endl;
    cout << endl;

    cout << "nのビット表現:" << endl;
    cout << bs << endl;
    cout << endl;

    cout << boolalpha;
    cout << "bs.all:" << endl;
    cout << bs.all() << endl;

    return 0;
}

//any
static int f26(void)
{
    unsigned long long n;

    if (IsConsole) cout << "整数を入力: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    bitset<sizeof(unsigned long long) * 8> bs(n);

    cout << "n: " << endl;
    cout << n << endl;
    cout << endl;

    cout << "nのビット表現:" << endl;
    cout << bs << endl;
    cout << endl;

    cout << boolalpha;
    cout << "bs.any:" << endl;
    cout << bs.any() << endl;

    return 0;
}

//none
static int f27(void)
{
    unsigned long long n;

    if (IsConsole) cout << "整数を入力: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    bitset<sizeof(unsigned long long) * 8> bs(n);

    cout << "n: " << endl;
    cout << n << endl;
    cout << endl;

    cout << "nのビット表現:" << endl;
    cout << bs << endl;
    cout << endl;

    cout << boolalpha;
    cout << "bs.none:" << endl;
    cout << bs.none() << endl;

    return 0;
}

//to_ulong
static int f28(void)
{
    bitset<32> bs;

    if (IsConsole) cout << "ビットを入力: ";
    cin >> bs;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "n(bit):" << endl;
    cout << bs << endl;
    cout << endl;

    cout << "n(10進数):" << endl;
    cout << bs.to_ulong() << endl;

    return 0;
}

//to_ullong
static int f29(void)
{
    bitset<64> bs;

    if (IsConsole) cout << "ビットを入力: ";
    cin >> bs;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "n(bit):" << endl;
    cout << bs << endl;
    cout << endl;

    cout << "n(10進数):" << endl;
    cout << bs.to_ullong() << endl;

    return 0;
}

//to_string
static int f30(void)
{
    unsigned long long n;

    if (IsConsole) cout << "整数を入力: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    bitset<sizeof(unsigned long long) * 8> bs{ n };

    cout << "bs: " << bs.to_string() << endl;
    cout << "bs: " << bs.to_string('F', 'T') << endl;

    return 0;
}

//_LL
static int f31(void)
{
    bitset<32> bs{ "10111001101111100111011101000101" };
    size_t shift;

    if (IsConsole) cout << "シフトするビット数を入力: ";
    cin >> shift;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "値:" << endl;
    cout << bs << endl;
    cout << (bs << shift) << endl;

    return 0;
}

//_RR
static int f32(void)
{
    bitset<32> bs{ "10111001101111100111011101000101" };
    size_t shift;

    if (IsConsole) cout << "シフトするビット数を入力: ";
    cin >> shift;

    if (cin.fail()) {
        cerr << "値が正しく入力されませんでした" << endl;
        return 1;
    }

    cout << "値:" << endl;
    cout << bs << endl;
    cout << (bs >> shift) << endl;

    return 0;
}

int bitset__class__run(FUNCNAME)
{
    if (IsEqualFuncName("bitset1")) return f0();
    if (IsEqualFuncName("bitset2")) return f1();
    if (IsEqualFuncName("bitset3")) return f3();
    if (IsEqualFuncName("bitset4")) return f2();
    if (IsEqualFuncName("bitset5")) return f4();
    if (IsEqualFuncName("_NE")) return f5();
    if (IsEqualFuncName("_EE")) return f6();
    if (IsEqualFuncName("_E")) return f7();
    if (IsEqualFuncName("_AE")) return f8();
    if (IsEqualFuncName("_VE")) return f9();
    if (IsEqualFuncName("_HE")) return f10();
    if (IsEqualFuncName("_LL")) return f31();
    if (IsEqualFuncName("_LLE")) return f11();
    if (IsEqualFuncName("_RR")) return f32();
    if (IsEqualFuncName("_RRE")) return f12();
    if (IsEqualFuncName("_~")) return f17();
    if (IsEqualFuncName("_I1")) return f20();
    if (IsEqualFuncName("_I2")) return f21();
    if (IsEqualFuncName("all")) return f25();
    if (IsEqualFuncName("any")) return f26();
    if (IsEqualFuncName("count")) return f22();
    if (IsEqualFuncName("flip1")) return f18();
    if (IsEqualFuncName("flip2")) return f19();
    if (IsEqualFuncName("none")) return f27();
    if (IsEqualFuncName("reset1")) return f15();
    if (IsEqualFuncName("reset2")) return f16();
    if (IsEqualFuncName("set1")) return f13();
    if (IsEqualFuncName("set2")) return f14();
    if (IsEqualFuncName("size")) return f23();
    if (IsEqualFuncName("test")) return f24();
    if (IsEqualFuncName("to_string")) return f30();
    if (IsEqualFuncName("to_ullong")) return f29();
    if (IsEqualFuncName("to_ulong")) return f28();

    return NotFound(FUNCNAMEVALUE);
}