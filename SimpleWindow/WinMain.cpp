



// WINAPI : Windows API
// SAL : Source code Annotation Language
//		_In_		_In_opt
//		_Out_		_Out_opt
//		_Inout_		_Inout_opt

// HINSTANCE
//		Handle of Instance
//		(������)

// LPSTR
//		Long Pointer to null-terminated STRing

// LPCSTR
//		Long Pointer Constant wide-character STRing

//

// �밡���� ��Ÿ��
//		Win API �밡�� -> int nNnumber;

// MessageBox()
//	HWND  hwnd		Handle of WinDow


// Windows API ���

#include <Windows.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	MessageBox(nullptr, L"HelloWorld", L"SimpleWorld", MB_ICONEXCLAMATION | MB_OK);

	// 1. ������ Ŭ���� ���
	// 2. ������ ����
	// 3. ������ �޽���(�̺�Ʈ) ����
	// 4. ������ ���ν���

	return 0;
}
// *. ������ ���ν��� �Լ� ����� - callback
