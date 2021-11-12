#pragma once
#include "Card.h"
#include <list>
//����
//	40���� ī�� ����( 8*5 )
//	��(2���� ��Ī)
//	Ŭ����
//	��������
//	Ŭ���� ����
//	��� �׸��� + ī�� �׸���
// Ŭ���� ī�� üũ


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


