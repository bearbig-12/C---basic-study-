#include <iostream>

int main()
{
	double height{};
	double weight{};
	

	std::cout << "Hello this is BMI calculator, please Insert your Height(m) and Weight(kg) : ";
	std::cin >> height >> weight;

	double BMI = weight / (height * height);
	std::cout << "Your BMI rate is : " << BMI << std::endl;
	
	if (BMI < 18.5)
	{
		std::cout << "You are underweight";
	}
	else if ((BMI >= 18.5) && (BMI < 22.9))
	{
		std::cout << "You are Normal";
	}
	else if ((BMI >= 23) && (BMI < 24.9))
	{
		std::cout << "You are in Danager";
	}
	else if ((BMI >= 25) && (BMI < 29.9))
	{
		std::cout << "You are in Level 1 obesity";
	}
	else if (BMI >= 30)
	{
		std::cout << "You are in Level 2 obesity";
	}



}