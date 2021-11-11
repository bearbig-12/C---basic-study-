#include "GameLogic.h"
#include <string>
namespace solitaire
{
	void GameLogic::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mFlipCount = 0;
		mDeck.clear();

		mBackGround = std::make_unique<Gdiplus::Image>(L"data/bg_blank.png");
		CreateCards(); 
	}
	void GameLogic::Release()
	{
		mDeck.clear();
		mBackGround.reset();
	}
	void GameLogic::Draw(Gdiplus::Graphics& graphics)
	{
		graphics.DrawImage(mBackGround.get(), 0, 0, mBackGround->GetWidth(), mBackGround->GetHeight());

		for (auto& card : mDeck)
		{
			card.Draw(graphics);

		}
		Gdiplus::SolidBrush brush(Gdiplus::Color::DarkGreen);
		Gdiplus::Font font(L"¸¼Àº °íµñ", 20); 
		Gdiplus::PointF pos(895.0f, 20.0f);

		graphics.DrawString(L"Å¬¸¯¼ö : ", -1, &font, pos, &brush);
		Gdiplus::StringFormat format;
		format.SetAlignment(Gdiplus::StringAlignmentCenter);
		format.SetLineAlignment(Gdiplus::StringAlignmentCenter);
		graphics.DrawString(std::to_wstring(mFlipCount).c_str(), -1, &font, BOARD_COUNT_RECT, &format, &brush);

	}
	void GameLogic::OnClick(int cursorX, int cursorY)
	{
		for (auto& card : mDeck)
		{
			if (card.CheckClicked(cursorX, cursorY))
			{
				//TODO

			}
		}
	}
	void GameLogic::CreateCards()
	{
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Bear, 0, 0));
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Wolf, 120, 0));
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Dragon, 240, 0));
	}
}