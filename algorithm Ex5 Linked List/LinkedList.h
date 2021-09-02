#pragma once
#include <string>

struct Monster
{
	std::string name{ "" };	//empty string
	int Hp{ 0 };

	Monster* pNext{ nullptr };
};

struct LinkedList
{
	Monster* pHead{ nullptr };
	Monster* pTail{ nullptr };
};
Monster* CreateMonster(LinkedList& list, std::string name, int hp);
void PrintMonster(const LinkedList& list);
int MonsterCount(const LinkedList& list);
Monster* FindMonster(const LinkedList& list, std::string name);
void PrintAll(Monster* element);
void DeleteAll(LinkedList& list);