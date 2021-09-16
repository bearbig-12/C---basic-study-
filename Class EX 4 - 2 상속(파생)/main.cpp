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
		// ����� �������ִ� ��� Ŭ���� A�� ���� ����� Class B�� �����Ѵ�.
public:
	ClassB()
	{
		std::cout << "ClassB()" << std::endl;
	}

};

class ClassC
{
	ClassA mA;	// �������
	ClassB mB;
public:
	ClassC() : mA{}, mB{}	// �ʱ�ȭ ����Ʈ�� ������ ��� ������ ������� ����.
	{
		std::cout << "ClassC()" << std::endl;
	}

private:
	
};

int main()
{
	ClassC c;

}