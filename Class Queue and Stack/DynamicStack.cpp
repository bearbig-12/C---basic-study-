#include "DynamicStack.h"
#include <iostream>



void Stack::UserInput(Stack& stack)
{
	int type{ 0 };


	while (true)
	{
		Stack::Print(stack);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> type;
		if (type == mPUSH)
		{
			int value;
			std::cout << " Push value : ";
			std::cin >> value;
			Push(stack, value);
			
		}
		else if (type == mPOP)
		{
			Pop(stack);
			
		}
		else if (type == mSTOP)
		{
			std::cout << "Stop the function" << std::endl;
			break;
		}
		else
		{
			std::cout << "Thas's not invalid type of number," << " please read information carfully" << std::endl;
			
		}
	}
}

void Stack::Push(Stack& stack, int value)
{
	Element* element = new Element;
	element->mValue = value;
	stack.mCount++;

	element->mpNext = stack.mTop;
	stack.mTop = element;

	std::cout << "Push : " << value << std::endl;
}

void Stack::Pop(Stack& stack)
{
	Element* element = stack.mTop;
	if (stack.mCount <= 0)
	{
		std::cout << "Empty" << std::endl;
	}
	stack.mTop = element->mpNext;
	element->mpNext = nullptr;
	std::cout << "Pop : " << element->mValue << std::endl;
	delete element;
	stack.mCount--;
}

void Stack::Print(const Stack& stack)
{
	Element* element = stack.mTop;
	while (element != nullptr)
	{
		std::cout << element->mValue << std::endl;
		element = element->mpNext;
		
	}
}
