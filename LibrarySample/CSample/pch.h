#ifndef __PCH__
#define __PCH__

#include <errno.h>
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

int RunSample(const char* folder, const char* func);


#define ERROR_MESSAGE "サンプルの実行時にエラーが発生しました\n"

#define FUNCNAME const char* funcName
#define IsEqualFolderName(x) IsEqual(x, folder)
#define IsEqualFuncName(x) IsEqual(x, funcName)

#define MACRO_FUNCTION "?macro"

int stdbool__h__run(FUNCNAME);
int stdio__h__run(FUNCNAME);

/*
コピー元
https://www.iar.com/jp/knowledge/learn/programming/advanced-preprocessor-tips-and-tricks/
*/
#define MacroHelper(x) #x
#define Macro(x) MacroHelper(x)

#endif //!__PCH__