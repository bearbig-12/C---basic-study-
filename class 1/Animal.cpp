#include "Animal.h"
#include <iostream>
void Animal::Sound()
{
	std::cout << "Make some noise" << std::endl;
}

int Animal::GetAge() const
{
	return mAge;
}

void Animal::SetAge(int age)
{
	mAge = age;
}

int Animal::GetWeight() const
{
	return mWeight;
}

void Animal::SetWeight(int weight)
{
	mWeight = weight;
}

Animal* Animal::Clone()
{
	return new Animal(*this);
}

Animal::Animal(int age, int weight)
{
	mAge = age;
	mWeight = weight;
}
