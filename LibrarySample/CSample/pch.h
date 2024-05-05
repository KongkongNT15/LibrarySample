#ifndef __PCH__
#define __PCH__

#include <assert.h>
#include <errno.h>
#include <iso646.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef __MSVC__
#include <Windows.h>
#endif
#ifdef __UNIX__
#include <unistd.h>
#endif

int ExitFailure();

void getline(char* buffer, size_t maxLength);

int IsEqual(const char* left, const char* right);

int IsConsole();
void SetIsConsole(int value);

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
int iso646__h__run(FUNCNAME);
int stdbool__h__run(FUNCNAME);
int stdio__h__run(FUNCNAME);

/*
コピー元
https://www.iar.com/jp/knowledge/learn/programming/advanced-preprocessor-tips-and-tricks/
*/
#define MacroHelper(x) #x
#define Macro(x) MacroHelper(x)

#endif //!__PCH__