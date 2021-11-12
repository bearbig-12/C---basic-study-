
#include "GameLogic.h"
//#include <Windows.h>
//#include <gdiplus.h>
//#include "Card.h"
//#include <list>
#pragma comment(lib,"Gdiplus.lib")

const wchar_t gClassName[]{ L"MyWindowClass" };

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

solitaire::GameLogic gLogic;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	// GDIplus 초기화
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplustoken;
	GdiplusStartup(&gdiplustoken, &gdiplusStartupInput, nullptr);
	//TEST
	

	// 클래스 등록
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);		
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;				
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);

	if (RegisterClassEx(&wc) == false)
	{
		MessageBox(nullptr, L"Failed to register window class", L"Error", MB_OK | MB_ICONEXCLAMATION);
	}

	//윈도우 만들기
	RECT wr = { 0,0,1024,768 };
	AdjustWindowRect(&wr, WS_OVERLAPPED | WS_SYSMENU, FALSE);
	HWND hwnd = CreateWindowEx(
		0,
		gClassName,
		L"Solitare Game",
		WS_OVERLAPPED | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right - wr.left, wr.bottom - wr.top,
		0, 0,
		hInstance,
		nullptr
		);

	if (hwnd == nullptr)
	{
		MessageBox(nullptr, L"Failed to create window!", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	gLogic.Initialize(hwnd);

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	//메시지 루프
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}

	gLogic.Release();

	// GDIplus 해제
	Gdiplus::GdiplusShutdown(gdiplustoken);

	return static_cast<int>(msg.wParam);
}
	
void OnPaint(HWND hwnd)
{
	HDC hdc;
	PAINTSTRUCT ps;

	hdc = BeginPaint(hwnd, &ps);

	Gdiplus::Graphics graphics(hdc);

	gLogic.Draw(graphics);

	EndPaint(hwnd, &ps);
}
//윈도우 프로시져
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_LBUTTONUP:
		gLogic.OnClick(LOWORD(lparam), HIWORD(lparam));
		break;
	case WM_PAINT:
		OnPaint(hwnd);
		break;

	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wparam, lparam);
	}
}

	