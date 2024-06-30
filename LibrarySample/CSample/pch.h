#ifndef __PCH__
#define __PCH__

#include <assert.h>
#include <errno.h>
#include <fenv.h>
#include <float.h>
#include <inttypes.h>
#include <iso646.h>
#include <locale.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#ifdef __MSVC__
#include <Windows.h>
#endif
#ifdef __UNIX__
#include <unistd.h>
#endif

extern int IsConsole;

int ExitFailure();

size_t getline(char* buffer, size_t bufferLength);
size_t getwcsline(wchar_t* buffer, size_t bufferLength);

int IsEqual(const char* left, const char* right);

int NotFound(const char* name);

int RunSample(const char* folder, const char* func);

//Shift_Jis文字がマルチバイト文字の1文字目かを判定
int IsShiftJisMultiByteChar(int c);

//UTF-8文字が何バイト文字がを判定
int GetUTF8MultiByteCharLength(int c);

#define ERROR_MESSAGE "サンプルの実行時にエラーが発生しました\n"

#define FUNCNAME const char* funcName
#define IsEqualFolderName(x) IsEqual(x, folder)
#define IsEqualFuncName(x) IsEqual(x, funcName)
#define FUNCNAMEVALUE funcName

#define MACRO_FUNCTION "?macro"

int assert__h__run(FUNCNAME);
int ctype__h__run(FUNCNAME);
int errno__h__run(FUNCNAME);
int float__h__run(FUNCNAME);
int inttypes__h__run(FUNCNAME);
int iso646__h__run(FUNCNAME);
int stdbool__h__run(FUNCNAME);
int stdio__h__run(FUNCNAME);
int stdnoreturn__h__run(FUNCNAME);

/*
コピー元
https://www.iar.com/jp/knowledge/learn/programming/advanced-preprocessor-tips-and-tricks/
*/
#define MacroHelper(x) #x
#define Macro(x) MacroHelper(x)

#define PutMacro(x, message) puts(#x); puts(MacroHelper(x)); puts(message)

#endif //!__PCH__