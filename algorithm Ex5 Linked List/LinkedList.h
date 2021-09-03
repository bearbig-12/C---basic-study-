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
void Print_Recursive(Monster* element);
void DeleteAll(LinkedList& list);
bool Delete(LinkedList& list, std::string name);
void Print_Recursive2(const LinkedList& list, Monster* element);
void Insert(LinkedList& list, std::string target , std::string name, int Hp);