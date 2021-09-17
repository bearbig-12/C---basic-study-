#include <iostream>
#include "DynamicStack.h"

void PrintInformation()
{
	std::cout << "-----Welcome to Stack Function-----" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "[1] - PUSH " << std::endl;
	std::cout << "[2] - POP " << std::endl;
	std::cout << "[3] - STOP " << std::endl;
	std::cout << "-----------------------------------" << std::endl;

}



int main()
{

	PrintInformation();
	Stack st1;

	st1.UserInput(st1);
}