static int macro(void)
{
    PutMacro(CREATE_NEW, "�V�����t�@�C�����쐬");
    PutMacro(CREATE_ALWAYS, "�t�@�C���̗L���ɂ�����킸��ɐV�K�쐬");
    PutMacro(OPEN_EXISTING, "�t�@�C�������݂���΂�����J��");
    PutMacro(OPEN_ALWAYS, "��Ɋ����̃t�@�C�����J��");
    PutMacro(TRUNCATE_EXISTING, "�t�@�C�������݂���΃T�C�Y���[���ɐ؂�̂Ă�");

    PutMacro(INVALID_FILE_SIZE, "GetFileSize()�����s�����Ƃ��̖߂�l");

    PutMacro(CreateFile, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(DeleteFile, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetCompressedFileSize, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetDiskFreeSpace, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetTempPath, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(GetTempPath2, CALL_BY_ANSI_OR_UNICODE);

    return 0;
}