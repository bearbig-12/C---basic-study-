#pragma once
class Animal
{
protected:
	int mAge;
	int mWeight;
public:
	virtual void Sound();

public:
	// getter setter
	int GetAge() const;
	void SetAge(int age);

	int GetWeight() const;
	void SetWeight(int weight);

	virtual Animal* Clone();	// ���� ������ ���� ���� �����ڸ� ��� �Ҽ� ���� ������ �Լ��� ������ش�.
public:
	Animal() = default;
	
	Animal(int age, int weight);
	virtual ~Animal()	// (�߿�) ��ӹ޴� Ŭ������ �ִٸ� Base Ŭ������ �Ҹ��ڴ� �� ���� �Ҹ��ڷ�
	{

	}



};

