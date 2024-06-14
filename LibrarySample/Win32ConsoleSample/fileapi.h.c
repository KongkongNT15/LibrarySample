#include "pch.h"
#include "../Macros/fileapi.macro.h"

//DeleteFileW
static int f0(void)
{
    setlocale(LC_ALL, "");

    wchar_t filePath[MAX_PATH];

    if (IsConsole) wprintf(L"削除するファイル: ");
    GetLineW(filePath, MAX_PATH);

    if (!DeleteFile(filePath)) {
        fwprintf(stderr, L"エラーが発生しました\n");
        fwprintf(stderr, L"ふぁ！？っく\n");

        return GetLastError();
    }

    wprintf(L"ファイルを削除しました\n");

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

    if (IsConsole) wprintf(L"ファイルパスを入力: ");
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
        fwprintf(stderr, L"ファイルを作成できませんでした\n");
        fwprintf(stderr, L"ふぁ！？っく\n");

        return GetLastError();
    }

    *pSizeLow = GetFileSize(hFile, pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        fwprintf(stderr, L"ファイルサイズを取得できませんでした\n");
        fwprintf(stderr, L"ふぁ！？っく\n");

        CloseHandle(hFile);

        return GetLastError();
    }

    wprintf(L"ファイルサイズ: %llu\n", fileSize);

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

    if (IsConsole) wprintf(L"ファイルパスを入力: ");
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
        fwprintf(stderr, L"ファイルを作成できませんでした\n");
        fwprintf(stderr, L"ふぁ！？っく\n");

        return GetLastError();
    }

    if (!GetFileSizeEx(hFile, &fileSize)) {
        fwprintf(stderr, L"ファイルサイズを取得できませんでした\n");
        fwprintf(stderr, L"ふぁ！？っく\n");

        CloseHandle(hFile);

        return GetLastError();
    }

    wprintf(L"ファイルサイズ: %lld\n", fileSize.QuadPart);

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

    if (IsConsole) wprintf(L"ファイルパスを入力: ");
    GetLineW(filePath, MAX_PATH);

    *pSizeLow = GetCompressedFileSize(filePath, pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        fwprintf(stderr, L"ファイルサイズを取得できませんでした\n");
        fwprintf(stderr, L"ふぁ！？っく\n");

        return GetLastError();
    }

    wprintf(L"ファイルサイズ: %llu\n", fileSize);

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
        fputs("情報を取得できませんでした\n", stderr);
        fputs("ふぁ！？っく\n", stderr);

        return GetLastError();
    }

    printf("クラスターごとのセクター数: %lu\n", sectorPerCluster);
    printf("セクターごとのバイト数:     %lu\n", bytesPerSector);
    printf("空きクラスター数:           %lu\n", numberOfFreeClusters);
    printf("クラスター数:               %lu\n", totalNumberOfClusters);

    return 0;
}

//GetTempPathW
static int f5(void)
{
    setlocale(LC_ALL, "");

    wchar_t tempPath[MAX_PATH];

    GetTempPath(MAX_PATH, tempPath);

    if (GetLastError() != NO_ERROR) {
        fputs("パスを取得できませんでした\n", stderr);
        fputs("ふぁ！？っく\n", stderr);

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
        fputs("パスを取得できませんでした\n", stderr);
        fputs("ふぁ！？っく\n", stderr);

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
        L"まだ足りないな……\r\n"
        L"この程度の金じゃ、俺は強くなれない。\r\n"
        L"カツアゲ続行だ。";

    if (IsConsole) wprintf(L"作成するファイルのパスを入力: ");
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
        fwprintf(stderr, L"ファイルを作成できませんでした\n");
        fwprintf(stderr, L"ふぁ！？っく\n");

        return GetLastError();
    }

    //UTF16LEのBOMを入れる
    WriteFile(hFile, utf16leBom, sizeof(utf16leBom), &writtenLength1, NULL);

    //文字列を書き込む
    WriteFile(hFile, wcs, sizeof(wcs) - sizeof(wchar_t), &writtenLength2, NULL);

    CloseHandle(hFile);

    wprintf(L"書き込んだバイト数: %lu\n", writtenLength1 + writtenLength2);

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