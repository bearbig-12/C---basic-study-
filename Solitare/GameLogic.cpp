#include "GameLogic.h"
#include <string>
#include <vector>
#include <random>

// 카드 : 현재 클릭한 카드
// 1. GUI 갱신 : 클릭수 증가
// 2. 이전에 선택한 카드(selected)가 없으면 현재 카드를 선택함
//		selected = card
//		뒤집기
// 3. 이전에 선택한 카드(selected)가 있으면
//		selected == card 타입
//		두장제거
//		selected = null
//		
//		selected !=  card 타입
//		두장모두 다시 뒤집기
//		selected = null


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
		Gdiplus::Font font(L"맑은 고딕", 20); 
		Gdiplus::PointF pos(895.0f, 20.0f);

		graphics.DrawString(L"클릭수 : ", -1, &font, pos, &brush);
		Gdiplus::StringFormat format;
		format.SetAlignment(Gdiplus::StringAlignmentCenter);
		format.SetLineAlignment(Gdiplus::StringAlignmentCenter);
		graphics.DrawString(std::to_wstring(mFlipCount).c_str(), -1, &font, BOARD_COUNT_RECT, &format, &brush);

	}
	void GameLogic::OnClick(int cursorX, int cursorY)
	{
		Card* pCard{};
		
		for (auto& card : mDeck)
		{
			
			if (card.CheckClicked(cursorX, cursorY))
			{
				pCard = &card;
				break;
			}
		}
		
		if (pCard)
		{
			mFlipCount++;
			RECT rct{
				BOARD_COUNT_RECT.GetLeft(), BOARD_COUNT_RECT.GetTop(),
				BOARD_COUNT_RECT.GetRight(), BOARD_COUNT_RECT.GetBottom()
			};
			InvalidateRect(mHwnd, &rct, false);
			if (mpSelected == nullptr)
			{
				mpSelected = pCard;
			}
			else
			{
				if (mpSelected == pCard)
				{
					mpSelected = nullptr;
				}
				else
				{
					if (mpSelected->GetType() == pCard->GetType())
					{
						UpdateWindow(mHwnd);
						Sleep(500);				// 0.5초 뒤에 지워짐

						pCard->Invalidate();
						mpSelected->Invalidate();	//화면갱신을 위한 

						mDeck.remove_if([&](Card& card) {
							return (card.GetIndex() == mpSelected->GetIndex() ||
								card.GetIndex() == pCard->GetIndex());
							});
						
						

						mpSelected = nullptr;
					}
					else
					{
						UpdateWindow(mHwnd);
						//ms
						// 1 s = 1000ms
						Sleep(500);
						pCard->Flip(false);
						mpSelected->Flip(false);

						mpSelected = nullptr;
					}
				}
	
			}
		}
	}
	void GameLogic::CreateCards()
	{
		std::vector<Type> types;
		while (types.size() < static_cast<size_t>(BOARD_ROW) * BOARD_COLUMN)
		{
			int mod = types.size() % 6;

			switch (mod)
			{
			case 0:
				types.push_back(Type::Bear);
				types.push_back(Type::Bear);
				break;
			case 2:
				types.push_back(Type::Wolf);
				types.push_back(Type::Wolf);
				break;
			case 4:
				types.push_back(Type::Dragon);
				types.push_back(Type::Dragon);
				break;
			}
		}
		std::random_device rd;
		std::mt19937 gen(rd());

		std::shuffle(types.begin(), types.end(), gen);

		int posX{ 15 }, posY{ 10 };
		int index = 0;

		for (int x = 0; x < BOARD_COLUMN; ++x)
		{
			posY = 10; 
			for (int y = 0; y < BOARD_ROW; ++y)
			{
				mDeck.push_back(Card(mHwnd, index ,types[index++], posX, posY));
				posY += 140 + 10;	// 카드 한장의 크기 140  카드사이에 공백 10
			}
			posX += 100 + 10;		// 카드의 가로 100 + 공백 10
		}

		/*mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Bear, 0, 0));
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Wolf, 120, 0));
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Dragon, 240, 0));*/
	}
}