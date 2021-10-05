#include "Warrior.h"
#include <iostream>
Warrior::Warrior()
{
	std::cout << "+[Warrior]" << std::endl;
}

Warrior::~Warrior()
{
	std::cout << "-[Warrior]" << std::endl;
}

void Warrior::Attack() const
{
	//Character::Attack();
	std::cout << "\t전사는 검을 휘둘렀다!" << std::endl;
}

void Warrior::DoubleSwing() const
{
	std::cout << "\t전사는 검을 두번 휘둘렀다!" << std::endl;

}

void Warrior::Move() const
{
	//Character::Move();	// 순수가상함수라도 정의는 가능
	std::cout << "\t 전사는 앞으로 움직였다!" << std::endl;
}
