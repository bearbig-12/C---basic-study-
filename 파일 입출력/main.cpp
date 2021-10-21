#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Monster
{
private:
	std::string mName;
	int mLevel;
	int mHP;
	int mMP;
public:
	Monster()
	{

	}
	Monster(std::string name, int level, int hp, int mp)
		: mLevel{ level }, mName{ name }, mHP{ hp }, mMP{ mp }
	{

	}
	

	void SetName(std::string name)
	{
		mName = name;
	}
	void SetLevel(int level)
	{
		mLevel = level;
	}
	void SetHP(int hp)
	{
		mHP = hp;
	}
	void SetMP(int mp)
	{
		mMP = mp;
	}
	void Print()
	{
		std::cout << mName << ", " << mLevel << ", " << mHP << ", " << mMP << std::endl;
	}
	friend std::istream& operator >> (std::istream& is, Monster& monster);
	friend std::ostream& operator <<(std::ostream& os, Monster& monster);
};

std::istream& operator >> (std::istream& is, Monster& monster)
{
	std::string buffer;
	try 
	{
		std::getline(is, buffer, ',');
		monster.mName = buffer;
		std::cout << buffer << std::endl;

		std::getline(is, buffer, ',');
		monster.mLevel = std::stoi(buffer);
		std::cout << buffer << std::endl;

		std::getline(is, buffer, ',');
		monster.mHP = std::stoi(buffer);
		std::cout << buffer << std::endl;

		std::getline(is, buffer);	// ���̴ϱ� ��ǥ ���� �д°� �ƴ� ������ ������ �ȴ�.
		monster.mMP = std::stoi(buffer);
		std::cout << buffer << std::endl;

	}
	catch (std::exception e)
	{
		std::cout << "������ ������ �߸��Ǿ����ϴ� !" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	return is;
}

std::ostream& operator <<(std::ostream& os, Monster& monster)
{
	try
	{
		os << monster.mName << "," <<
			monster.mLevel << "," <<
			monster.mHP << "," <<
			monster.mMP << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << " ��Ʈ���� ������ �� ������ �߻��߽��ϴ�" << std::endl;

	}
	return os;
}


bool LoadFile(const char* filename, std::vector<Monster>& vector)
{

	//1. ���� ��Ʈ�� ��ü(�Է�)
	//2. �۾� (������ ��������)
	//3. ��ü ���� (���� �ݱ�)
	
	//std::ifstream ifs(filename);
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);	// badbit��� �÷��װ� ������ ���ܰ� �߻��Ѵ�.

	try
	{
		ifs.open(filename);
		std::string buffer;
		std::getline(ifs, buffer);	// sstream ��� ���� �ʿ� , ���� �о� ����

		while (!ifs.eof())
		{
			Monster mon;
			ifs >> mon;
			vector.push_back(mon);
		}
		//std::cout << buffer << std::endl;
		
		ifs.close();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;		// � ������ �߻��ߴ��� �޽����� ������

		ifs.close();
		return false;
	}
	
	return true;

}

bool SaveFile(const char* filename, std::vector<Monster> monsters)
{
	std::ofstream ofs;
	ofs.exceptions(std::ofstream::badbit);

	try
	{
		ofs.open(filename);

		ofs << "--Monster data--" << std::endl;
		for (auto& e : monsters)
		{
			ofs << e;
		}
		ofs.close();
	}
	catch (std::exception e)
	{
		std::cout << " ���� ���� ���� ������ �߻��߽��ϴ�." << std::endl;
		std::cout << e.what() << std::endl;
		ofs.close();
		return false;
	}


	return true;
}

int main()
{
	int x{ 1 };
	std::vector<Monster> monsters;
	//UNIX ǥ��
	LoadFile("D:\\Git hub\\SimpleData\\Data.txt", monsters); // \�� �ܵ����� ������. ���� 2��

	for (auto& e : monsters)
	{
		e.Print();
	}

	monsters.push_back({"ORC",20,20,20});

	SaveFile("D:\\Git hub\\SimpleData\\Data.txt", monsters);
}