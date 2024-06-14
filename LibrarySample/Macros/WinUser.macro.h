static int macro(void)
{
    PutMacro(CharLower, CALL_BY_ANSI_OR_UNICODE);
    PutMacro(MessageBox, CALL_BY_ANSI_OR_UNICODE);

    return 0;
}