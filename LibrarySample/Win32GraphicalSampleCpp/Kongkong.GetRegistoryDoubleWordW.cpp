#include "pch.h"

DWORD Kongkong::GetRegistoryDoubleWordW(HKEY hKeyParent, const wchar_t* key, const wchar_t* name)
{
    DWORD value;
    DWORD length = sizeof(DWORD);
    HKEY  hKey = nullptr;
    DWORD rc = RegOpenKeyEx(hKeyParent, key, 0, KEY_READ, &hKey);

    if (rc == ERROR_SUCCESS) {
        rc = RegQueryValueEx(hKey, name, nullptr, nullptr, (LPBYTE)&value, &length);
    }

    RegCloseKey(hKey);

    if (rc != ERROR_SUCCESS) [[unlikely]] throw Exception();

    return value;
}