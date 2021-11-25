#include "BuggyHouse.h"

HRESULT BuggyHouse::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
    HRESULT hr = D2DFramWork::Initialize(hInstance, title, width, height);
    ThrowIfFailed(hr, "Failed  D2DFramework::Initialize() Failed");

    mspBackground = std::make_unique<Actor>(
        this,
        L"D:\\Git hub\\SimpleData\\back1_1024.png",
        0.0f, 0.0f
        );

   /* float x, y;
    RECT rct;
    GetClientRect(mHwnd, &rct);*/
    for (int i = 0; i < 40; ++i)
    {
        /*x = static_cast<float>(rand() % (rct.right - rct.left));
        y = static_cast<float>(rand() % (rct.bottom - rct.top));*/

        mBuglist.push_back(std::make_unique<Bug>(
            this
           /* L"D:\\Git hub\\SimpleData\\bug1_1.png", x, y*/
            ));
    }

    return S_OK;
}

void BuggyHouse::Release()
{
    for (auto& bug : mBuglist)
    {
        bug.reset();
    }
    mBuglist.clear();
    mspBackground.reset();
    D2DFramWork::Release();
}

void BuggyHouse::Render()
{
    HRESULT hr;

    mspRenderTarget->BeginDraw();

    mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
    mspRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity());    // ���ڵ带 ���� ����� ��ġ�� 40��° ������ �������� ���������
                                                                    // ���� ����Ÿ���� �����·� ��������ϱ� ������ ��������� �̿��Ͽ� �ʱ�ȭ ���ش�.
    CheckBugs();

    mspBackground->Draw();
    for (auto& bug : mBuglist)
    {
       /* auto pos = bug->GetPosition();

        pos.x += static_cast<FLOAT>(rand() % 3 - 1);
        pos.y += static_cast<FLOAT>(rand() % 3 - 1);

        bug->SetPosition(pos);*/

        bug->Draw();
    }
    hr = mspRenderTarget->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET)
    {
        CreateDeviceResources();
    }


}

void BuggyHouse::CheckBugs()
{
    if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
    {
        POINT pt;
        GetCursorPos(&pt);      // ��ũ�� ��ǥ
        ScreenToClient(mHwnd, &pt);

        auto it = std::remove_if(mBuglist.begin(), mBuglist.end(), [&](auto& actor)
            {
                return actor->isClicked(pt);
            }
        
        );
        mBuglist.erase(it, mBuglist.end());
    }
}
