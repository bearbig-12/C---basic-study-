#include <iostream>

int main()
{
	int input{};

	std::cout << "숫자를 입력 하세요 ";
	std::cin >> input;
	int absoluteNumber;

	int result;

	/*if (input >= 0)
	{
		absoluteNumber = input;
	}
	else
	{
		absoluteNumber = -input;
	}*/

	absoluteNumber = (input >= 0) ? input :  -input;

	std::cout << "절대 값 : " << result;

}