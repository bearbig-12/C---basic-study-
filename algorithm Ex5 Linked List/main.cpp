#include <iostream>
#include <string>
#include "LinkedList.h"




int main()
{
	LinkedList myList;

	CreateMonster(myList, "Wolf", 10);
	CreateMonster(myList, "Slime", 20);
	CreateMonster(myList, "Demon", 100);
	
	Insert(myList, "Demon","Zombie", 200);

	Print_Recursive2(myList, myList.pHead);
	Delete(myList, "Slime");
	Print_Recursive2(myList, myList.pHead);
	

	//PrintMonster(myList);
	//std::cout << "Count : " << MonsterCount(myList) << std::endl;

	//FindMonster(myList, "Slime");

	/*if (FindMonster(myList, "Slime") != nullptr)
	{
		std::cout << "Found" << std::endl;
	}*/

	//DeleteAll(myList);
}