#include "pch.h"

BOOL GetArgs(wchar_t** pHeaderTag, wchar_t** pSampleTag)
{
    wchar_t* p = GetCommandLine();
    size_t length = wcslen(p);
    wchar_t* end = p + length;
    int count = 0;
    wchar_t* args[3];

    while (p != end) {
        if (count > 3) return FALSE;

        BOOL added = FALSE;
        if (*p != L' ') {
            if (*p == L'"') {
                for (wchar_t* q = p + 1; q != end; ++q) {
                    if (*q == L'\"') {
                        wchar_t* tmp = malloc(sizeof(wchar_t) * ((q - p) + 1));
                        if (tmp == NULL) return FALSE;

                        memcpy(tmp, p + 1, sizeof(wchar_t) * (q - p - 1));

                        tmp[q - p - 1] = L'\0';

                        args[count++] = tmp;

                        puts("s");

                        p = q;
                        break;
                    }
                }
            }
            else {
                for (wchar_t* q = p; q != end; ++q) {
                    if (*q == L' ' || *q == L'\0') {

                        wchar_t* tmp = malloc(sizeof(wchar_t) * ((q - p) + 1));
                        if (tmp == NULL) return FALSE;

                        memcpy(tmp, p, sizeof(wchar_t) * (q - p));

                        tmp[q - p] = L'\0';
                        p = q - 1;
                        added = TRUE;

                        args[count++] = tmp;

                        break;
                    }
                }
                if (!added) {
                    wchar_t* tmp = malloc(sizeof(wchar_t) * ((end - p) + 1));
                    if (tmp == NULL) return FALSE;

                    memcpy(tmp, p, sizeof(wchar_t) * (end - p));

                    tmp[end - p] = L'\0';

                    args[count++] = tmp;

                    break;
                }

            }


        }

        p++;
    }

    if (count != 3) return FALSE;

    *pHeaderTag = args[1];
    *pSampleTag = args[2];

    return TRUE;
}