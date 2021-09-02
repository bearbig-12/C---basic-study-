#include <iostream>
#include <string>
#include "LinkedList.h"




int main()
{
	LinkedList myList;

	CreateMonster(myList, "Wolf", 10);
	CreateMonster(myList, "Slime", 20);
	CreateMonster(myList, "Demon", 100);
	PrintAll(myList.pHead);
	DeleteAll(myList);
	PrintAll(myList.pHead);
	//PrintMonster(myList);
	//std::cout << "Count : " << MonsterCount(myList) << std::endl;

	//FindMonster(myList, "Slime");

	/*if (FindMonster(myList, "Slime") != nullptr)
	{
		std::cout << "Found" << std::endl;
	}*/
}