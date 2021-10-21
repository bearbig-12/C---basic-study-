#include <iostream>
#include "Monster.h"
#include <vector>

// 파일헤더 - POD
struct Header
{
	int verstion{ 1 };
	int itemCount{};
};

int main()
{
	std::vector<Monster> monsters
	{
		{"JELLY", 1, 1, 1},
		{"WOLF", 5, 5, 5},
		{"DEMON", 10,10,10},
	};

	SaveToFile("D:\\Git hub\\SimpleData\\Data.txt", monsters);
}