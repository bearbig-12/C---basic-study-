#include "Warrior.h"
#include <iostream>

void Warrior::Attack()
{
	if (this->dmg < 20)
	{
		std::cout << "DMG : " << this->dmg << " ȿ���� �����ε� �ϴ�..." << std::endl;
	}
	else
	{
		std::cout << "DMG : " << this->dmg << " ȿ���� �����ߴ�!" << std::endl;
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
