#include <iostream>
#include "Monster.h"
#include <vector>

// 파일헤더 - POD
struct Header		// 데이터를 통째로 보낼 수 있다.
{
	int verstion{ 1 };
	int itemCount{};
};

using Monsters = std::vector<Monster>;

bool SaveToFile(const char* filename, Monsters& monsters)
{
	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);

	try
	{
		ofs.open(filename, std::ofstream::binary);

		Header header{ 1, monsters.size() };
		ofs.write(reinterpret_cast<char*>(&header), sizeof(Header));		// 구조체를 통째로 바이너리 형태로 저장 할수있다.
		for (auto e : monsters)
		{
			ofs << e;
		}
		ofs.close();

	}
	catch (std::exception e)
	{
		std::cout << "파일 저장 중에 에러가 발생했습니다!!!" << std::endl;
		std::cout << e.what() << std::endl;


		ofs.close();
		return false;
	}
	return true;
}

bool LoadFromFile(const char* filename, Monsters& monsters)
{
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		ifs.open(filename, std::ifstream::binary);
		// 헤더
		Header header;
		ifs.read(reinterpret_cast<char*>(&header), sizeof(Header));

		for (int i = 0; i < header.itemCount; ++i)
		{
			Monster monster;
			ifs >> monster;
			monsters.push_back(monster);

		}
		ifs.close();

	}
	catch (std::exception e)
	{
		std::cout << "파일을 불러오는 중 문제가 발생!!" << std::endl;
		std::cout << e.what() << std::endl;

		ifs.close();
		return false;
	}
	return true;

}

int main()
{
	Monsters monsters
	{
		{"JELLY", 1, 1, 1},
		{"WOLF", 5, 5, 5},
		{"DEMON", 10,10,10},
	};

	SaveToFile("D:\\Git hub\\SimpleData\\Data.txt", monsters);

	monsters.clear();

	LoadFromFile("D:\\Git hub\\SimpleData\\Data.txt", monsters);

}