#pragma once
#include <memory>
#include "Actor.h"
class ActorExample :
    public D2DFramWork
{
    std::unique_ptr<Actor> mspBackground;
    std::unique_ptr<Actor> mspBug;
public:
    virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"Actor EX",
        UINT width = 1024, UINT height = 768) override
    {
        HRESULT hr = D2DFramWork::Initialize(hInstance, title, width, height);
        ThrowIfFailed(hr);

        mspBackground = std::make_unique<Actor>(this, L"D:\\Git hub\\SimpleData\\back1_1024.png",0,0);
        mspBug = std::make_unique<Actor>(this, L"D:\\Git hub\\SimpleData\\bug1_1.png", 500.0f, 300.0f);
        return S_OK;

    }
    virtual void Release() override
    {
        mspBug.reset();
        mspBackground.reset();
        D2DFramWork::Release();
    }
    virtual void Render() override
    {
        HRESULT hr;
        mspRenderTarget->BeginDraw();
        mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.0f, 0.0f, 1.0f));
        mspBackground->Draw();
        mspBug->Draw();
        hr = mspRenderTarget->EndDraw();
        if(hr==D2DERR_RECREATE_TARGET)
        {
            CreateDeviceResources();
        }
    }
};

