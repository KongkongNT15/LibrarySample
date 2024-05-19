#include <wchar.h>
#include <Windows.h>

//�p�C�v�̃o�b�t�@�[�̒����H
#define PIPE_INPUT_LENGTH 1024
#define PIPE_OUTPUT_LENGTH 16384

__declspec(dllexport) const char* StartSample(const wchar_t* commandLine, const wchar_t* input, unsigned long wait, unsigned long* returnCode);

char* ptr = NULL;

char pipeCreationErrorMessage[] = "�X�g���[���̍쐬���ɃG���[���������܂���";
char pipeSettingErrorMessage[] = "�X�g���[���̐ݒ蒆�ɃG���[���������܂���";
char pipeInputWritingError[] = "���̓X�g���[���ɏ�������ł���r���ŃG���[���������܂���";
char timeOutMessage[] = "�ڑ����^�C���A�E�g���܂���";
char createProcessErrorMessage[] = "�v���Z�X���J�n�ł��܂���ł���";
char redirectErrorMessage[] = "�o�̓X�g���[���̃��_�C���N�g�Ɏ��s���܂���";
char mallocError[] = "�������̊m�ۂɎ��s���܂���";

const char* StartSample(const wchar_t* commandLine, const wchar_t* input, unsigned long wait, unsigned long* returnCode)
{
	SECURITY_ATTRIBUTES securityAttributes = { 0 };
	securityAttributes.nLength = sizeof(SECURITY_ATTRIBUTES);
	securityAttributes.lpSecurityDescriptor = NULL;
	securityAttributes.bInheritHandle = TRUE;

	//���̓X�g���[��
	HANDLE hInputStdIn;
	HANDLE hOutputStdIn;

	//�o�̓X�g���[��
	HANDLE hInputStdOut;
	HANDLE hOutputStdOut;

	//�ӂ��I�H����
	DWORD tmp;

	//�Ƃɂ�������
	DWORD length;

	//���̓X�g���[���쐬
	if (!CreatePipe(&hInputStdIn, &hOutputStdIn, &securityAttributes, PIPE_INPUT_LENGTH)) {
		*returnCode = -1;
		return pipeCreationErrorMessage;
	}

	//�q�v���Z�X�����̃n���h���A�N�Z�X�ł���悤�ɂ���
	if (!SetHandleInformation(hOutputStdIn, HANDLE_FLAG_INHERIT, 0)) {
		CloseHandle(hInputStdIn);
		CloseHandle(hOutputStdIn);

		*returnCode = -1;
		return pipeSettingErrorMessage;
	}

	//�o�̓X�g���[���쐬
	if (!CreatePipe(&hInputStdOut, &hOutputStdOut, &securityAttributes, PIPE_OUTPUT_LENGTH)) {
		CloseHandle(hInputStdIn);
		CloseHandle(hOutputStdIn);

		*returnCode = -1;
		return pipeCreationErrorMessage;
	}

	//�q�v���Z�X�����̃n���h���A�N�Z�X�ł���悤�ɂ���
	if (!SetHandleInformation(hInputStdOut, HANDLE_FLAG_INHERIT, 0)) {
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);

		*returnCode = -1;
		return pipeSettingErrorMessage;
	}

	//���̓X�g���[���ɏ�������
	length = (DWORD)wcslen(input);
	if (length != 0) {
		//ANSI�ɕϊ����Ă���X�g���[���ɏ�������
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
	

	//�悭�킩�����
	STARTUPINFO sInfo = { 0 };
	sInfo.cb = sizeof(STARTUPINFO);
	sInfo.dwFlags = STARTF_USESTDHANDLES;
	sInfo.hStdInput = hInputStdIn;
	sInfo.hStdOutput = hOutputStdOut;
	sInfo.hStdError = hOutputStdOut;

	//�q�v���Z�X�Ƃ��̃��C���X���b�h�̃n���h��
	PROCESS_INFORMATION pInfo = { 0 };

	//�v���Z�X���쐬���Ď��s
	if (!CreateProcess(NULL, (wchar_t*)commandLine, &securityAttributes, &securityAttributes, TRUE, CREATE_NO_WINDOW, NULL, NULL, &sInfo, &pInfo)) {
		*returnCode = GetLastError();
		CloseHandle(hInputStdIn);
		CloseHandle(hInputStdOut);
		CloseHandle(hOutputStdIn);
		CloseHandle(hOutputStdOut);

		return createProcessErrorMessage;
	}

	//�w�肳�ꂽ���Ԃ����҂�
	//���s���Ȃ狭���I��
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

	//�ȑO�m�ۂ��Ă����̈�����
	if (ptr != NULL) {
		free(ptr);
	}

	//�o�̓X�g���[���ɏ������܂ꂽ�f�[�^�̒���
	length = GetFileSize(hInputStdOut, NULL);

	//�擾�Ɏ��s
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

	//�������m�ۂɎ��s
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

	//�߂�l���擾
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

	//���_�C���N�g
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