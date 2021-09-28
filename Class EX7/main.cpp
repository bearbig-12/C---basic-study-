#include <iostream>
#include "String.h"

//class MyClass
//{
//public:
//	int mValue1;
//	int mValue2;
//
//	MyClass() : MyClass(1, 1)
//	{
//		
//	}
//	MyClass(int v1, int v2) : mValue1{ v1 }, mValue2{ 2 }
//	{
//
//	}
//
//	void SetValue1(int x)
//	{
//		mValue1 = x;
//	}
//	void DoNothing()
//	{
//
//	}
//};

class MyClass
{
private:
	static int sCount2;	// 정적 멤버의 선언

public:
	static int sCount;
	MyClass()
	{
		sCount++;	// 인스턴스가 생성될때 하나 추가
	}
	~MyClass()
	{
		sCount--;	// 인스턴스가 없어질때 하나 빼기
	}
	static void Function()	// 인스턴스가 아닌 클래스에 종속되었는 함수 이므로 this가 사용불가능.
	{
		sCount2++;
	}
};

int MyClass::sCount{ 0 };	//정적 멤버의 정의	// 만들어진 인스턴스의 갯수를 세는 함수	// 클래스를 추척할때 유용함.
int MyClass::sCount2{ 0 };

int main()
{

	String s1{ "Hello" };
	s1.Print();


	/*const MyClass c1;
	const MyClass c2(2, 2);
	const MyClass c3{ 3,3 };*/

	//c2.mValue1 = 3; 상수 객체의 멤버 함수는 변경을 할 수 없다.
	
	//MyClass c1;
	//MyClass c2;
	//{
	//	MyClass c3;
	//	std::cout << MyClass::sCount << std::endl;
	//}

	////std::cout << c1.mValue;
	//MyClass::Function();


}