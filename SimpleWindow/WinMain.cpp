



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

	// 1. ������ Ŭ���� ���
	WNDCLASSEX wc;				// ����ü - �Ű������� �Ѱ��ٶ��� �ݵ�� 0���� �ʱ�ȭ 

	//memset(&wc, 0, sizeof(WNDCLASSEX));		// 0���� �ʱ�ȭ
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);		// count of byte
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);		// Ŀ�� Ŀ���͸���¡
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;				// ������
	wc.lpfnWndProc = WindowProc;

	if (RegisterClassEx(&wc) == false)
	{
		MessageBox(nullptr, L"Failed to Register Window Class!", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	// 2. ������ ����							-1���� Ŭ���� ����
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

	// 3. ������ �޽���(�̺�Ʈ) ����
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return static_cast<int>(msg.wParam);
}

// *. ������ ���ν��� �Լ� ����� - callback

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	/*case WM_LBUTTONDOWN:
	{
		HDC hdc = GetDC(hwnd);

		Rectangle(hdc, 0, 0, 100, 100);

		ReleaseDC(hwnd, hdc);
		break;
	}*/

	case WM_KEYDOWN:
	{
		//char x = wparam;
		std::wostringstream oss2;
		oss2 << wparam << std::endl;;
		//oss2 << "Key : " << x;
		OutputDebugString(oss2.str().c_str());
		break;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc;
		hdc = BeginPaint(hwnd, &ps);

		Rectangle(hdc, 0, 0, 100, 100);

		EndPaint(hwnd, &ps);


	}
		break;
	/*case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lparam);
		int y = HIWORD(lparam >> 16);

		std::wostringstream oss;

		oss << "X : " << x << "Y : " << y;
		MessageBox(hwnd, oss.str().c_str(), L"����Ŭ��", MB_OK);

		break;
	}*/
	case WM_CLOSE:
		DestroyWindow(hwnd);	// ������ �ݱ�
		break;

	case WM_DESTROY:
		PostQuitMessage(0);		// ������
		break;

	default:
		return DefWindowProc(hwnd, message, wparam, lparam);
		break;
	}
	return 0;
}
