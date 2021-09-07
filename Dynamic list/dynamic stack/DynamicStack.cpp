#include "DynamicStack.h"
#include <iostream>
void Initialize(Stack& stack)
{
	stack.count = 0;
	stack.top = nullptr;
}

void Release(Stack& stack)
{
	Element* element = stack.top;
	while (element != nullptr)
	{
		Element* next = element->pNext;
		delete element;
		element = next;
	}

	Initialize(stack);
}

void Push(Stack& stack, int value)
{
	Element* element = new Element;
	element->value = value;
	stack.count++;
	
	element->pNext = stack.top;
	stack.top = element;

	std::cout << "Push : " << value << std::endl;
}

bool Pop(Stack& stack)
{
	Element* element = stack.top;
	
	if (stack.count <= 0)
	{
		std::cout << "The Stack is Empty" << std::endl;
		return false;
	}
	stack.top = element->pNext;
	element->pNext = nullptr;
	std::cout << "Pop : " << element->value << std::endl;
	delete element;
	stack.count--;

	return true;
}

void Print(Stack& stack)
{
	Element* element = stack.top;
	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->pNext;
	}
}
