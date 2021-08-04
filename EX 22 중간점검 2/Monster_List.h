#pragma once
#include <iostream>
#include <string>

struct Monster_Data
{
	std::string type;
	std::string name;
	int HP{ 0 };
};

std::string Monster(std::string str)
{
	std::string Monster_Type;
	if (str == "Wolf")
	{
		str = "Wolf";
	}
	else if (str == "Demon")
	{
		str = "Demon";
	}
	else if (str == "Slime")
	{
		str = "Slime";
	}
	return str;
}

void Print(Monster_Data data)
{
	Monster_Data Data;
	std::cout << "Type : " << Monster(Data.type);
	std::cout << " Name : " << Data.name;
	std::cout << " HP : " << Data.HP << std::endl;
}


