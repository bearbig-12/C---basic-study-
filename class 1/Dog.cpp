#include "Dog.h"
#include <iostream>

void Dog::Roll()
{
	std::cout << "Rolling " << std::endl;
}

Dog::BREED Dog::GetBreed() const	// BREED는 DOG클래스에 들어가 있기 떄문에 관계를 명확하게 표시해줘야함
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

Dog::Dog() : mBreed{HUSKEY} // Dog::BREED::HUSKEY 도 가능
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
