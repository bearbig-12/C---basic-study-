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

	ClearBuffer(D2D1::ColorF::LightPink);

	/*FillRectToBuffer(0, 0, 100, 100, D2D1::ColorF::Red);
	FillRectToBuffer(50, 50, 100, 100, D2D1::ColorF(0,1,0,0.5f));*/
	//DrawCircleToBuffer(150, 150, 100, D2D1::ColorF::Blue);
	DrawLineToBuffer(0, 0, 100, 100, D2D1::ColorF::Yellow);
	DrawLineToBuffer(100, 0, 0, 100, D2D1::ColorF::Yellow);
	DrawLineToBuffer(0, 50, 100, 50, D2D1::ColorF::Yellow);
	DrawLineToBuffer(50, 0, 50, 100, D2D1::ColorF::Yellow);

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
	UINT8* temp = &mspBackBuffer[0];

	for (int pixel = 0; pixel < BITMAP_WIDTH * BITMAP_HEIGHT; ++pixel)
	{
		// 0.0f ~ 1.0f
		// 0 ~ 255
		*(temp) = static_cast<UINT8>(color.r * 255);
		*(temp + 1) = static_cast<UINT8>(color.g * 255);
		*(temp + 2) = static_cast<UINT8>(color.b * 255);
		*(temp + 3) = static_cast<UINT8>(color.a * 255);

		temp += BITMAP_BYTECOUNT;
	}

	


		
}

void BitmapExample::DrawPixelToBuffer(int x, int y, D2D1::ColorF color)
{
	// Alpha Blending
	// 색혼합 = 기존색상 * ( 1 - a ) + 신규색상 * a
	int pitch = BITMAP_WIDTH * BITMAP_BYTECOUNT;
	int index = pitch * y + x * BITMAP_BYTECOUNT;
	
	float inverse_a = 1.0f - color.a;
	UINT8 Red2 = static_cast<UINT8>(color.r * 255);
	UINT8 Green2 = static_cast<UINT8>(color.g * 255);
	UINT8 Blue2 = static_cast<UINT8>(color.b * 255);

	mspBackBuffer[index] = 
		static_cast<UINT8>(mspBackBuffer[index] * inverse_a + Red2 * color.a);
	mspBackBuffer[index+1] = 
		static_cast<UINT8>(mspBackBuffer[index+1] * inverse_a + Green2 * color.a);
	mspBackBuffer[index+2] = 
		static_cast<UINT8>(mspBackBuffer[index+2] * inverse_a + Blue2 * color.a);
	mspBackBuffer[index + 3] =
		static_cast<UINT8>(color.a * 255);

	 
	
}

void BitmapExample::FillRectToBuffer(int left, int top, int width, int height, D2D1::ColorF color)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			DrawPixelToBuffer(i + left, j + top, color);
		}
	}
}

void BitmapExample::DrawCircleToBuffer(int x, int y, float radius, D2D1::ColorF color)
{
	for (int i = 0; i < 360; ++i)
	{
		auto radian = (i * (3.141592 / 180));
		int _x = (cos(radian) * radius) + x;
		int _y = (sin(radian) * radius) + y;
		DrawPixelToBuffer(_x,_y, color);
	}
}

void BitmapExample::DrawLineToBuffer(int x1, int y1, int x2, int y2, D2D1::ColorF color)
{
	float dx = static_cast<float>(x2 - x1);
	float dy = static_cast<float>(y2 - y1);

	if (dx == 0 && dy == 0)	//두점이 같음
	{
		return;
	}

	int sign{};
	if (abs(dx) > abs(dy))
	{
		sign = (dx < 0) ? -1 : 1;
		for (int x = x1; x != x2; x+=sign)
		{
			int y = static_cast<int>(dy / dx * (x - x1) + y1);
			DrawPixelToBuffer(x, y, color);
		}
	}
	else
	{
		sign = (dy < 0) ? -1 : 1;
		for (int y = y1; y != y2; y += sign)
		{
			int x = static_cast<int>(dx / dy * (y - y1) + x1);
			DrawPixelToBuffer(x, y, color);

		}
	}
	
	
		



}
