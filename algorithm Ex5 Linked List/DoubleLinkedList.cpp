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
		element->pPre = list.pTail; // �� ������ ���� pTail�� ����Ű�� �ֱ� ������ ��element�� pre�� pTail.
		list.pTail->pNext = element;	// ��element�� pNext�� New Element�� �Ǿ�� �ϱ� ������ pNext = element
		list.pTail = element; // ��element �ڿ� �� ���Ҹ� �ϳ��� �߰� �Ͽ����Ƿ�, pTail�� ��element�� �Ű���� ��
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
			// �� ù���� �����
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
			// �� �ڿ��� �����
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
