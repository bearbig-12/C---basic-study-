#include <iostream>

int main()
{
	std::cout << "C++�� ��Ʈ �����ڸ� �Է��ϼ��� : ";
	char inputOperator;
	std::cin >> inputOperator;

	switch (inputOperator)
	{
	case '!':
		std::cout << "���� ������" << std::endl;
		break;
	 
	case '^' :
	case'|':
	case '&':
		std::cout << "���� ������" << std::endl;
		break;

	default:
		std::cout << "��Ʈ������ �ƴ�!" << std::endl;

		break;
	}
}