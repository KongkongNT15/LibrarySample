#include <wchar.h>
#include <Windows.h>

//パイプのバッファーの長さ？
#define PIPE_INPUT_LENGTH 1024
#define PIPE_OUTPUT_LENGTH 16384

__declspec(dllexport) const char* StartSample(const wchar_t* commandLine, const wchar_t* input, unsigned long wait, unsigned long* returnCode);

char* ptr = NULL;

char pipeCreationErrorMessage[] = "ストリームの作成中にエラーが発生しました";
char pipeSettingErrorMessage[] = "ストリームの設定中にエラーが発生しました";
char pipeInputWritingError[] = "入力ストリームに書き込んでいる途中でエラーが発生しました";
char timeOutMessage[] = "接続がタイムアウトしました";
char createProcessErrorMessage[] = "プロセスを開始できませんでした";
char redirectErrorMessage[] = "出力ストリームのリダイレクトに失敗しました";
char mallocError[] = "メモリの確保に失敗しました";

const char* StartSample(const wchar_t* commandLine, const wchar_t* input, unsigned long wait, unsigned long* returnCode)
{
	SECURITY_ATTRIBUTES securityAttributes = { 0 };
	securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
	securityAttributes.lpSecurityDescriptor = NULL;
	securityAttributes.bInheritHandle = TRUE;

	//入力ストリーム
	HANDLE hInputStdIn;
	HANDLE hOutputStdIn;

	//出力ストリーム
	HANDLE hInputStdOut;
	HANDLE hOutputStdOut;

	//ふぁ！？っく
	DWORD tmp;

	//とにかく長さ
	DWORD length;

	//入力ストリーム作成
	if (!CreatePipe(&hInputStdIn, &hOutputStdIn, &securityAttributes, PIPE_INPUT_LENGTH)) {
		*returnCode = -1;
		return pipeCreationErrorMessage;
	}

	//子プロセスがこのハンドルアクセスできるようにする
	if (!SetHandleInformation(hOutputStdIn, HANDLE_FLAG_INHERIT, 0)) {
		CloseHandle(hInputStdIn);
		CloseHandle(hOutputStdIn);

		*returnCode = -1;
		return pipeSettingErrorMessage;
	}

	//出力ストリーム作成
	if (!CreatePipe(&hInputStdOut, &hOutputStdOut, &securityAttributes, PIPE_OUTPUT_LENGTH)) {
		CloseHandle(hInputStdIn);
		CloseHandle(hOutputStdIn);

		*returnCode = -1;
		return pipeCreationErrorMessage;
	}

	//子プロセスがこのハンドルアクセスできるようにする
	if (!SetHandleInformation(hInputStdOut, HANDLE_FLAG_INHERIT, 0)) {
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);

		*returnCode = -1;
		return pipeSettingErrorMessage;
	}

	//入力ストリームに書き込み
	length = (DWORD)wcslen(input);
	if (length != 0) {
		//ANSIに変換してからストリームに書き込む
		char* strtr = malloc(length * 2 + 1);

		if (strtr == NULL) {

			CloseHandle(hInputStdIn);
			CloseHandle(hInputStdOut);
			CloseHandle(hOutputStdIn);
			CloseHandle(hOutputStdOut);

			*returnCode = -1;
			return pipeCreationErrorMessage;
		}

		WideCharToMultiByte(CP_ACP, 0, input, -1, strtr, length * 2 + 1, NULL, NULL);

		if (!WriteFile(hOutputStdIn, strtr, (DWORD)strlen(strtr), &tmp, NULL)) {
			CloseHandle(hInputStdIn);
			CloseHandle(hInputStdOut);
			CloseHandle(hOutputStdIn);
			CloseHandle(hOutputStdOut);

			*returnCode = -1;
			free(strtr);

			return pipeInputWritingError;
		}

		free(strtr);
	}
	

	//よくわからんやつ
	STARTUPINFO sInfo = { 0 };
	sInfo.cb = sizeof(STARTUPINFO);
	sInfo.dwFlags = STARTF_USESTDHANDLES;
	sInfo.hStdInput = hInputStdIn;
	sInfo.hStdOutput = hOutputStdOut;
	sInfo.hStdError = hOutputStdOut;

	//子プロセスとそのメインスレッドのハンドル
	PROCESS_INFORMATION pInfo = { 0 };

	//プロセスを作成して実行
	if (!CreateProcess(NULL, (wchar_t*)commandLine, &securityAttributes, &securityAttributes, TRUE, CREATE_NO_WINDOW, NULL, NULL, &sInfo, &pInfo)) {
		*returnCode = GetLastError();
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);

		return createProcessErrorMessage;
	}

	//指定された時間だけ待つ
	//実行中なら強制終了
	if (WaitForSingleObject(pInfo.hProcess, wait) == WAIT_TIMEOUT) {
		TerminateProcess(pInfo.hProcess, (UINT)-1);
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);
		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

		*returnCode = -1;

		return timeOutMessage;
	}

	//以前確保していた領域を解放
	if (ptr != NULL) {
		free(ptr);
	}

	//出力ストリームに書き込まれたデータの長さ
	length = GetFileSize(hInputStdOut, NULL);

	//取得に失敗
	if (length == INVALID_FILE_SIZE) {

		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);
		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);
		*returnCode = -1;

		return redirectErrorMessage;
	}

	ptr = malloc(length + 1);

	//メモリ確保に失敗
	if (ptr == NULL) {
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);
		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

		*returnCode = -1;

		return redirectErrorMessage;
	}

	//戻り値を取得
	GetExitCodeProcess(pInfo.hProcess, &returnCode);

	//
	if (length == 0) {
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);
		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

		*ptr = '\0';
		return ptr;
	}

	//リダイレクト
	if (!ReadFile(hInputStdOut, ptr, length, &length, NULL)) {
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);
		CloseHandle(pInfo.hProcess);
		CloseHandle(pInfo.hThread);

		*returnCode = GetLastError();

		return redirectErrorMessage;
	}

	ptr[length] = '\0';

	CloseHandle(hInputStdIn);
	CloseHandle(hInputStdOut);
	CloseHandle(hOutputStdIn);
	CloseHandle(hOutputStdOut);
	CloseHandle(pInfo.hProcess);
	CloseHandle(pInfo.hThread);

	return ptr;
}