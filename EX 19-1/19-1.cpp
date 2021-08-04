#include<iostream>

int Sum(int array[])
{
	int result{ 0 };
	//std::cout << sizeof(array) << std::endl;	// 4가 나오지만 원소의 갯수는 아님 포인터값임
	for (int i = 0; i <= 5; ++i)
	{
		result = result + array[i];
	}
	return result;
}
char CovertToUpperCase(char input)
{
	if (input >= 'a' && input <= 'z')
	{
		return input - 'a' + 'A';
	}
	else
	{
		return input;
	}
}

int main()
{
	//int Numbers[]{ 1, 2, 3, 4, 5 };

	//std::cout << Sum(Numbers) << std::endl;

	char buffer[50]{ "Hello World! ! !" };
	for (int i = 0; i < 50; ++i)
	{
		std::cout << CovertToUpperCase(buffer[i]);
	}
}