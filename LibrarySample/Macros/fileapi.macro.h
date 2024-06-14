static int macro(void)
{
    PutMacro(CREATE_NEW, "新しくファイルを作成");
    PutMacro(CREATE_ALWAYS, "ファイルの有無にかからわず常に新規作成");
    PutMacro(OPEN_EXISTING, "ファイルが存在すればそれを開く");
    PutMacro(OPEN_ALWAYS, "常に既存のファイルを開く");
    PutMacro(TRUNCATE_EXISTING, "ファイルが存在すればサイズをゼロに切り捨てる");

    PutMacro(INVALID_FILE_SIZE, "GetFileSize()が失敗したときの戻り値");

    PutMacro(CreateFile, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(DeleteFile, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetCompressedFileSize, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetDiskFreeSpace, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetTempPath, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetTempPath2, CALL_BY_ANSI_OR_UNICODE);

    return 0;
}