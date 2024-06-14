#pragma once

#include <locale.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <Windows.h>

#include "../Macros/MacroDefinition.h"

extern int IsConsole;

size_t GetLineA(char* buffer, size_t bufferCount);
size_t GetLineW(wchar_t* buffer, size_t bufferCount);

int IsEqualStringA(const char* left, const char* right);
int IsEqualStringW(const wchar_t* left, const wchar_t* right);

int RunSample(const char* headerTag, const char* sampleTag);

int RunNotFound(const char* tag);

int RunFileapiSample(const char* tag);
int RunHandleapiSample(const char* tag);
int RunWinuserSample(const char* tag);