#include <iostream>
#include <string>
#include "LinkedList.h"

Monster* CreateMonster(LinkedList& list, std::string name, int hp)
{
	Monster* element = new Monster;

	element->name = name;
	element->Hp = hp;
	if (list.pTail == nullptr)
	{
		list.pHead = element;
		list.pTail = element;
	}
	else
	{
		list.pTail->pNext = element;
		list.pTail = element;
	}
	return element;
}

void PrintMonster(const LinkedList& list)
{
	Monster* element{ list.pHead };

	//Traverse 순환의 기본형
	while (element != nullptr)
	{
		std::cout << element->name << " : " << element->Hp << std::endl;
		element = element->pNext;
	}
}

int MonsterCount(const LinkedList& list)
{
	int count{ 0 };
	Monster* element{ list.pHead };
	while (element != nullptr)
	{
		count++;
		element = element->pNext;
	}
	return count;
}

Monster* FindMonster(const LinkedList& list, std::string name)
{
	Monster* element{ list.pHead };
	while (element != nullptr)
	{
		if (element->name == name)
		{
			std::cout << "Found : " << element->name << " : " << element->Hp << std::endl;
			return element;
		}
		else
		{
			std::cout << " 404 Not Found " << std::endl;
			return nullptr;
		}
	}
	//std::cout << " 404 Not Found " << std::endl;
	
	return nullptr;
}

void PrintAll(Monster* element)
{
	if (element == nullptr)
	{
		std::cout << "It's Empty" << std::endl;
		return;
	}
	std::cout << element->name << " : " << element->Hp << std::endl;
	PrintAll(element->pNext);
}

void DeleteAll(LinkedList& list)
{
	Monster* element{ list.pHead };
	Monster* Next{};

	while (element != nullptr);
	{
		Next = element->pNext;
		delete element;

		element = Next;
	}
	list.pHead = nullptr;
	list.pTail = nullptr;
}
