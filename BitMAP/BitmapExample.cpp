#include "BitmapExample.h"

HRESULT BitmapExample::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	D2DFramWork::Initialize(hInstance, title, width, height);

	//가상 BackBuffer
	mspBackBuffer = std::make_unique<UINT8[]>(
		BITMAP_WIDTH * BITMAP_HEIGHT * BITMAP_BYTECOUNT
		);
	
	// 가상 FrameBuffer
	HRESULT hr = mspRenderTarget->CreateBitmap(
		D2D1::SizeU(BITMAP_WIDTH, BITMAP_HEIGHT),
		D2D1::BitmapProperties(
			D2D1::PixelFormat(DXGI_FORMAT_R8G8B8A8_UNORM, D2D1_ALPHA_MODE_IGNORE)
		),
		mspFrameBitmap.GetAddressOf()
	);
	ThrowIfFailed(hr);
	return hr;
}

void BitmapExample::Render()
{
	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	PresentBuffer();
	mspRenderTarget->DrawBitmap(mspFrameBitmap.Get());

	mspRenderTarget->EndDraw();
}

void BitmapExample::PresentBuffer()
{
	mspFrameBitmap->CopyFromMemory(nullptr, mspBackBuffer.get(), 
		BITMAP_WIDTH * BITMAP_BYTECOUNT);
}

void BitmapExample::ClearBuffer(D2D1::ColorF color)
{
	auto temp = mspBackBuffer[0];
	
	for (int i = 0; i < BITMAP_WIDTH * BITMAP_HEIGHT; ++i)
	{
		temp
	}


		
}
