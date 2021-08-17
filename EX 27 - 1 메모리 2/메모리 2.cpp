#include <iostream>

// C++ ��Ÿ�� ���� �Ҵ�
	// ������ ���� = new Ÿ��;
	// delete ������ ����
	// new �� delete �� ���� ������

// ���α׷� �޸� ����
	// 1. Code or Text
	// ���� �ڵ�
	// 
	// *2. Data
	// ���α׷� ���۽ÿ� �Ҵ�, ����ÿ� ��ü
	// ��������
	//
	// *3. Heap or Free
	// ����ÿ� �������� �Ҵ�
	// ���� �Ҵ�
	//
	// 4. Register
	// �Լ��ּ�
	//
	// *5. Stack
	// �Լ� ȣ�� �� �����Ǵ� �Ű����� �� ��������, �Լ� ��ȯ�� �Բ� ���� 
	// ��������, �Ű�����

void MyFunction1();
void MyFunction2();

char gString[]{ "Memory LayOut" };
int gInteger;

int main()
{
	//int* p{ new int{4} };

	//int* p;
	//p = new int;
	//*p = 4;

	//std::cout << *p << std::endl;

	//delete p;

	std::cout << (void*)gString << std::endl;
	std::cout << &gInteger << std::endl;

	int* p = new int;

	std::cout << "main::p - " << p << std::endl;

	MyFunction1();

	delete p;
}

void MyFunction1()
{
	int local;
	std::cout << "MyFunction1::local - " << &local << std::endl;

	MyFunction2();
}
void MyFunction2()
{
	int local;
	std::cout << "MyFunction2::local - " << &local << std::endl;

}