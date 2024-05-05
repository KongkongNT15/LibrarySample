#include "pch.h"
using namespace std;

//array1
static int f0(void)
{
    array<int, 5> arr = { 1, 2, 3, 7, 11 };

    cout << "arr:";
    for (auto const i : arr) {
        cout << ' ' << i;
    }
    cout << endl;

    return 0;
}

//array2
static int f1(void)
{
    array<int, 5> arr1 = { 1, 2, 3, 7, 11 };
    array<int, 5> arr2 = arr1;

    arr2[0] = 8;

    cout << "arr1:";
    for (int const& i : arr1) {
        cout << ' ' << i;
    }
    cout << endl;

    cout << "arr2:";
    for (int const& i : arr2) {
        cout << ' ' << i;
    }
    cout << endl;

    return 0;
}

//_E
static int f2(void)
{
    array<int, 3> arr1 = { 1, 2, 3 };
    array<int, 3> arr2 = { 5, 6, 8 };

    arr2 = arr1;

    arr2[0] = 9;

    cout << "arr1:";
    for (int const& i : arr1) {
        cout << ' ' << i;
    }
    cout << endl;

    cout << "arr2:";
    for (int const& i : arr2) {
        cout << ' ' << i;
    }
    cout << endl;

    return 0;
}

//_I1
static int f3(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << ' ' << arr[i];
    }
    cout << endl;

    return 0;
}

//_I2
static int f4(void)
{
    const array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << ' ' << arr[i];
    }
    cout << endl;

    return 0;
}

//at1
static int f5(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << ' ' << arr.at(i);
    }
    cout << endl;
    cout << endl;

    cout << "arr[100]:" << endl;
    try {
        cout << arr.at(100) << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

//at2
static int f6(void)
{
    const array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << ' ' << arr.at(i);
    }
    cout << endl;
    cout << endl;

    cout << "arr[100]:" << endl;
    try {
        cout << arr.at(100) << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

//back1
static int f7(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (int const& n : arr) {
        cout << ' ' << n;
    }
    cout << endl;

    cout << "arr.back: " << arr.back() << endl;

    return 0;
}

//back2
static int f8(void)
{
    const array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (int const& n : arr) {
        cout << ' ' << n;
    }
    cout << endl;

    cout << "arr.back: " << arr.back() << endl;

    return 0;
}

//begin1
static int f9(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        cout << ' ' << *iter;
    }
    cout << endl;

    return 0;
}

//begin2
static int f10(void)
{
    const array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        cout << ' ' << *iter;
    }
    cout << endl;

    return 0;
}

//cbegin, cend
static int f11(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (auto iter = arr.cbegin(); iter != arr.cend(); ++iter) {
        cout << ' ' << *iter;
    }
    cout << endl;

    return 0;
}

//crbegin, crend
static int f12(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (auto iter = arr.crbegin(); iter != arr.crend(); ++iter) {
        cout << ' ' << *iter;
    }
    cout << endl;

    return 0;
}

//data1
static int f13(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };
    int* p = arr.data();
    int* const end = p + arr.size();

    cout << "arr:";
    while (p != end) {
        cout << ' ' << *p;
        p++;
    }
    cout << endl;

    return 0;
}

//data2
static int f14(void)
{
    const array<int, 5> arr = { 1, 2, 3, 6, 8 };
    const int* p = arr.data();
    const int* const end = p + arr.size();

    cout << "arr:";
    while (p != end) {
        cout << ' ' << *p;
        p++;
    }
    cout << endl;

    return 0;
}

//empty
static int f15(void)
{
    array<int, 5> arr1{};
    array<int, 0> arr2;

    if (arr1.empty()) cout << "arr1‚Í‹ó‚Å‚·" << endl;
    else cout << "arr1‚Í‹ó‚Å‚Í‚ ‚è‚Ü‚¹‚ñ" << endl;

    if (arr2.empty()) cout << "arr2‚Í‹ó‚Å‚·" << endl;
    else cout << "arr2‚Í‹ó‚Å‚Í‚ ‚è‚Ü‚¹‚ñ" << endl;

    return 0;
}

//fill
static int f16(void)
{
    array<int, 5> arr{};

    arr.fill(26);

    cout << "arr:";
    for (int const& i : arr) {
        cout << ' ' << i;
    }
    cout << endl;

    return 0;
}

//front1
static int f17(void)
{
    array<int, 5> arr = { 7, 6, 9, 22, 54 };

    cout << "arr:";
    for (int const& n : arr) {
        cout << ' ' << n;
    }
    cout << endl;

    cout << "arr.front: " << arr.front() << endl;

    return 0;
}

//front2
static int f18(void)
{
    const array<int, 5> arr = { 7, 6, 9, 22, 54 };

    cout << "arr:";
    for (int const& n : arr) {
        cout << ' ' << n;
    }
    cout << endl;

    cout << "arr.front: " << arr.front() << endl;

    return 0;
}

//max_size
static int f19(void)
{
    array<int, 5> arr1 = { 7, 6, 9, 22, 54 };
    array<int, 2> arr2 = { 1, 4 };

    cout << "arr1.maxsize: " << arr1.max_size() << endl;
    cout << "arr2.maxsize: " << arr2.max_size() << endl;

    return 0;
}

//rbegin1, rend1
static int f20(void)
{
    array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (auto iter = arr.rbegin(); iter != arr.rend(); ++iter) {
        cout << ' ' << *iter;
    }
    cout << endl;

    return 0;
}

//rbegin2, rend2
static int f21(void)
{
    const array<int, 5> arr = { 1, 2, 3, 6, 8 };

    cout << "arr:";
    for (auto iter = arr.rbegin(); iter != arr.rend(); ++iter) {
        cout << ' ' << *iter;
    }
    cout << endl;

    return 0;
}

//size
static int f22(void)
{
    array<int, 5> arr1 = { 7, 6, 9, 22, 54 };
    array<int, 2> arr2 = { 1, 4 };

    cout << "arr1.size: " << arr1.size() << endl;
    cout << "arr2.size: " << arr2.size() << endl;

    return 0;
}

//swap
static int f23(void)
{
    array<int, 5> arr1 = { 7, 6, 9, 22, 54 };
    array<int, 5> arr2 = { 1, 4, 6, 13, 65 };

    arr1.swap(arr2);

    cout << "arr1:";
    for (int const& n : arr1) {
        cout << ' ' << n;
    }
    cout << endl;

    cout << "arr2:";
    for (int const n : arr2) {
        cout << ' ' << n;
    }
    cout << endl;

    return 0;
}

int array__class__run(FUNCNAME)
{
	if (IsEqualFuncName("array1")) return f0();
	if (IsEqualFuncName("array2")) return f1();
	if (IsEqualFuncName("_E")) return f2();
	if (IsEqualFuncName("_I1")) return f3();
	if (IsEqualFuncName("_I2")) return f4();
	if (IsEqualFuncName("at1")) return f5();
	if (IsEqualFuncName("at2")) return f6();
	if (IsEqualFuncName("back1")) return f7();
	if (IsEqualFuncName("back2")) return f8();
	if (IsEqualFuncName("begin1")) return f9();
	if (IsEqualFuncName("begin2")) return f10();
	if (IsEqualFuncName("cbegin")) return f11();
	if (IsEqualFuncName("crbegin")) return f12();
	if (IsEqualFuncName("data1")) return f13();
	if (IsEqualFuncName("data2")) return f14();
	if (IsEqualFuncName("empty")) return f15();
	if (IsEqualFuncName("fill")) return f16();
	if (IsEqualFuncName("front1")) return f17();
	if (IsEqualFuncName("front2")) return f18();
	if (IsEqualFuncName("max_size")) return f19();
	if (IsEqualFuncName("rbegin1")) return f20();
	if (IsEqualFuncName("rbegin2")) return f21();
	if (IsEqualFuncName("size")) return f22();
	if (IsEqualFuncName("swap")) return f23();

	return NotFound(FUNCNAMEVALUE);
}