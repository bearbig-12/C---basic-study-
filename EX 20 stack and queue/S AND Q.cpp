#include <iostream>

char ReadInput();
void PrintInfo();
void PrintTalbe(char start, char end);
char getCharacter(int code);
int main()
{
	char start{ ReadInput() }, end{ ReadInput() };

	PrintInfo();
	
	PrintTalbe(start, end);

}

char ReadInput()
{
	char ch;
	std::cin >> ch;
	return ch;
}

void PrintInfo()
{
	std::cout << std::endl;
	std::cout << "-------ASCII TABLE----------" << std::endl;
}

char getCharacter(int code)
{
	return char(code);
}
void PrintTalbe(char start, char end)
{
	for (int ch = start; ch <= end; ++ch)
	{
		std::cout << ch << "\t" << getCharacter(ch) << std::endl;
	}
}
