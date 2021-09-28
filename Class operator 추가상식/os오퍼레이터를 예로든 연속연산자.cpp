#include <iostream>

class Charater
{
public:
	Charater& move()
	{
		//...
		return *this;
	}

	Charater& turnLeft()
	{
		//...
		return *this;
	}

	Charater& turnRigjt()
	{
		//...
		return *this;
	}
};


//int main()
//{
//	Charater player;
//
//	player.move().turnLeft().turnRigjt();
//
//	// 자기자신을 반환할때는 이렇게도 사용가능.
//}