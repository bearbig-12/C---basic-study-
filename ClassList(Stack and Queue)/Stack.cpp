#include "Stack.h"

void Stack::UserInput(LinkedList& list)
{
	int type{ 0 };

	while (1)
	{
		Stack::Print(list);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> type;

		if (type == mPUSH)
		{
			int value;
			std::cout << " Push value : ";
			std::cin >> value;
			Create(list, value);
		}
		else if (type == mPOP)
		{
			Delete(list);

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

void Stack::Create(LinkedList& list, int value)
{
	Element* element = new Element;
	element->mValue = value;
	list.mCount++;

	element->mpNext = list.mpLast;
	list.mpLast = element;

	std::cout << "Push : " << value << std::endl;
}

bool Stack::Delete(LinkedList& list)
{
	Element* element = list.mpLast;
	if (list.mCount == 0)
	{
		std::cout << "STACK IS EMPTY" << std::endl;
		return false;

	}
	list.mpLast = element->mpNext;
	element->mpNext = nullptr;
	std::cout << "Pop : " << element->mValue << std::endl;
	delete element;
	list.mCount--;

	return true;
}

void Stack::Print(LinkedList& list)
{
	Element* element = list.mpLast;
	while (element != nullptr)
	{
		std::cout << element->mValue << std::endl;
		element = element->mpNext;

	}
}


