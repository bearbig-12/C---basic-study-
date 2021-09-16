#pragma once
class Quest
{
private:
	/*const int mID;
	const int mEXP;*/
	int mID;
	int mEXP;
public:
	// 초기화 리스트(Initializer List)
	// <생성자> : 초기화식1, 초기화식2, 초기화식3 ...
	
	// Delegating Constructor : 대리 생성자, 생성자 위임


	//Quest(int id = 1, int exp = 0) : mID{ id }, mEXP{ exp }	//객체가 만들어지는 시점에 초기화 하기 때문에 상수라고 해도 초기화 가능.
	//{

	//}

	Quest() : mID{ 1 }, mEXP{ 0 }
	{

	}
	Quest(int id, int exp ) : Quest()	// 대리 생성자
	{
		mID = id;
		mEXP = exp;
	}

	

	void Print();
	
};

