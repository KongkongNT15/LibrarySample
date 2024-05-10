#include "pch.h"
using namespace std;

#if HAS_CPP20

//bit_cast
static int f0(void)
{
    double x;
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> x;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    n = bit_cast<unsigned long long>(x);

    cout << "x = " << x << endl;
    cout << "n = " << n << endl;

    return 0;
}

//byteswap
static int f1(void)
{
#if HAS_CPP23
    int64_t n = 0x123456789ABCDEF;

    int64_t m = byteswap(n);

    cout << hex << uppercase;
    cout << "n: 0x" << n << endl;
    cout << "m: 0x" << m << endl;

    return 0;

#else
    return 0;
#endif
}

//has_single_bit
static int f2(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n(10�i��):" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n(2�i��):" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;
    cout << endl;

    cout << "has_single_bit:" << endl;
    cout << boolalpha << has_single_bit(n) << endl;

    return 0;
}

//bit_ceil
static int f3(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n:" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n�ȏ��2�ׂ̂���:" << endl;
    cout << bit_ceil(n) << endl;

    return 0;
}

//bit_floor
static int f4(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n:" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n�ȉ���2�ׂ̂���:" << endl;
    cout << bit_floor(n) << endl;

    return 0;
}

//bit_width
static int f5(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n(10�i��):" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n(2�i��):" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;
    cout << endl;

    cout << "�K�v�ȃr�b�g��:" << endl;
    cout << bit_width(n) << endl;

    return 0;
}

//rotl
static int f6(void)
{
    unsigned long value = 0b10110111101101011110100100100011u;
    int shift;

    if (IsConsole) cout << "�V�t�g����r�b�g�������: ";
    cin >> shift;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << bitset<sizeof(unsigned int) * 8>(value) << endl;
    cout << bitset<sizeof(unsigned int) * 8>(rotl(value, shift));

    return 0;
}

//rotr
static int f7(void)
{
    unsigned long value = 0b10110111101101011110100100100011u;
    int shift;

    if (IsConsole) cout << "�V�t�g����r�b�g�������: ";
    cin >> shift;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << bitset<sizeof(unsigned int) * 8>(value) << endl;
    cout << bitset<sizeof(unsigned int) * 8>(rotr(value, shift));

    return 0;
}

//countl_zero
static int f8(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n(10�i��):" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n(2�i��):" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;
    cout << endl;

    cout << "�ŏ�ʂ���̃[���̘A���r�b�g��:" << endl;
    cout << countl_zero(n) << endl;

    return 0;
}

//countl_one
static int f9(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n(10�i��):" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n(2�i��):" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;
    cout << endl;

    cout << "�ŏ�ʂ����1�̘A���r�b�g��:" << endl;
    cout << countl_one(n) << endl;

    return 0;
}

//countr_zero
static int f10(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n(10�i��):" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n(2�i��):" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;
    cout << endl;

    cout << "�ŉ��ʂ���̃[���̘A���r�b�g��:" << endl;
    cout << countr_zero(n) << endl;

    return 0;
}

//countr_one
static int f11(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n(10�i��):" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n(2�i��):" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;
    cout << endl;

    cout << "�ŉ��ʂ����1�̘A���r�b�g��:" << endl;
    cout << countr_one(n) << endl;

    return 0;
}

//popcount
static int f12(void)
{
    unsigned long long n;

    if (IsConsole) cout << "���������: ";
    cin >> n;

    if (cin.fail()) {
        cerr << "�l�����������͂���܂���ł���" << endl;
        return 1;
    }

    cout << "n(10�i��):" << endl;
    cout << n << endl;
    cout << endl;

    cout << "n(2�i��):" << endl;
    cout << bitset<sizeof(unsigned long long) * 8>(n) << endl;
    cout << endl;

    cout << "1�̐�:" << endl;
    cout << popcount(n) << endl;

    return 0;
}

#endif

int bit__hpp__run(FUNCNAME)
{
#if HAS_CPP20
    if (IsEqualFuncName("bit_cast")) return f0();
    if (IsEqualFuncName("bit_ceil")) return f3();
    if (IsEqualFuncName("bit_floor")) return f4();
    if (IsEqualFuncName("bit_width")) return f5();
    if (IsEqualFuncName("byteswap")) return f1();
    if (IsEqualFuncName("countl_one")) return f9();
    if (IsEqualFuncName("countl_zero")) return f8();
    if (IsEqualFuncName("countr_one")) return f11();
    if (IsEqualFuncName("countr_zero")) return f10();
    if (IsEqualFuncName("has_single_bit")) return f2();
    if (IsEqualFuncName("popcount")) return f12();
    if (IsEqualFuncName("rotl")) return f6();
    if (IsEqualFuncName("rotr")) return f7();
#endif

	return NotFound(FUNCNAMEVALUE);
}