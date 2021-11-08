



// WINAPI : Windows API
// SAL : Source code Annotation Language
//		_In_		_In_opt
//		_Out_		_Out_opt
//		_Inout_		_Inout_opt

// HINSTANCE
//		Handle of Instance
//		(포인터)

// LPSTR
//		Long Pointer to null-terminated STRing

// LPCSTR
//		Long Pointer Constant wide-character STRing

//

// 헝가리언 스타일
//		Win API 헝가리 -> int nNnumber;

// MessageBox()
//	HWND  hwnd		Handle of WinDow


// Windows API 헤더

#include <Windows.h>

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	MessageBox(nullptr, L"HelloWorld", L"SimpleWorld", MB_ICONEXCLAMATION | MB_OK);

	// 1. 윈도우 클래스 등록
	// 2. 윈도우 생성
	// 3. 윈도우 메시지(이벤트) 루프
	// 4. 윈도우 프로시져

	return 0;
}
// *. 윈도우 프로시져 함수 만들기 - callback
