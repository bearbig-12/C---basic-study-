#pragma once
#include "D2DFramWork.h"
#include <vector>
#include <wincodec.h>

// ���� -> �ٸ� ����
//      ��ȣȭ(EnCoding) - �ڵ�(Codec)
//      <-
//      ��ȣȭ(DeCoding)


class ImageEx :
    public D2DFramWork
{

    Microsoft::WRL::ComPtr<IWICImagingFactory> mspWICFactory;
    Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap;
    Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap2;
    Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap3;

public:
    virtual HRESULT Initialize(
        HINSTANCE hInstance,
        LPCWSTR title = L"Bitmap Example",
        UINT width = 1024,
        UINT height = 768
    ) override;

    virtual void Release() override;

    virtual void Render() override;

public:
    HRESULT LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppBitmap);

    HRESULT LoadWICImage(LPCWSTR filename, ID2D1Bitmap** ppBitmap);
};

