



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
// 1. 윈도우 클래스 등록
// 2. 윈도우 생성							-1번의 클래스 지정
// 3. 윈도우 메시지(이벤트) 루프

#include <Windows.h>
#include <sstream>

const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	MessageBox(nullptr, L"HelloWorld", L"SimpleWorld", MB_ICONEXCLAMATION | MB_OK);

	
	WNDCLASSEX wc;				// 구조체 - 매개변수로 넘겨줄때는 반드시 0으로 초기화 

	//memset(&wc, 0, sizeof(WNDCLASSEX));		// 0으로 초기화
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);		// count of byte
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);		// 커서 커스터마이징
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;				// 배경색깔
	wc.lpfnWndProc = WindowProc;

	if (RegisterClassEx(&wc) == false)
	{
		MessageBox(nullptr, L"Failed to Register Window Class!", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	
	HWND hwnd = CreateWindowEx(
		0,
		gClassName,
		L"HelloWindow",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		640, 480,
		0,
		0,
		hInstance,
		0
	);

	if (hwnd == 0)
	{
		MessageBox(nullptr, L"Failed to Create Window!", L"Error", MB_OK | MB_ICONEXCLAMATION);
	}
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return static_cast<int>(msg.wParam);
}

// *. 윈도우 프로시져 함수 만들기 - callback

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{


	case WM_KEYDOWN:
	{
		//char x = wparam;
		std::wostringstream oss2;
		oss2 << wparam << std::endl;;
		//oss2 << "Key : " << x;
		OutputDebugString(oss2.str().c_str());
		
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hwnd, &ps);

		Rectangle(hdc, 0, 0, 100, 100);

		EndPaint(hwnd, &ps);


	}
	break;
	case WM_CLOSE:
		DestroyWindow(hwnd);	// 윈도우 닫기
		break;

	case WM_DESTROY:
		PostQuitMessage(0);		// 앱종료
		break;

	default:
		return DefWindowProc(hwnd, message, wparam, lparam);
		break;
	}
	return 0;
}
