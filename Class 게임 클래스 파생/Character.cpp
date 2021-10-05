#include "Character.h"
#include <iostream>
Character::Character() : mHp{0}
{
	std::cout << "+[Character]" << std::endl;
}

Character::~Character()
{
	std::cout << "-[Character]" << std::endl;

}

void Character::Attack() const
{
	std::cout << "\tBasic Attack" << std::endl;
}

void Character::Move() const
{
	std::cout << "\tBasic Move" << std::endl;
}
