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

void Print_Recursive(Monster* element)	// 매겨번수로 list.pHead를 받아서 처음부터 끝까지.
{
	LinkedList list;
	if (element == nullptr)
	{
		return;
	}
	std::cout << element->name << " : " << element->Hp << std::endl;
	Print_Recursive(element->pNext);
}

void DeleteAll(LinkedList& list)
{
	Monster* element{ list.pHead };
	
	while (element != nullptr);
	{
		Monster* Next = element->pNext;
		delete element;

		element = Next;
	}
	list.pHead = nullptr;
	list.pTail = nullptr;
}

bool Delete(LinkedList& list, std::string name)
{
	Monster* element = list.pHead;
	Monster* previous = nullptr;	// 전 element를 담을 변수

	while (element != nullptr)
	{
		if (element->name == name)
		{
			break;
		}

		previous = element;
		element = element->pNext;

	}
	if (element == nullptr)	// 마지막까지 가서 못찾음
	{
		return false;
	}
	if (list.pHead == element) // previous == nullptr
	{
		//head
		list.pHead = element->pNext;
		
	}
	else if (list.pTail == element)	//element->pNext == nullptr
	{
		//tail
		list.pTail = previous;
		previous->pNext = nullptr;
	}
	else
	{
		//middle
		previous->pNext = element->pNext;
	}
	if (list.pHead == element && list.pHead == list.pTail)
	{
		list.pHead = list.pTail = nullptr;
	}
	delete element;
	return false;
}

void Print_Recursive2(const LinkedList& list, Monster* element)
{

	if (list.pTail == element)
	{
		std::cout << element->name << " : " << element->Hp << std::endl;
		return;
	}
	std::cout << element->name << " : " << element->Hp << std::endl;
	Print_Recursive2(list, element->pNext);
}

void Insert(LinkedList& list, std::string target, std::string name, int Hp)
{
	Monster* element{ list.pHead };
	Monster* previous{nullptr};
	
	while (element != nullptr)
	{
		if (element->name == target)
		{
			break;
		}
		previous = element;
		element = element->pNext;
	}

	Monster* New_Monster = new Monster;
	New_Monster->name = name;
	New_Monster->Hp = Hp;
	New_Monster->pNext = nullptr;

	if (previous == nullptr)
	{
		//head 전
		previous = New_Monster;
		list.pHead = previous;

		New_Monster->pNext = element;
	}
	else
	{
		//중간
		previous->pNext = New_Monster;
		New_Monster->pNext = element;
	}

}
