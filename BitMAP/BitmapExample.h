#pragma once
#include "D2DFramWork.h"

// ������ �׷��� ī��
//		FrameBuffer : 1024 x 768 bitmap
//		BackBuffer -> FrameBuffer
//		�ùķ��̼� FrameBuffer�� �׷����� ��.

const int BITMAP_WIDTH = 1024;
const int BITMAP_HEIGHT = 768;
const int BITMAP_BYTECOUNT = 4; //RGBA
class BitmapExample :
	public D2DFramWork
{
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspFrameBitmap{};
	std::unique_ptr<UINT8[]> mspBackBuffer{};
public:
	virtual HRESULT Initialize(HINSTANCE hInstance,
		LPCWSTR title = L"MyFrameWork",
		UINT width = 1024,
		UINT height = 768);

	virtual void Render() override;

	void PresentBuffer();
	void ClearBuffer(D2D1::ColorF color);
};

