#include <iostream>


int main()
{
	//3¹ø ¹®Á¦
	
	char input[10]{  };
	std::cin >> input;

	for (int i = 0; i < sizeof(input); ++i)
	{
		if (input[i] == '\0')
		{
			break;
		}
		input[i] = input[i] - 32;
	}
	for (int i = 0; i < sizeof(input); ++i)
	{
		if (input[i] == '\0')
		{
			break;
		}
		std::cout << input[i];
	}
}