#include <iostream>

extern int myGlobalInteger;	//�ܺ�(���翡�� Mysource.cpp����)���� �ٸ� �Ҽ��ڵ��� ������ ������ ���������. // Global variable �� ���� ������.

void Myfunc()
{
	int myVariable{ 0 };
	static int myNumber{ 0 };	// ����ƽ ������ �����ѹ��� �����ǰ� ���α׷��� ���� �ɶ����� ����ִ´� ��) �Լ��� ������ ����� ���α׷��� ������ �ʴ��� ����ִ�.

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
