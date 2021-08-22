#include <iostream>

struct Character
{
	int HP;
	int Damage;
	float Speed;
};


int main()
{

	Character* pPlayer = new Character;

	pPlayer->HP = 100;
	pPlayer->Damage = 10;
	pPlayer->Speed = 10.0f;

	std::cout << pPlayer->HP << std::endl;
	std::cout << pPlayer->Damage << std::endl;
	std::cout << pPlayer->Speed << std::endl;


	delete pPlayer;
	

}