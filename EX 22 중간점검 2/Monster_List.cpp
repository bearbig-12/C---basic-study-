#include <iostream>
//#include "Monster_List.h"

enum Type
{
	Wolf,
	Demon,
	Slime
};

struct Monster_Data
{

	//std::string type;
	Type type;
	std::string name;
	int HP{ 0 };
};

//std::string Monster(std::string str)
//{
//	std::string Monster_Type;
//	if (str == "Wolf")
//	{
//		str = "Wolf";
//	}
//	else if (str == "Demon")
//	{
//		str = "Demon";
//	}
//	else if (str == "Slime")
//	{
//		str = "Slime";
//	}
//	return str;
//}

std::string Monster(Type type)
{
	std::string Monster_Type;
	switch (type)
	{
	case Wolf:
		Monster_Type = "Wolf";
		break;
	case Demon:
		Monster_Type = "Demon";
		break;
	case Slime:
		Monster_Type = "Slime";
		break;
	default:
		Monster_Type = "Not Invaild Type!! Please type again ";
		break;
	}
	return Monster_Type;
}

void Print(Monster_Data data)
{
	
	std::cout << "Type : " << Monster(data.type);
	std::cout << " Name : " << data.name;
	std::cout << " HP : " << data.HP << std::endl;
}
int main()
{
	Monster_Data wolf{ Wolf, "황천늑대", 10 };
	Monster_Data demon{ Demon, "써큐버스", 30 };

	Print(wolf);
	Print(demon);
}