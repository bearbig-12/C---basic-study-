#include <iostream>

class MyIDGenerator
{
private:
	static int sID;
public:
	static int GetID()
	{
		return sID++;
	}
};

int MyIDGenerator::sID{ 1 };

int main()
{
	std::cout << MyIDGenerator::GetID() << std::endl;
	std::cout << MyIDGenerator::GetID() << std::endl;
	std::cout << MyIDGenerator::GetID() << std::endl;
	std::cout << MyIDGenerator::GetID() << std::endl;
	std::cout << MyIDGenerator::GetID() << std::endl;
}