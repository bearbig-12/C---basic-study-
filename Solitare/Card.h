#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include <memory>

//카드
//종류 ( 용,곰,늑대)
// 앞 뒤면
// 위치 크기 (그리기 정보)
// 클릭하면 뒤집기

namespace solitaire
{
	enum class Type
	{
		Wolf,
		Bear,
		Dragon
	};

	class Card
	{
	private:
		HWND mHwnd;
		int mIndex;
		Type mType;
		bool mIsFront;
		int mX;
		int mY;

		

		std::unique_ptr<Gdiplus::Image> mBack;
		std::unique_ptr<Gdiplus::Image> mFront;

	public:
		Card(HWND hwnd, int index, Type type, int x, int y);

		bool CheckClicked(int cursorX, int cursorY);
		void Flip(bool isFront);
		void Draw(Gdiplus::Graphics& graphics);

		void Invalidate();

		Type GetType() { return mType; }
		int GetIndex() { return mIndex; }
		
	};
}