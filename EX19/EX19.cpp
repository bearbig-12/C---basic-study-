#include <iostream>

extern int myGlobalInteger;	//외부(현재에선 Mysource.cpp에서)에서 다른 소수코드의 변수를 가져다 쓰고싶을때. // Global variable 과 같이 사용금지.

void Myfunc()
{
	int myVariable{ 0 };
	static int myNumber{ 0 };	// 스태틱 변수는 오직한번만 생성되고 프로그램이 종료 될때까지 살아있는다 즉) 함수가 밖으로 벗어나도 프로그램이 끝나지 않는한 살아있다.

	myVariable += 1;
	myNumber += 1;

	std::cout << myVariable << " "  << myNumber << std::endl;
}
int main()
{

	Myfunc();
	Myfunc();
	Myfunc();
	Myfunc();
	Myfunc();

	//std::cout << myGlobalInteger << std::endl;
}
