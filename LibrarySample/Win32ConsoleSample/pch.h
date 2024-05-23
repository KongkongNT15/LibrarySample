#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <Windows.h>

#define TAG_MACRO "?macro"
#define CALL_BY_ANSI_OR_UNICODE "ANSI‚ÆUNICODE‚ÌŒÄ‚Ñ•ª‚¯"

#define MacroHelper(x) #x
#define Macro(x) MacroHelper(x)

#define PutMacro(x, message) puts(#x); puts(MacroHelper(x)); puts(message)

int IsConsole();
void SetIsConsole(int value);

int IsEqualStringA(const char* left, const char* right);
int IsEqualStringW(const wchar_t* left, const wchar_t* right);

int RunSample(const char* headerTag, const char* sampleTag);

int NotFound(const char* tag);

int RunWinuserSample(const char* tag);