#include <iostream>




int main()
{
	//Master #7
	for (int i = 2; i <= 6; ++i)
	{
		for (int a = 6; i < a; --a)
		{
			std::cout << " ";
		}
		for (int j = 1; j < i; ++j)
		{
			std::cout << "*" << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 2; i <= 6; ++i)
	{
		for (int a = 1; a < i; ++a)
		{
			std::cout << " ";
		}
		for (int j = 6; j > i; --j)
		{
			std::cout << "*" << " ";
		}
		std::cout << std::endl;
	}
}