



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
#include <sstream>
#include <gdiplus.h>

#pragma comment (lib, "Gdiplus.lib")


const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	//MessageBox(nullptr, L"HelloWorld", L"SimpleWorld", MB_ICONEXCLAMATION | MB_OK);

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR token;

	GdiplusStartup(&token, &gdiplusStartupInput, nullptr);

	// 1. 윈도우 클래스 등록
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

	RECT wr = { 0,0,640,480 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);

	// 2. 윈도우 생성							-1번의 클래스 지정
	HWND hwnd = CreateWindowEx(
		0,
		gClassName,
		L"HelloWindow",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right - wr.left, wr.bottom - wr.top,
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

	// 3. 윈도우 메시지(이벤트) 루프
	MSG msg;
	while (GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	Gdiplus::GdiplusShutdown(token);
	return static_cast<int>(msg.wParam);
}

// *. 윈도우 프로시져 함수 만들기 - callback

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hwnd, &ps);

	//HPEN bluePen = CreatePen(PS_DOT, 1, RGB(0, 0, 255));	// 외부를 그리는게 펜
	//HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

	//HBRUSH hatchBrush = CreateHatchBrush(HS_CROSS, RGB(255,0,0));	// 내부를 채우는게 브러쉬
	//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hatchBrush);



	//Rectangle(hdc, 250, 250, 350, 350);

	//SetPixel(hdc, 0, 0, RGB(0, 255, 0));
	//SetPixel(hdc, 100, 100, RGB(0, 255, 0));
	//
	//MoveToEx(hdc, 0, 100, NULL);
	//LineTo(hdc, 100, 100);

	//Ellipse(hdc, 150, 150, 300, 200);

	//DeleteObject(hatchBrush);
	//SelectObject(hdc,oldBrush);


	//DeleteObject(bluePen);
	//SelectObject(hdc, oldPen);

	Gdiplus:: Graphics graphics(hdc); // DC -> Graphics
	//Gdiplus::Pen pen(Gdiplus::Color(255,0,0,255));				// HPEN-> PEN		a r g b

	//graphics.DrawRectangle(&pen, 0, 0, 100, 100);

	//pen.SetColor(Gdiplus::Color::HotPink);
	//graphics.DrawLine(&pen, 0, 0, 100, 100);

	//Gdiplus::SolidBrush brush(Gdiplus::Color::Black);
	//Gdiplus::FontFamily family(L"맑은 고딕");
	//Gdiplus::Font font(&family, 24, Gdiplus::FontStyle::FontStyleRegular,Gdiplus::UnitPixel);
	//graphics.DrawString(L"Get on the MidnightTrain", -1, &font, { 0.0f,110.0f }, &brush);
		
	Gdiplus::Image image(L"isaac.png");
	//graphics.DrawImage(&image, Gdiplus::RectF(
	//	ps.rcPaint.left, 
	//	ps.rcPaint.top,
	//	ps.rcPaint.right - ps.rcPaint.left,
	//	ps.rcPaint.bottom-ps.rcPaint.top));
	graphics.DrawImage(&image, 0, 0, image.GetWidth(), image.GetHeight());
	EndPaint(hwnd, &ps);
}

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
		OnPaint(hwnd);
		break;
	/*case WM_LBUTTONDOWN:
	{
		int x = LOWORD(lparam);
		int y = HIWORD(lparam >> 16);

		std::wostringstream oss;

		oss << "X : " << x << "Y : " << y;
		MessageBox(hwnd, oss.str().c_str(), L"왼쪽클릭", MB_OK);

		break;
	}*/
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
