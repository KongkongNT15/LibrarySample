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
        L"�܂�����Ȃ��ȁc�c\r\n"
        L"���̒��x�̋�����A���͋����Ȃ�Ȃ��B\r\n"
        L"�J�c�A�Q���s���B";

    if (IsConsole) wcout << L"�쐬����t�@�C���̃p�X�����: ";
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
        wcerr << L"�t�@�C�����쐬�ł��܂���ł���" << endl;
        wcerr << L"�ӂ��I�H����" << endl;

        return GetLastError();
    }

    //UTF16LE��BOM������
    WriteFile(hFile, utf16leBom, sizeof(utf16leBom), &writtenLength1, NULL);

    //���������������
    WriteFile(hFile, wcs, sizeof(wcs) - sizeof(wchar_t), &writtenLength2, NULL);

    CloseHandle(hFile);

    wcout << L"�������񂾃o�C�g��: " << writtenLength1 + writtenLength2 << endl;

    return 0;
}

//DeleteFileW
static int f1(void)
{
    locale::global(locale(""));

    wstring filePath;

    if (IsConsole) wcout << L"�폜����t�@�C��: ";
    getline(wcin, filePath);

    if (!DeleteFile(filePath.c_str())) {
        wcerr << L"�G���[���������܂���" << endl;
        wcerr << L"�ӂ��I�H����" << endl;

        return GetLastError();
    }

    wcout << L"�t�@�C�����폜���܂���" << endl;

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

    if (IsConsole) wcout << L"�t�@�C���p�X�����: ";
    getline(wcin, filePath);

    *pSizeLow = GetCompressedFileSize(filePath.c_str(), pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        wcerr << L"�t�@�C���T�C�Y���擾�ł��܂���ł���" << endl;
        wcerr << L"�ӂ��I�H����" << endl;

        return GetLastError();
    }

    wcout << L"�t�@�C���T�C�Y: " << fileSize << endl;

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
        cerr << "�����擾�ł��܂���ł���" << endl;
        cerr << "�ӂ��I�H����" << endl;

        return GetLastError();
    }

    cout << "�N���X�^�[���Ƃ̃Z�N�^�[��: " << sectorPerCluster << endl;
    cout << "�Z�N�^�[���Ƃ̃o�C�g��:     " << bytesPerSector << endl;
    cout << "�󂫃N���X�^�[��:           " << numberOfFreeClusters << endl;
    cout << "�N���X�^�[��:               " << totalNumberOfClusters << endl;

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

    if (IsConsole) wcout << L"�t�@�C���p�X�����: ";
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
        wcerr << L"�t�@�C�����쐬�ł��܂���ł���" << endl;
        wcerr << L"�ӂ��I�H����" << endl;

        return GetLastError();
    }

    *pSizeLow = GetFileSize(hFile, pSizeHigh);

    if (GetLastError() != NO_ERROR) {
        wcerr << L"�t�@�C���T�C�Y���擾�ł��܂���ł���" << endl;
        wcerr << L"�ӂ��I�H����" << endl;

        CloseHandle(hFile);

        return GetLastError();
    }

    wcout << L"�t�@�C���T�C�Y: " << fileSize << endl;

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

    if (IsConsole) wcout << L"�t�@�C���p�X�����: ";
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
        wcerr << L"�t�@�C�����쐬�ł��܂���ł���" << endl;
        wcerr << L"�ӂ��I�H����" << endl;

        return GetLastError();
    }

    if (!GetFileSizeEx(hFile, &fileSize)) {
        wcerr << L"�t�@�C���T�C�Y���擾�ł��܂���ł���" << endl;
        wcerr << L"�ӂ��I�H����" << endl;

        CloseHandle(hFile);

        return GetLastError();
    }

    wcout << L"�t�@�C���T�C�Y: " << fileSize.QuadPart << endl;

    return 0;
}

//GetTempPath2W
static int f6(void)
{
    locale::global(locale(""));

    wchar_t tempPath[MAX_PATH];

    GetTempPath2(MAX_PATH, tempPath);

    if (GetLastError() != NO_ERROR) {
        cout << "�p�X���擾�ł��܂���ł���" << endl;
        cout << "�ӂ��I�H����" << endl;

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
        cout << "�p�X���擾�ł��܂���ł���" << endl;
        cout << "�ӂ��I�H����" << endl;

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