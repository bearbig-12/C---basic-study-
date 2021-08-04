#include <iostream>

int main()
{
	int Array[5]{0};
	int sum{ 0 };
	for (int i = 0; i < 5; ++i)
	{
		if (i == 0)
		{
			std::cout << i + 1 << " st " << "Please Insert your grade : ";
		}
		else if (i == 1)
		{
			std::cout << i + 1 << " nd " << "Please Insert your grade : ";
		}
		else if (i == 2)
		{
			std::cout << i + 1 << " rd " << "Please Insert your grade : ";
		}
		else
		{
			std::cout << i + 1 << " th " << "Please Insert your grade : ";
			
		}
		std::cin >> Array[i];
		
	}
	for (int i = 0; i < 5; ++i)
	{
		
		sum += Array[i];
	}
	std::cout << " 5명의 점수의 합 : " << sum << std::endl;
	std::cout << "평균 점수 : " << sum / 5 << std::endl;
}