#include "ImageEx.h"
#include <fstream>
#include <vector>

#pragma comment(lib, "WindowsCodecs.lib")

HRESULT ImageEx::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;


	// COM
	hr = CoInitialize(nullptr);		// ��� Componete ����� �� �Լ��� �� �ʿ�
	ThrowIfFailed(hr);
	


	hr = ::CoCreateInstance(CLSID_WICImagingFactory,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(mspWICFactory.GetAddressOf())
	);
	ThrowIfFailed(hr);
	
	D2DFramWork::Initialize(hInstance, title, width, height);
	//hr = LoadBMP(L"D:\\Git hub\\SimpleData\\32.bmp", mspBitmap.GetAddressOf());
	hr = LoadWICImage(L"D:\\Git hub\\SimpleData\\1.png", mspBitmap.GetAddressOf()), 
		LoadWICImage(L"D:\\Git hub\\SimpleData\\32.bmp", mspBitmap2.GetAddressOf());
	

	return hr;

}

void ImageEx::Release()
{
	D2DFramWork::Release();

	CoUninitialize();		// ������ �Ҷ� �� ����� ��.
}

void ImageEx::Render()
{
	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Aquamarine));
	mspRenderTarget->DrawBitmap(mspBitmap.Get());
	mspRenderTarget->DrawBitmap(mspBitmap2.Get(), D2D1::RectF(33,0,65, 32));

	mspRenderTarget->EndDraw();
}

HRESULT ImageEx::LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppBitmap)
{
	// 1. ���Ͽ���
	std::ifstream file;
	file.open("D:\\Git hub\\SimpleData\\1.png", std::ifstream::binary);
	file.open("D:\\Git hub\\SimpleData\\32.bmp", std::ifstream::binary);

	// 2. BITMAP FILE HEADER
	BITMAPFILEHEADER bmh;
	file.read(reinterpret_cast<char*>(&bmh), sizeof(BITMAPFILEHEADER));

	// 3. BITMAP INFO HEADER
	BITMAPINFOHEADER bmi;
	file.read(reinterpret_cast<char*>(&bmi), sizeof(BITMAPINFOHEADER));

	if (bmh.bfType != 0x4D42)
	{
		return E_FAIL;
	}
	if (bmi.biBitCount != 32)
	{
		return E_FAIL;
	}
	// 4. bfoffBits  �� ��ŭ �ǳʶٱ�
	file.seekg(bmh.bfOffBits);
	// 5. �ȼ� ������ �б�
	std::vector<char> pPixels(bmi.biSizeImage);
	int pitch = bmi.biWidth * (bmi.biBitCount / 8);
	//file.read(&pPixels[0], (bmi.biSizeImage));
	//for (int y = bmi.biHeight - 1; y >= 0; --y)
	//{
	//	file.read(&pPixels[y*pitch], pitch);
	//}
	for (int y = bmi.biHeight - 1; y >= 0; --y)
	{
		int index = y* pitch;
		for (int x = 0; x < bmi.biWidth; ++x)
		{
			char r{}, g{}, b{}, a{};
			file.read(&b, 1);	// ���ȼ��� �ޱ�
			file.read(&g, 1);
			file.read(&r, 1);
			file.read(&a, 1);

			if (b == (char)250 && g == (char)199 && r == (char)30)	// ������ ���� ��� �����
			{
				r = g = b = a = 0;
			}
			pPixels[index++] = b;	// ���δ� �̹� ������ pitch�� �޾ƿ��� �ƾ��� ���δ� �׳� ���ϱ�
			pPixels[index++] = g;
			pPixels[index++] = r;
			pPixels[index++] = a;

		}
	}

	file.close();

	HRESULT hr = mspRenderTarget->CreateBitmap(
		D2D1::SizeU(bmi.biWidth, bmi.biHeight),
		D2D1::BitmapProperties(
			D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)
		),
		ppBitmap
	);
	ThrowIfFailed(hr);

	hr = (*ppBitmap)->CopyFromMemory(
		nullptr,
		&pPixels[0],
		pitch
		);
	ThrowIfFailed(hr);

	return hr;
}

HRESULT ImageEx::LoadWICImage(LPCWSTR filename, ID2D1Bitmap** ppBitmap)
{

	//WIC

	// 1. ���ڴ��� ����

	Microsoft::WRL::ComPtr<IWICBitmapDecoder> bitmapDecoder;
	
	HRESULT hr;
	

	hr = mspWICFactory->CreateDecoderFromFilename(
		filename,
		nullptr,
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad,
		bitmapDecoder.GetAddressOf()
	);
	ThrowIfFailed(hr);




	// 2. ������ ����
	Microsoft::WRL::ComPtr<IWICBitmapFrameDecode> frame;
	hr = bitmapDecoder->GetFrame(0, frame.GetAddressOf());
	ThrowIfFailed(hr);




	// 3. Format Converter - �츮�� ���ϴ� BGRA8888
	Microsoft::WRL::ComPtr<IWICFormatConverter> converter;
	hr = mspWICFactory->CreateFormatConverter(converter.GetAddressOf());
	ThrowIfFailed(hr);

	

	hr = converter->Initialize(
		frame.Get(),
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0,				//threshold
		WICBitmapPaletteTypeCustom
		);
	ThrowIfFailed(hr);



	// 4.  �ȼ� �迭
	mspRenderTarget->CreateBitmapFromWicBitmap(
		converter.Get(),
		mspBitmap.GetAddressOf()
	);
	mspRenderTarget->CreateBitmapFromWicBitmap(
		converter.Get(),
		mspBitmap.GetAddressOf()
	);
	ThrowIfFailed(hr);

	
	return hr;
}
