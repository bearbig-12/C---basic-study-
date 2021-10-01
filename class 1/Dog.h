#pragma once
#include "Animal.h"


class Dog : public Animal   
{
public:
	enum BREED
	{
		BEAGLGE, DOBERMAN, BERNARD,
		CHIHUAHUA, HUSKEY, RETRIEVER, SHINTZU
	};
	
private:
	BREED mBreed;

public:
	void Roll();
public:

	BREED GetBreed() const;
	void SetBreed(BREED breed);

	void Sound();

	Animal* Clone(); // base case���� Animal*�� �Ͽ��� ������
public:
	Dog();
	Dog(BREED breed, int age, int weight);
	~Dog();

};

