#include <iostream>
#include <cassert>

// assert(��/����);
// ���� ��� ������� (release ��忡�� �۵�����)


//struct  Warrior
//{
//
//};
//void Move_Warrior(Warrior* warrior)
//{
//	assert(warrior != nullptr);
//		
//
//	std::cout << "Normal" << std::endl;
//}

int average(int a, int b, int c)
{
	if (!(a > 0 && a < b && b < c))
	{
		throw std::logic_error("a, b, c should be positive and a < b < c");
	}
	int average{};

	average = (a + b + c) / 3.0;

	if (average < 0)
	{
		throw std::logic_error("average is negative !");
	}

	return average;
}

int main()
{
	/*int x{ 0 };

	assert(x == 10);

	std::cout << "Finish" << std::endl;*/

	//Move_Warrior(nullptr);

	int a, b, c;

	std::cout << "�� ���� �Է� : ";
	std::cin >> a >> b >> c;

	try
	{
		std::cout << average(a, b, c) << std::endl;
	}
	catch (std::logic_error error)
	{
		std::cerr << error.what() << std::endl;
	}
	std::cout << "ver2";


}