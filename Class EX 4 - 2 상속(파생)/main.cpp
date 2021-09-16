#include <iostream>
class ClassA
{
public:
	ClassA()
	{
		std::cout << "ClassA()" << std::endl;
	}
};

class ClassB
{
		// 멤버를 가지고있는 경우 클래스 A를 먼저 만들고 Class B를 생성한다.
public:
	ClassB()
	{
		std::cout << "ClassB()" << std::endl;
	}

};

class ClassC
{
	ClassA mA;	// 멤버변수
	ClassB mB;
public:
	ClassC() : mA{}, mB{}	// 초기화 리스트의 순서는 멤버 변수의 순서대로 적기.
	{
		std::cout << "ClassC()" << std::endl;
	}

private:
	
};

int main()
{
	ClassC c;

}