#include <iostream>
#include "Dog.h"
//class classA
//{
//public:
//	void func(int i) 
//	{
//		
//	}
//	void func(float f, int i)
//	{
//		std::cout << "work" << std::endl;
//	}
//};
//
//class classB : public classA
//{
//public:
//	void func(int i){}
//};

int main()
{
	Dog happy{ Dog::BREED::SHINTZU, 15, 3 };
	//happy.SetWeight(Dog::BREED::SHINTZU);
	//happy.SetAge(15);

	//happy.Sound();
	//happy.Roll();

	Animal* Clone = happy.Clone();

	Clone->Sound();
	std::cout << Clone->GetAge() << std::endl;
	std::cout << ((Dog*)Clone)->GetBreed() << std::endl;

	/*classB b;
	b.classA::func(10.0f, 1);*/

	//Animal* p = new Dog;
	//p->Sound();

	//delete p; // �̰��  Animal�� �������� Dog�� �������� �ʰ� �ȴ�
	//		  // ���� Animal �Ҹ��ڿ� virtual�� �ٿ� Dog�� ������ �Ѵ�
	//		  // EX) virtual ~Animal()
}
