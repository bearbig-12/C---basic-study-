#include <string>
#include "Card.h"
namespace solitaire
{
	Card::Card(HWND hwnd, Type type, int x, int y) :
		mHwnd {hwnd},
		mType{type},
		mIsFront{false},
		mX{x},
		mY{y}
	{
		std::wstring filename;
		switch (mType)
		{
		case Type::Wolf:
			filename = L"data/card_creature_wolf.png";
			break;
		case Type::Bear:
			filename = L"data/card_creature_bear.png";
			break;
		case Type::Dragon:
			filename = L"data/card_creature_dragon.png";
			break;
		}
		mFront = std::make_unique<Gdiplus::Image>(filename.c_str());
		mBack = std::make_unique<Gdiplus::Image>(L"data/card_back.png");
	}

	bool Card::CheckClicked(int cursorX, int cursorY)
	{
		if (cursorX >= mX && cursorY >= mY &&
			cursorX <= static_cast<int>(mX + mFront->GetWidth()) && 
			cursorY <= static_cast<int>(mY + mFront->GetHeight()))
		{
			Flip(!mIsFront);
			return true;
		}
		return false;
	}

	void Card::Flip(bool isFront)
	{
		mIsFront = isFront;
		Invalidate();
	}

	void Card::Draw(Gdiplus::Graphics& graphics)
	{
		if (mIsFront)
		{
			graphics.DrawImage(mFront.get(), mX, mY, mFront->GetWidth(), mFront->GetHeight());

		}
		else
		{
			graphics.DrawImage(mBack.get(), mX, mY, mBack->GetWidth(), mBack->GetHeight());
		}
	}

	void Card::Invalidate()
	{
		RECT rct{
			mX,mY,
			static_cast<LONG>(mX + mFront->GetWidth()), 
			static_cast<LONG>(mY + mFront->GetHeight())
		};
		InvalidateRect(mHwnd, &rct, false);
	}

}
