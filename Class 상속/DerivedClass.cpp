#include <iostream>
class ClassA	
{
public:
	ClassA()
	{
		std::cout << "ClassA::ClassA()" << std::endl;
	}
};

class ClassB
{
	ClassA mA;	// 멤버를 가지고있는 경우 클래스 A를 먼저 만들고 Class B를 생성한다.
public:
	ClassB()
	{
		std::cout << "ClassB::ClassB()" << std::endl;
	}

};

class ClassC
{

public:
	class ClassD
	{
	
	};

private:
	ClassD mD;
};

//
//int main()
//{
//	ClassC myClass;
//
//	ClassC::ClassD c;	// 클래스 C에 들어있는 클래스 D에 접근하는 것뿐 ClassC는 생성하지 않음
//
//}
