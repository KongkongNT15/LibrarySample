#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <wchar.h>
#include <Windows.h>

int wmain(int argc, wchar_t** argv)
{
    if (argc != 5) {
        fputs("コマンドライン引数の数が正しくありません\n", stderr);
        return 1;
    }

    //argv[1]~argv[4]の文字列の長さの合計 + 3 + 1
    size_t length = 4;
    int i;

    for (i = 1; i < argc; i++) {
        length += wcslen(argv[i]);
    }

    wchar_t* args = malloc(length * sizeof(wchar_t));
    
    if (args == NULL) {
        fputs("メモリエラーが発生しました\n", stderr);
        return 1;
    }

    wchar_t* tmp = args;

    for (i = 1; i < argc; i++) {
        if (i == argc - 1) {
            swprintf(tmp, length - (tmp - args), L"%ls", argv[i]);
            continue;
        }
        tmp += swprintf(tmp, length - (tmp - args), L"%ls ", argv[i]);
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(
        NULL,
        args,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    )
        ) {
        fputs("プロセスの作成に失敗しました\n", stderr);
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD returns;
    GetExitCodeProcess(pi.hProcess, &returns);

    putchar('\n');
    printf("%ls (プロセス %u) は、コード %d で終了しました。\n", argv[1], pi.dwProcessId, returns);
    printf("このウィンドウを閉じるには、任意のキーを押してください...");

    (void)_getch();

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    free(args);

    return 0;
}