#include "pch.h"

void Kongkong::SetAsCenter(HWND hChild, HWND hParent, int x, int y)
{
    double kakudairitu = GetDpiForWindow(hParent) / 96.0;

    x = (int)(kakudairitu * x);
    y = (int)(kakudairitu * y);

    RECT parentClientRect, childRect;
    int x1, y1;
    int width, height;

    GetClientRect(hParent, &parentClientRect);
    GetWindowRect(hChild, &childRect);

    width = childRect.right - childRect.left;
    height = childRect.bottom - childRect.top;
    x1 = (parentClientRect.right - width) / 2;
    y1 = (parentClientRect.bottom - height) / 2;

    if (!SetWindowPos(hChild, NULL, x1 + x, y1 + y, width, height, SWP_NOZORDER)) [[unlikely]] throw Exception(L"SetAsCenter()が失敗しました");
}