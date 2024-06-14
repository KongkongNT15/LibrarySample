#include "pch.h"
#include "../Macros/fileapi.macro.h"
using namespace std;
using namespace Kongkong;

//CreateFileW-WriteFile
static int f0(void)
{
    locale::global(locale(""));

    HANDLE hFile;
    wstring filePath;
    const uint8_t utf16leBom[] = { 0xFF, 0xFE };
    DWORD writtenLength1, writtenLength2;
    const wchar_t wcs[] =
        L"まだ足りないな……\r\n"
        L"この程度の金じゃ、俺は強くなれない。\r\n"
        L"カツアゲ続行だ。";

    if (IsConsole) wcout << L"作成するファイルのパスを入力: ";
    getline(wcin, filePath);

    hFile = CreateFile(
        filePath.c_str(),
        GENERIC_WRITE,
        0,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        wcerr << L"ファイルを作成できませんでした" << endl;
        wcerr << L"ふぁ！？っく" << endl;

        return GetLastError();
    }

    //UTF16LEのBOMを入れる
    WriteFile(hFile, utf16leBom, sizeof(utf16leBom), &writtenLength1, NULL);

    //文字列を書き込む
    WriteFile(hFile, wcs, sizeof(wcs) - sizeof(wchar_t), &writtenLength2, NULL);

    CloseHandle(hFile);

    wcout << L"書き込んだバイト数: " << writtenLength1 + writtenLength2 << endl;

    return 0;
}

//DeleteFileW
static int f1(void)
{
    locale::global(locale(""));

    wstring filePath;

    if (IsConsole) wcout << L"削除するファイル: ";
    getline(wcin, filePath);

    if (!DeleteFile(filePath.c_str())) {
        wcerr << L"エラーが発生しました" << endl;
        wcerr << L"ふぁ！？っく" << endl;

        return GetLastError();
    }

    wcout << L"ファイルを削除しました" << endl;

    return 0;
}

//GetCompressedFileSizeW
static int f2(void)
{
    locale::global(locale(""));

    wstring filePath;
    uint64_t fileSize;
    DWORD* pSizeLow = (DWORD*)&fileSize;
    DWORD* pSizeHigh = pSizeLow + 1;

    if (IsConsole) wcout << L"ファイルパスを入力: ";
    getline(wcin, filePath);

    *pSizeLow = GetCompressedFileSize(filePath.c_str(), pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        wcerr << L"ファイルサイズを取得できませんでした" << endl;
        wcerr << L"ふぁ！？っく" << endl;

        return GetLastError();
    }

    wcout << L"ファイルサイズ: " << fileSize << endl;

    return 0;
}

//GetDiskFreeSpaceW
static int f3(void)
{
    DWORD sectorPerCluster;
    DWORD bytesPerSector;
    DWORD numberOfFreeClusters;
    DWORD totalNumberOfClusters;

    if (!GetDiskFreeSpace(L"C:\\", &sectorPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters)) {
        cerr << "情報を取得できませんでした" << endl;
        cerr << "ふぁ！？っく" << endl;

        return GetLastError();
    }

    cout << "クラスターごとのセクター数: " << sectorPerCluster << endl;
    cout << "セクターごとのバイト数:     " << bytesPerSector << endl;
    cout << "空きクラスター数:           " << numberOfFreeClusters << endl;
    cout << "クラスター数:               " << totalNumberOfClusters << endl;

    return 0;
}

//GetFileSize
static int f4(void)
{
    locale::global(locale(""));

    wstring filePath;
    uint64_t fileSize;
    DWORD* pSizeLow = (DWORD*)&fileSize;
    DWORD* pSizeHigh = pSizeLow + 1;
    HANDLE hFile;

    if (IsConsole) wcout << L"ファイルパスを入力: ";
    getline(wcin, filePath);

    hFile = CreateFile(
        filePath.c_str(),
        GENERIC_READ,
        0,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        wcerr << L"ファイルを作成できませんでした" << endl;
        wcerr << L"ふぁ！？っく" << endl;

        return GetLastError();
    }

    *pSizeLow = GetFileSize(hFile, pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        wcerr << L"ファイルサイズを取得できませんでした" << endl;
        wcerr << L"ふぁ！？っく" << endl;

        CloseHandle(hFile);

        return GetLastError();
    }

    wcout << L"ファイルサイズ: " << fileSize << endl;

    CloseHandle(hFile);

    return 0;
}

//GetFileSizeEx
static int f5(void)
{
    locale::global(locale(""));

    wstring filePath;
    LARGE_INTEGER fileSize;
    HANDLE hFile;

    if (IsConsole) wcout << L"ファイルパスを入力: ";
    getline(wcin, filePath);

    hFile = CreateFile(
        filePath.c_str(),
        GENERIC_READ,
        0,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        wcerr << L"ファイルを作成できませんでした" << endl;
        wcerr << L"ふぁ！？っく" << endl;

        return GetLastError();
    }

    if (!GetFileSizeEx(hFile, &fileSize)) {
        wcerr << L"ファイルサイズを取得できませんでした" << endl;
        wcerr << L"ふぁ！？っく" << endl;

        CloseHandle(hFile);

        return GetLastError();
    }

    wcout << L"ファイルサイズ: " << fileSize.QuadPart << endl;

    return 0;
}

//GetTempPath2W
static int f6(void)
{
    locale::global(locale(""));

    wchar_t tempPath[MAX_PATH];

    GetTempPath2(MAX_PATH, tempPath);

    if (GetLastError() != NO_ERROR) {
        cout << "パスを取得できませんでした" << endl;
        cout << "ふぁ！？っく" << endl;

        return GetLastError();
    }

    wcout << tempPath << endl;

    return 0;
}

//GetTempPathW
static int f7(void)
{
    locale::global(locale(""));

    wchar_t tempPath[MAX_PATH];

    GetTempPath(MAX_PATH, tempPath);

    if (GetLastError() != NO_ERROR) {
        cout << "パスを取得できませんでした" << endl;
        cout << "ふぁ！？っく" << endl;

        return GetLastError();
    }

    wcout << tempPath << endl;

    return 0;
}

int Kongkong::Fileapi::RunSample(const char* tag)
{
    if (IsEqualStringA(tag, "CreateFileW-WriteFile")) return f0();
    if (IsEqualStringA(tag, "DeleteFileW")) return f1();
    if (IsEqualStringA(tag, "GetCompressedFileSizeW")) return f2();
    if (IsEqualStringA(tag, "GetDiskFreeSpaceW")) return f3();
    if (IsEqualStringA(tag, "GetFileSize")) return f4();
    if (IsEqualStringA(tag, "GetFileSizeEx")) return f5();
    if (IsEqualStringA(tag, "GetTempPath2W")) return f6();
    if (IsEqualStringA(tag, "GetTempPathW")) return f7();

    if (IsEqualStringA(tag, TAG_MACRO)) return macro();

    return RunNotFound(tag);
}