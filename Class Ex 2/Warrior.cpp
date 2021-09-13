#include "Warrior.h"
#include <iostream>

void Warrior::Attack()
{
	if (this->dmg < 20)
	{
		std::cout << "DMG : " << this->dmg << " 효과가 별로인듯 하다..." << std::endl;
	}
	else
	{
		std::cout << "DMG : " << this->dmg << " 효과가 굉장했다!" << std::endl;
	}

}

void Warrior::SetStatus(int hp, int dmg)
{
	this->hp = hp;
	this->dmg = dmg;
}

int Warrior::SetValue() const
{
	return this->value;
}
