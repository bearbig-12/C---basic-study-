#include <iostream>
#include <regex>

int main()
{
	std::cout << "�̸��� : ";
	std::string email;
	std::cin >> email;

	std::regex pattern(R"((\w+[\.]*)@(\w+[\w\.]*)\.([A-Za-z]+))");

	if (std::regex_match(email, pattern))
	{
		std::cout << "�ùٸ� �̸��� �Դϴ�" << std::endl;
	}
	else
	{
		std::cout << "�߸��� �̸��� �Դϴ�" << std::endl;
	}

	//std::cout << "Hello" << " " << "world" << std::endl;
}