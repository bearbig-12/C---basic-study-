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
	ClassA mA;	// ����� �������ִ� ��� Ŭ���� A�� ���� ����� Class B�� �����Ѵ�.
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
//	ClassC::ClassD c;	// Ŭ���� C�� ����ִ� Ŭ���� D�� �����ϴ� �ͻ� ClassC�� �������� ����
//
//}
