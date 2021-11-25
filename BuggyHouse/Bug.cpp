#include "Bug.h"

// 동일한 방햑으로 5번(5픽셀까지는 그대로 이동)
// 방향전환(45도단위)
// 8방향 (UP, UP & RIGHT, RIGHT...)


Bug::Bug(D2DFramWork* pFramework):
	Actor(pFramework, L"D:\\Git hub\\SimpleData\\bug1_1.png")
{
	RECT rct{};

	GetClientRect(pFramework->GetWindowHandle(), &rct);

	mX = static_cast<float>(rand() % (rct.right - rct.left));
	mY = static_cast<float>(rand() % (rct.bottom - rct.top));

	mSteps = 0;
	mIsDelete = false;

}

void Bug::Draw()
{
	if (mSteps++ > 10)
	{
		mSteps = 0;
		mRotation += (rand() % 3 - 1) * 45;
	}
	auto curDir = UPVECTOR * D2D1::Matrix3x2F::Rotation(mRotation);
	mX += curDir.x;
	mY += curDir.y;

	auto size{ mpBitmap->GetPixelSize() };
	D2D1_RECT_F rect{ 0.0f,0.0f,static_cast<float>(size.width),static_cast<float>(size.height) };

	auto matTranslate = D2D1::Matrix3x2F::Translation(mX, mY);
	//auto matScale = D2D1::Matrix3x2F::Scale(1.0f, 1.0f);
	auto matRotation = D2D1::Matrix3x2F::Rotation(mRotation, {size.width * 0.5f, size.height * 0.5f});

	auto pRT = mpFramework->GetRenderTarget();

	pRT->SetTransform(matRotation * matTranslate);

	pRT->DrawBitmap(
		mpBitmap,
		rect,
		mOpacity
	);
}

bool Bug::isClicked(POINT& pt)
{
	auto size{ mpBitmap->GetPixelSize() };
	D2D1_RECT_F rect{
		mX,mY,
		static_cast<float>(mX + size.width), static_cast<float>(mY + size.height)
	};
	if (pt.x >= rect.left && pt.x < rect.right &&
		pt.y >= rect.top && pt.y <= rect.bottom)
	{
		mIsDelete = true;
		return true;
	}
	return false;
}
