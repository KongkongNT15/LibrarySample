#include "pch.h"
#include "../Macros/fileapi.macro.h"

//DeleteFileW
static int f0(void)
{
    setlocale(LC_ALL, "");

    wchar_t filePath[MAX_PATH];

    if (IsConsole) wprintf(L"�폜����t�@�C��: ");
    GetLineW(filePath, MAX_PATH);

    if (!DeleteFile(filePath)) {
        fwprintf(stderr, L"�G���[���������܂���\n");
        fwprintf(stderr, L"�ӂ��I�H����\n");

        return GetLastError();
    }

    wprintf(L"�t�@�C�����폜���܂���\n");

    return 0;
}

//GetFileSize
static int f1(void)
{
    setlocale(LC_ALL, "");

    wchar_t filePath[MAX_PATH];
    uint64_t fileSize;
    DWORD* pSizeLow = (DWORD*)&fileSize;
    DWORD* pSizeHigh = pSizeLow + 1;
    HANDLE hFile;

    if (IsConsole) wprintf(L"�t�@�C���p�X�����: ");
    GetLineW(filePath, MAX_PATH);

    hFile = CreateFile(
        filePath,
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fwprintf(stderr, L"�t�@�C�����쐬�ł��܂���ł���\n");
        fwprintf(stderr, L"�ӂ��I�H����\n");

        return GetLastError();
    }

    *pSizeLow = GetFileSize(hFile, pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        fwprintf(stderr, L"�t�@�C���T�C�Y���擾�ł��܂���ł���\n");
        fwprintf(stderr, L"�ӂ��I�H����\n");

        CloseHandle(hFile);

        return GetLastError();
    }

    wprintf(L"�t�@�C���T�C�Y: %llu\n", fileSize);

    CloseHandle(hFile);

    return 0;
}

//GetFileSizeEx
static int f2(void)
{
    setlocale(LC_ALL, "");

    wchar_t filePath[MAX_PATH];
    LARGE_INTEGER fileSize;
    HANDLE hFile;

    if (IsConsole) wprintf(L"�t�@�C���p�X�����: ");
    GetLineW(filePath, MAX_PATH);

    hFile = CreateFile(
        filePath,
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fwprintf(stderr, L"�t�@�C�����쐬�ł��܂���ł���\n");
        fwprintf(stderr, L"�ӂ��I�H����\n");

        return GetLastError();
    }

    if (!GetFileSizeEx(hFile, &fileSize)) {
        fwprintf(stderr, L"�t�@�C���T�C�Y���擾�ł��܂���ł���\n");
        fwprintf(stderr, L"�ӂ��I�H����\n");

        CloseHandle(hFile);

        return GetLastError();
    }

    wprintf(L"�t�@�C���T�C�Y: %lld\n", fileSize.QuadPart);

    CloseHandle(hFile);

    return 0;
}

//GetCompressedFileSizeW
static int f3(void)
{
    setlocale(LC_ALL, "");

    wchar_t filePath[MAX_PATH];
    uint64_t fileSize;
    DWORD* pSizeLow = (DWORD*)&fileSize;
    DWORD* pSizeHigh = pSizeLow + 1;

    if (IsConsole) wprintf(L"�t�@�C���p�X�����: ");
    GetLineW(filePath, MAX_PATH);

    *pSizeLow = GetCompressedFileSize(filePath, pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        fwprintf(stderr, L"�t�@�C���T�C�Y���擾�ł��܂���ł���\n");
        fwprintf(stderr, L"�ӂ��I�H����\n");

        return GetLastError();
    }

    wprintf(L"�t�@�C���T�C�Y: %llu\n", fileSize);

    return 0;
}

//GetDiskFreeSpaceW
static int f4(void)
{
    DWORD sectorPerCluster;
    DWORD bytesPerSector;
    DWORD numberOfFreeClusters;
    DWORD totalNumberOfClusters;

    if (!GetDiskFreeSpace(L"C:\\", &sectorPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters)) {
        fputs("�����擾�ł��܂���ł���\n", stderr);
        fputs("�ӂ��I�H����\n", stderr);

        return GetLastError();
    }

    printf("�N���X�^�[���Ƃ̃Z�N�^�[��: %lu\n", sectorPerCluster);
    printf("�Z�N�^�[���Ƃ̃o�C�g��:     %lu\n", bytesPerSector);
    printf("�󂫃N���X�^�[��:           %lu\n", numberOfFreeClusters);
    printf("�N���X�^�[��:               %lu\n", totalNumberOfClusters);

    return 0;
}

//GetTempPathW
static int f5(void)
{
    setlocale(LC_ALL, "");

    wchar_t tempPath[MAX_PATH];

    GetTempPath(MAX_PATH, tempPath);

    if (GetLastError() != NO_ERROR) {
        fputs("�p�X���擾�ł��܂���ł���\n", stderr);
        fputs("�ӂ��I�H����\n", stderr);

        return GetLastError();
    }

    printf("%ls\n", tempPath);

    return 0;
}

//GetTempPath2W
static int f6(void)
{
    setlocale(LC_ALL, "");

    wchar_t tempPath[MAX_PATH];

    GetTempPath2(MAX_PATH, tempPath);

    if (GetLastError() != NO_ERROR) {
        fputs("�p�X���擾�ł��܂���ł���\n", stderr);
        fputs("�ӂ��I�H����\n", stderr);

        return GetLastError();
    }

    printf("%ls\n", tempPath);

    return 0;
}

//CreateFileW-WriteFile
static int f7(void)
{
    setlocale(LC_ALL, "");

    HANDLE hFile;
    wchar_t filePath[MAX_PATH];
    const uint8_t utf16leBom[] = { 0xFF, 0xFE };
    DWORD writtenLength1, writtenLength2;
    const wchar_t wcs[] = 
        L"�܂�����Ȃ��ȁc�c\r\n"
        L"���̒��x�̋�����A���͋����Ȃ�Ȃ��B\r\n"
        L"�J�c�A�Q���s���B";

    if (IsConsole) wprintf(L"�쐬����t�@�C���̃p�X�����: ");
    GetLineW(filePath, MAX_PATH);

    hFile = CreateFile(
        filePath,
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        fwprintf(stderr, L"�t�@�C�����쐬�ł��܂���ł���\n");
        fwprintf(stderr, L"�ӂ��I�H����\n");

        return GetLastError();
    }

    //UTF16LE��BOM������
    WriteFile(hFile, utf16leBom, sizeof(utf16leBom), &writtenLength1, NULL);

    //���������������
    WriteFile(hFile, wcs, sizeof(wcs) - sizeof(wchar_t), &writtenLength2, NULL);

    CloseHandle(hFile);

    wprintf(L"�������񂾃o�C�g��: %lu\n", writtenLength1 + writtenLength2);

    return 0;
}

int RunFileapiSample(const char* tag)
{
    if (IsEqualStringA(tag, "CreateFileW-WriteFile")) return f7();
    if (IsEqualStringA(tag, "DeleteFileW")) return f0();
    if (IsEqualStringA(tag, "GetCompressedFileSizeW")) return f3();
    if (IsEqualStringA(tag, "GetDiskFreeSpaceW")) return f4();
    if (IsEqualStringA(tag, "GetFileSize")) return f1();
    if (IsEqualStringA(tag, "GetFileSizeEx")) return f2();
    if (IsEqualStringA(tag, "GetTempPath2W")) return f6();
    if (IsEqualStringA(tag, "GetTempPathW")) return f5();

    if (IsEqualStringA(tag, TAG_MACRO)) return macro();

    return RunNotFound(tag);
}