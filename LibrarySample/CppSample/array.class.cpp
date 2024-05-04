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

int array__class__run(FUNCNAME)
{
	if (IsEqualFuncName("array1")) return f0();
	if (IsEqualFuncName("array2")) return f1();
	if (IsEqualFuncName("_E")) return f2();
	if (IsEqualFuncName("_I1")) return f3();
	if (IsEqualFuncName("_I2")) return f4();

	return NotFound(FUNCNAMEVALUE);
}