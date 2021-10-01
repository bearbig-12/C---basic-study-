#include "Dog.h"
#include <iostream>

void Dog::Roll()
{
	std::cout << "Rolling " << std::endl;
}

Dog::BREED Dog::GetBreed() const	// BREED�� DOGŬ������ �� �ֱ� ������ ���踦 ��Ȯ�ϰ� ǥ���������
{
	return mBreed;
}

void Dog::SetBreed(BREED breed)
{
	mBreed = breed;
}

void Dog::Sound()
{
	
	Animal::Sound();
	std::cout << "Woof  Woof ... " << std::endl;
}

Animal* Dog::Clone()
{
	return new Dog(*this);
}

Dog::Dog() : mBreed{HUSKEY} // Dog::BREED::HUSKEY �� ����
{
}

Dog::Dog(BREED breed, int age, int weight) : 
	Animal(age, weight), 
	mBreed{breed}
{
}

Dog::~Dog()
{
}
