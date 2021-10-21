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

		std::getline(is, buffer);	// 끝이니까 쉼표 까지 읽는게 아닌 한줄을 읽으면 된다.
		monster.mMP = std::stoi(buffer);
		std::cout << buffer << std::endl;

	}
	catch (std::exception e)
	{
		std::cout << "데이터 형식이 잘못되었습니다 !" << std::endl;
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
		std::cout << " 스트림에 저장할 때 오류가 발생했습니다" << std::endl;

	}
	return os;
}


bool LoadFile(const char* filename, std::vector<Monster>& vector)
{

	//1. 파일 스트림 객체(입력)
	//2. 작업 (데이터 꺼내오기)
	//3. 객체 제거 (파일 닫기)
	
	//std::ifstream ifs(filename);
	std::ifstream ifs;
	ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);	// badbit라는 플래그가 켜지면 예외가 발생한다.

	try
	{
		ifs.open(filename);
		std::string buffer;
		std::getline(ifs, buffer);	// sstream 헤더 파일 필요 , 한줄 읽어 오기

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
		std::cout << e.what() << std::endl;		// 어떤 에러가 발생했는지 메시지로 보여줌

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
		std::cout << " 파일 저장 도중 오류가 발생했습니다." << std::endl;
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
	//UNIX 표기
	LoadFile("D:\\Git hub\\SimpleData\\Data.txt", monsters); // \는 단독으로 못쓴다. 따라서 2개

	for (auto& e : monsters)
	{
		e.Print();
	}

	monsters.push_back({"ORC",20,20,20});

	SaveFile("D:\\Git hub\\SimpleData\\Data.txt", monsters);
}