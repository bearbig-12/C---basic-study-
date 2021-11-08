#include <iostream>
#include "Monster.h"
#include <vector>

// ������� - POD
struct Header		// �����͸� ��°�� ���� �� �ִ�.
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
		ofs.write(reinterpret_cast<char*>(&header), sizeof(Header));		// ����ü�� ��°�� ���̳ʸ� ���·� ���� �Ҽ��ִ�.
		for (auto e : monsters)
		{
			ofs << e;
		}
		ofs.close();

	}
	catch (std::exception e)
	{
		std::cout << "���� ���� �߿� ������ �߻��߽��ϴ�!!!" << std::endl;
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
		// ���
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
		std::cout << "������ �ҷ����� �� ������ �߻�!!" << std::endl;
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