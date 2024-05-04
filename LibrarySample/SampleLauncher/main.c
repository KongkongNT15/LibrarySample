#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <wchar.h>
#include <Windows.h>

int wmain(int argc, wchar_t** argv)
{
    if (argc != 5) {
        fputs("�R�}���h���C�������̐�������������܂���\n", stderr);
        return 1;
    }

    //argv[1]~argv[4]�̕�����̒����̍��v + 3 + 1
    size_t length = 4;
    int i;

    for (i = 1; i < argc; i++) {
        length += wcslen(argv[i]);
    }

    wchar_t* args = malloc(length * sizeof(wchar_t));
    
    if (args == NULL) {
        fputs("�������G���[���������܂���\n", stderr);
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
        fputs("�v���Z�X�̍쐬�Ɏ��s���܂���\n", stderr);
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD returns;
    GetExitCodeProcess(pi.hProcess, &returns);

    putchar('\n');
    printf("%ls (�v���Z�X %u) �́A�R�[�h %d �ŏI�����܂����B\n", argv[1], pi.dwProcessId, returns);
    printf("���̃E�B���h�E�����ɂ́A�C�ӂ̃L�[�������Ă�������...");

    (void)_getch();

    // Close process and thread handles. 
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    free(args);

    return 0;
}