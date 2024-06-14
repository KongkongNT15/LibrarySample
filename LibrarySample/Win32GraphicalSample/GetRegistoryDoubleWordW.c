#include "pch.h"

BOOL GetRegistoryDoubleWordW(HKEY hKeyParent, const wchar_t* key, const wchar_t* name, DWORD* pData)
{
    DWORD length = sizeof(DWORD);
    HKEY  hKey = NULL;
    DWORD rc = RegOpenKeyEx(hKeyParent, key, 0, KEY_READ, &hKey);

    if (rc == ERROR_SUCCESS) {
        rc = RegQueryValueEx(hKey, name, NULL, NULL, (LPBYTE)(pData), &length);
    }

    RegCloseKey(hKey);

    return rc == ERROR_SUCCESS;
}