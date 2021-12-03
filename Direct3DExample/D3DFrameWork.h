#pragma once

#define WIN32_LEAN_AND_MEAN


#include <windows.h>
#include <string>
#include <wrl/client.h>
#include <d3d11.h>

class D3DFrameWork
{
private:
	const std::wstring gClassName{ L"MyWindowClass" };
	const std::wstring gTitle{ L"Direct3D Example" };

protected:
	int gScreenWidth{ 800 };
	int gScreenHeight{ 600 };
	bool gMinimized{ false };
	bool gMaximized{ false };
	bool gResizing{ false };

	HWND mHwnd{};
	HINSTANCE mInstance{};

	Microsoft::WRL::ComPtr<ID3D11Device>			mspDevice{};
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>		mspDeviceContext{};
	Microsoft::WRL::ComPtr<IDXGISwapChain>			mspSwapChain{};
	Microsoft::WRL::ComPtr<ID3D11Texture2D>			mspRenderTarget{};
	Microsoft::WRL::ComPtr<ID3D11Texture2D>			mspDepthStencil{};
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> mspRenderTargetView{};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> mspDepthStencilView{};

	
private:
	void InitWindow(HINSTANCE hInstance);
	void InitD3D();

protected:
	void OnResize();
	void RenderFrame();

public:
	virtual void Initialize(HINSTANCE hInstance,
		int width = 800,
		int height = 600
	);
	virtual void ReleaseD3D();
	virtual void GameLoop();

public:
	LRESULT CALLBACK MessageHandle(HWND hwnd, UINT message,
		WPARAM wparam, LPARAM lparam);
	static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);


};

