#include "LinkedList.h"
#include <iostream>

void LinkedList::UserInput(LinkedList& list)
{
	int type{ 0 };


	while (true)
	{
		LinkedList::Print(list);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> type;
		if (type == mCreate)
		{
			int value;
			std::cout << " Create value : ";
			std::cin >> value;
			Create(list, value);

		}
		else if (type == mDelete)
		{
			int value;
			std::cout << " Delete Value : ";
			std::cin >> value;
			Delete2(list, value);

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

void LinkedList::Create(LinkedList& list, int value)
{
	Element* element = new Element;
	element->mValue = value;
	list.mCount++;

	if (list.mpLast == nullptr)
	{
		list.mpFirst = list.mpLast = element;
	}
	else
	{
		list.mpLast->mpNext = element;
		list.mpLast = element;
	}

	std::cout << "Push : " << value << std::endl;
}

bool LinkedList::Delete(LinkedList& list)
{
	return false;
}

bool LinkedList::Delete2(LinkedList& list, int value)
{
	Element* element = list.mpFirst;
	Element* previous{};

	while (element != nullptr)
	{
		if (element->mValue == value)
		{
			break;
		}
		previous = element;
		element = element->mpNext;
	}

	if (element == nullptr)
	{
		return false;
	}

	if (list.mpFirst == element)
	{
		list.mpFirst = element->mpNext;
	}
	else if (list.mpLast == element)
	{
		list.mpLast = previous;
		previous->mpNext = nullptr;
	}
	else
	{
		previous->mpNext = element->mpNext;
	}
	if (list.mpFirst == element && list.mpFirst == list.mpLast)
	{
		list.mpFirst = list.mpLast = nullptr;
	}
	std::cout << "Delete : " << value << std::endl;
	delete element;
	return true;
}

void LinkedList::Print(LinkedList& list)
{
	Element* element = list.mpFirst;
	while (element != nullptr)
	{
		std::cout << element->mValue << std::endl;
		element = element->mpNext;
	}
}
