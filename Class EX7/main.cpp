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
	static int sCount2;	// ���� ����� ����

public:
	static int sCount;
	MyClass()
	{
		sCount++;	// �ν��Ͻ��� �����ɶ� �ϳ� �߰�
	}
	~MyClass()
	{
		sCount--;	// �ν��Ͻ��� �������� �ϳ� ����
	}
	static void Function()	// �ν��Ͻ��� �ƴ� Ŭ������ ���ӵǾ��� �Լ� �̹Ƿ� this�� ���Ұ���.
	{
		sCount2++;
	}
};

int MyClass::sCount{ 0 };	//���� ����� ����	// ������� �ν��Ͻ��� ������ ���� �Լ�	// Ŭ������ ��ô�Ҷ� ������.
int MyClass::sCount2{ 0 };

int main()
{

	String s1{ "Hello" };
	s1.Print();


	/*const MyClass c1;
	const MyClass c2(2, 2);
	const MyClass c3{ 3,3 };*/

	//c2.mValue1 = 3; ��� ��ü�� ��� �Լ��� ������ �� �� ����.
	
	//MyClass c1;
	//MyClass c2;
	//{
	//	MyClass c3;
	//	std::cout << MyClass::sCount << std::endl;
	//}

	////std::cout << c1.mValue;
	//MyClass::Function();


}