#ifndef __PCH__
#define __PCH__

//C++Ç≈<math.h>ÇÃêîäwíËêîÇégópÇ∑ÇÈ
#define _USE_MATH_DEFINES

#include <array>
#include <bitset>
#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>

#define CPP14 2014
#define CPP17 2017
#define CPP20 2020
#define CPP23 2023

#ifdef __MSVC__

#if _MSVC_LANG > 202002L
#define CPPVERSION CPP23
#endif

#ifndef CPPVERSION
#if _MSVC_LANG > 201703L
#define CPPVERSION CPP20
#endif
#endif

#ifndef CPPVERSION
#if _MSVC_LANG > 201402L
#define CPPVERSION CPP17
#endif
#endif

#ifndef CPPVERSION
#define CPPVERSION CPP14
#endif

#endif //__MSVC__

#define HAS_CPP23 CPPVERSION >= CPP23
#define HAS_CPP20 CPPVERSION >= CPP20
#define HAS_CPP17 CPPVERSION >= CPP17
#define HAS_CPP14 CPPVERSION >= CPP14

#if HAS_CPP17
#include <any>
#endif

#if HAS_CPP20
#include <bit>
#endif

#if HAS_CPP23
#include <print>
#endif

extern bool IsConsole;

#define FUNCNAME const char* funcName
#define FUNCNAMEVALUE funcName
#define IsEqualFolderName(x) IsEqual(x, folder)
#define IsEqualFuncName(x) IsEqual(x, funcName)

bool IsEqual(const char* left, const char* right);
int NotFound(const char* funcName);
int RunSample(const char* folder, const char* func);

int any__class__run(FUNCNAME);
int any__hpp__run(FUNCNAME);
int array__class__run(FUNCNAME);
int array__hpp__run(FUNCNAME);
int bad_any_cast__class__run(FUNCNAME);
int bad_cast__class__run(FUNCNAME);
int bad_typeid__class__run(FUNCNAME);
int bit__hpp__run(FUNCNAME);
int bitset__class__run(FUNCNAME);
int bitset__hpp__run(FUNCNAME);
int exception__class__run(FUNCNAME);
int type_info__class__run(FUNCNAME);

#endif //!__PCH__