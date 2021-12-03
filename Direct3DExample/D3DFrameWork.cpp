#include "D3DFrameWork.h"
#pragma comment (lib, "d3d11.lib")

void D3DFrameWork::Initialize(HINSTANCE hInstance, int width, int height)
{
	gScreenWidth = width;
	gScreenHeight = height;

	InitWindow(hInstance);
	InitD3D();
}
void D3DFrameWork::InitWindow(HINSTANCE hInstance)
{
	WNDCLASSEX wc;


	ZeroMemory(&wc, sizeof(WNDCLASSEX));


	mInstance = hInstance;


	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName.c_str();
	wc.hInstance = mInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = nullptr;
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);


	if (!RegisterClassEx(&wc))
	{
		return;
	}


	RECT wr{ 0, 0, gScreenWidth, gScreenHeight };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);


	mHwnd = CreateWindowEx(
		NULL,
		gClassName.c_str(),
		gTitle.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		mInstance,
		NULL
	);


	if (mHwnd == nullptr)
	{
		return;
	}

	SetWindowLongPtr(mHwnd, GWLP_USERDATA,
		reinterpret_cast<LONG_PTR>(this));


	ShowWindow(mHwnd, SW_SHOW);


	SetForegroundWindow(mHwnd);
	SetFocus(mHwnd);


	UpdateWindow(mHwnd);

}

void D3DFrameWork::InitD3D()
{
	// Device ¸¸µé±â
	// SwapChain ¸¸µé±â


	DXGI_SWAP_CHAIN_DESC scd{};


	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
	scd.BufferCount = 1;
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	scd.BufferDesc.Width = gScreenWidth;
	scd.BufferDesc.Height = gScreenHeight;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.OutputWindow = mHwnd;
	scd.Windowed = TRUE;
	scd.SampleDesc.Count = 1;
	scd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;




	D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		0,
		D3D11_SDK_VERSION,
		&scd,
		mspSwapChain.ReleaseAndGetAddressOf(),
		mspDevice.ReleaseAndGetAddressOf(),
		NULL,
		mspDeviceContext.ReleaseAndGetAddressOf()
	);


	OnResize();

}

void D3DFrameWork::OnResize()
{
	/////////////////////////////////////////


	ID3D11RenderTargetView* nullViews[]{ nullptr };
	mspDeviceContext->OMSetRenderTargets(_countof(nullViews), nullViews, nullptr);


	mspRenderTargetView.Reset();
	mspDepthStencilView.Reset();
	mspRenderTarget.Reset();
	mspDepthStencil.Reset();


	mspDeviceContext->Flush();


	/////////////////////////////////////////


	mspSwapChain->ResizeBuffers(0, gScreenWidth, gScreenHeight, DXGI_FORMAT_UNKNOWN, 0);


	// ·»´õÅ¸°Ù
	mspSwapChain->GetBuffer(0, IID_PPV_ARGS(mspRenderTarget.ReleaseAndGetAddressOf()));


	mspDevice->CreateRenderTargetView(mspRenderTarget.Get(),
		nullptr,
		mspRenderTargetView.ReleaseAndGetAddressOf());


	// ±íÀÌ-½ºÅÙ½Ç
	CD3D11_TEXTURE2D_DESC dtd(
		DXGI_FORMAT_D24_UNORM_S8_UINT,
		gScreenWidth, gScreenHeight,
		1,
		1,
		D3D11_BIND_DEPTH_STENCIL
	);


	mspDevice->CreateTexture2D(&dtd, nullptr, mspDepthStencil.ReleaseAndGetAddressOf());


	CD3D11_DEPTH_STENCIL_VIEW_DESC dsvd(D3D11_DSV_DIMENSION_TEXTURE2D);


	mspDevice->CreateDepthStencilView(
		mspDepthStencil.Get(),
		&dsvd,
		mspDepthStencilView.ReleaseAndGetAddressOf()
	);


	// ÆÄÀÌÇÁ¶óÀÎ
	mspDeviceContext->OMSetRenderTargets(
		1, mspRenderTargetView.GetAddressOf(),
		mspDepthStencilView.Get());


	// ºäÆ÷Æ®(View-Port)
	CD3D11_VIEWPORT viewport(0.0f, 0.0f,
		static_cast<float>(gScreenWidth), static_cast<float>(gScreenHeight));


	mspDeviceContext->RSSetViewports(1, &viewport);

}

void D3DFrameWork::RenderFrame()
{
	float clear_color[]{ 0.0f, 0.2f, 0.4f, 1.0f };
	mspDeviceContext->ClearRenderTargetView(mspRenderTargetView.Get(), clear_color);
	mspDeviceContext->ClearDepthStencilView(mspDepthStencilView.Get(),
		D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,
		1.0f,
		0);


	// ±×¸®±â
	mspSwapChain->Present(0, 0);
}



void D3DFrameWork::ReleaseD3D()
{
	mspSwapChain->SetFullscreenState(FALSE, nullptr);


	mspDepthStencilView.Reset();
	mspDepthStencil.Reset();
	mspRenderTargetView.Reset();
	mspRenderTarget.Reset();


	mspSwapChain.Reset();
	mspDevice.Reset();
	mspDeviceContext.Reset();


	DestroyWindow(mHwnd);
	UnregisterClass(gClassName.c_str(), mInstance);
}

void D3DFrameWork::GameLoop()
{
	MSG msg{};
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);


			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			// Game Loop
			RenderFrame();
		}
	}

}

LRESULT D3DFrameWork::MessageHandle(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		if (gResizing)
		{
			RenderFrame();
		}
		else
		{
			PAINTSTRUCT ps;
			BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
		}
	}
	break;


	case WM_SIZE:
		gScreenWidth = LOWORD(lparam);
		gScreenHeight = HIWORD(lparam);

		if (mspDevice)
		{
			if (wparam == SIZE_MINIMIZED)
			{
				gMinimized = true;
				gMaximized = false;
			}
			else if (wparam == SIZE_MAXIMIZED)
			{
				gMinimized = false;
				gMaximized = true;
				OnResize();
			}
			else if (wparam == SIZE_RESTORED)
			{
				if (gMinimized)
				{
					gMinimized = false;
					OnResize();
				}
				else if (gMaximized)
				{
					gMaximized = false;
					OnResize();
				}
				else if (gResizing)
				{


				}
				else
				{
					OnResize();
				}
			}
		}
		return 0;
		break;


	case WM_ENTERSIZEMOVE:
		gResizing = true;
		return 0;
		break;


	case WM_EXITSIZEMOVE:
		gResizing = false;
		OnResize();
		return 0;
		break;


	case WM_MENUCHAR:
		return MAKELRESULT(0, MNC_CLOSE);
		break;


	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lparam)->ptMinTrackSize.x = 640;
		((MINMAXINFO*)lparam)->ptMinTrackSize.y = 480;
		return 0;
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

	return LRESULT();
}

LRESULT D3DFrameWork::WindowProc(HWND hwnd, UINT message,
	WPARAM wparam, LPARAM lparam)
{
	D3DFrameWork* pFramework = reinterpret_cast<D3DFrameWork*>(
		GetWindowLongPtr(hwnd, GWLP_USERDATA));

	return pFramework->MessageHandle(hwnd, message, wparam,lparam);
}
