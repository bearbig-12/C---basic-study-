#include <iostream>

int main()
{
	int input{};

	std::cout << "���ڸ� �Է� �ϼ��� ";
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

	std::cout << "���� �� : " << result;

}