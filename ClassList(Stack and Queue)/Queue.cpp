
#include "Queue.h"

void Queue::UserInput(LinkedList& list)
{
	int type{ 0 };

	while (1)
	{
		Queue::Print(list);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> type;

		if (type == mENQUEUE)
		{
			int value;
			std::cout << " Push value : ";
			std::cin >> value;
			Create(list, value);
		}
		else if (type == mDEQUEUE)
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

void Queue::Create(LinkedList& list, int value)
{
	Element* element = new Element;
	element->mValue = value;
	element->mpNext = nullptr;
	if (list.mCount == 0)
	{
		list.mpFirst = list.mpLast = element;
	}
	else
	{
		list.mpLast->mpNext = element;
		list.mpLast = element;
	}
	list.mCount++;
}

bool Queue::Delete(LinkedList& list)
{
	if (list.mCount == 0)
	{
		std::cout << "Queue is Empty" << std::endl;
		return false;
	}
	Element* element = list.mpFirst;
	std::cout << "Dequeue : " << element->mValue << std::endl;

	list.mpFirst = element->mpNext;
	delete element;

	list.mCount--;
	if (list.mCount == 0)
	{
		list.mpFirst = list .mpLast = nullptr;
	}
	return true;
}

void Queue::Print(LinkedList& list)
{
	Element* element = list.mpFirst;

	while (element != nullptr)
	{
		std::cout << element->mValue << std::endl;
		element = element->mpNext;
	}
}
