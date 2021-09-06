#include <iostream>
#include "DoubleLinkedList.h"

Monster2* CreateMonster(DoubleLinkedList& list, std::string name, int hp)
{
	Monster2* element = new Monster2;

	element->name = name;
	element->Hp = hp;
	if (list.pTail == nullptr)
	{
		list.pHead = element;
		list.pTail = element;
	}
	else
	{
		element->pPre = list.pTail; // 전 원소의 값은 pTail이 가리키고 있기 때문에 새element의 pre는 pTail.
		list.pTail->pNext = element;	// 전element의 pNext는 New Element가 되어야 하기 때문에 pNext = element
		list.pTail = element; // 전element 뒤에 새 원소를 하나더 추가 하였으므로, pTail을 새element로 옮겨줘야 함
	}
	return element;
}

void PrintMonster(const DoubleLinkedList& list)
{
	Monster2* element{ list.pHead };

	while (element != nullptr)
	{
		std::cout << element->name << " : " << element->Hp << std::endl;
		element = element->pNext;
	}
}

int MonsterCount(const DoubleLinkedList& list)
{
	Monster2* element{ list.pHead };
	int count{ 0 };
	while (element != nullptr)
	{
		count++;
		element = element->pNext;
	}
	return count;
}

Monster2* FindMonster(const DoubleLinkedList& list, std::string name)
{
	Monster2* element{ list.pHead };
	while (element != nullptr)
	{
		if (element->name == name)
		{
			return element;
		}
		element = element->pNext;
	}

	return nullptr;
}

void Print_Recursive(Monster2* element)
{
}

void DeleteAll(DoubleLinkedList& list)
{
	Monster2* element{ list.pHead };
	Monster2* Next;
	while (element != nullptr)
	{
		Next = element->pNext;
		delete element;

		element = Next;
	}
	list.pHead = list.pTail = nullptr;
}

bool Delete(DoubleLinkedList& list, std::string name)
{
	Monster2* element = FindMonster(list, name);
	if (element != nullptr)
	{
		// 1. pHead = pTail;
		// 2. pHead = element;
		// 3. pTail = element;
		// 4. else;
		if (list.pHead == element)
		{
			// 맨 첫원소 지우기
			list.pHead = element->pNext;
			if (element->pNext != nullptr)
			{
				element->pNext->pPre = nullptr;
			}
		}
		else
		{
			element->pPre->pNext = element->pNext;
		}
		if (list.pTail == element)
		{
			// 맨 뒤원소 지우기
			list.pTail = element->pPre;
			if (element->pPre != nullptr)
			{
				element->pPre->pNext = nullptr;
			}
		}
		else
		{
			element->pNext->pPre = element->pPre;
		}

	}
	delete element;
	return true;
}

void Print_Recursive2(const DoubleLinkedList& list, Monster2* element)
{
}

void Insert(DoubleLinkedList& list, std::string target, std::string name, int Hp)
{
}
