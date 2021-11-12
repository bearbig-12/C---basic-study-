#pragma once
#include "Card.h"
#include <list>
//게임
//	40장의 카드 관리( 8*5 )
//	비교(2장이 매칭)
//	클릭수
//	게임진행
//	클리어 조건
//	배경 그리기 + 카드 그리기
// 클릭된 카드 체크


namespace solitaire
{
	class GameLogic
	{
	private:
		const int BOARD_ROW{ 5 };
		const int BOARD_COLUMN{ 8 };
		const Gdiplus::RectF BOARD_COUNT_RECT{ 885.0f, 60.0f,120.0f,30.0f };

		std::unique_ptr<Gdiplus::Image> mBackGround;
		std::list<Card> mDeck;

		HWND mHwnd;
		int mFlipCount;

		Card* mpSelected;
		
	public:
		void Initialize(HWND hwnd);
		void Release();
		void Draw(Gdiplus::Graphics& graphics);
		void OnClick(int cursorX, int cursorY);

	private:
		void CreateCards();
	};
}


