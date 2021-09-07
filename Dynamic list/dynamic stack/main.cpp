#include<iostream>
#include "DynamicStack.h"


void Printinfo()
{
	std::cout << "<STACK>" << std::endl;
	std::cout << " 1 - Push " << std::endl;
	std::cout << " 2 - Pop " << std::endl;
	std::cout << " 3 - EXIT " << std::endl;
	std::cout << "- - - - - - - - - - - - -" << std::endl;
}

void ProcessUserInput(Stack& stack)
{
	int command{ 0 };

	while (true)
	{
		Print(stack);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> command;

		switch (command)
		{
		case PUSH:
		{
			int value;
			std::cout << "		Push value : ";
			std::cin >> value;
			Push(stack, value);
			break;
		}
		case POP:
		{
			Pop(stack);
			break;
		}
		case EXIT:
		{
			return;
			break;
		}
		default:
			std::cout << "잘못된 명령 입니다!!" << std::endl;
			break;
		}
	}
}

int main()
{
	Stack mystack;

	Initialize(mystack);

	Printinfo();
	ProcessUserInput(mystack);

	Release(mystack);
}