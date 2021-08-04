#include <iostream>

int main()
{
	std::cout << "C++의 비트 연산자를 입력하세요 : ";
	char inputOperator;
	std::cin >> inputOperator;

	switch (inputOperator)
	{
	case '!':
		std::cout << "단항 연산자" << std::endl;
		break;
	 
	case '^' :
	case'|':
	case '&':
		std::cout << "이항 연산자" << std::endl;
		break;

	default:
		std::cout << "비트연사자 아님!" << std::endl;

		break;
	}
}