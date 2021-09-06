#pragma once

struct Monster2
{
	std::string name{ "" };
	int Hp{ 0 };

	Monster2* pNext{ nullptr };
	Monster2* pPre { nullptr };
};

struct DoubleLinkedList
{
	Monster2* pHead{ nullptr };
	Monster2* pTail{ nullptr };
};

Monster2* CreateMonster(DoubleLinkedList& list, std::string name, int hp);
void PrintMonster(const DoubleLinkedList& list);
int MonsterCount(const DoubleLinkedList& list);
Monster2* FindMonster(const DoubleLinkedList& list, std::string name);
void Print_Recursive(Monster2* element);
void DeleteAll(DoubleLinkedList& list);
bool Delete(DoubleLinkedList& list, std::string name);
void Print_Recursive2(const DoubleLinkedList& list, Monster2* element);
void Insert(DoubleLinkedList& list, std::string target, std::string name, int Hp);