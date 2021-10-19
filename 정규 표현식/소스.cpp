#include <iostream>
#include <regex>

int main()
{
	std::cout << "이메일 : ";
	std::string email;
	std::cin >> email;

	std::regex pattern(R"((\w+[\.]*)@(\w+[\w\.]*)\.([A-Za-z]+))");

	if (std::regex_match(email, pattern))
	{
		std::cout << "올바른 이메일 입니다" << std::endl;
	}
	else
	{
		std::cout << "잘못된 이메일 입니다" << std::endl;
	}

	//std::cout << "Hello" << " " << "world" << std::endl;
}