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
	std::cout << "\t����� ���� �ֵѷ���!" << std::endl;
}

void Warrior::DoubleSwing() const
{
	std::cout << "\t����� ���� �ι� �ֵѷ���!" << std::endl;

}

void Warrior::Move() const
{
	//Character::Move();	// ���������Լ��� ���Ǵ� ����
	std::cout << "\t ����� ������ ��������!" << std::endl;
}
