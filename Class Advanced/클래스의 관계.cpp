

//  A is part of B	(���� ���� ���� - ��� ���� ���)
//		A�� B�� �Ϻ� �������
//		A�� �ѹ��� �ϳ��� ��ü���� ����
//		A�� B�� ���� ���� (�ɸ��Ͱ� �������� �������ͽ��� ��������.)
//		A�� B�� ���縦 ���� ��

class Status 
{
	int hp;
	int mp;
};
class Character	
{
	Status mStatus;
};

//	A has a B  (���� ���� ���� - ������)
//		B�� A�� �������
//		B�� �ѹ��� ���� ������Ʈ�� �Ҽ�
//		B�� A�� ���� �������� ���� (������ ����� �÷��̾�� �������� ����)
//		B�� A�� ���縦 ���� ��

class Player 
{
};

class Auction 
{
	Player* mPlayers;
};


//	A use a B
//		B�� A�� ������ ����
//		B�� �ѹ��� ���� ������Ʈ�� �Ҽ�
//		B�� A�� ���� �������� ����
//		B�� A�� ���縦 �𸦼��� �ְ� �� ���� �ִ�.

class Potion
{
	int mCount;
	int mRecovery;
};

class Player
{
	Potion* pPotion;
};

//	A is a B
//		Ư��ȭ ��ü -> �Ϲ����� ����
//		�Ϲ�ȭ, Ư��ȭ
//		���(Inheritance), �Ļ�(derivation)

//		��������(����) - Base class , ��������(��) - Derived class

class Dog
{
private:
	int mAge;
public:
	int mWeight;
public:
	void Bark();
};

class Cat
{
private:
	int mAge;
public:
	int mWeight;
public:
	void Meow();
};

// �Ϲ�ȭ 
// mAge, mWeight

//	A is a B
//		���� ������ �����̴�.
//		���̽�ũ���� ������ �����̴�.
//		���� ���̽�ũ���� �ٸ���.

//		��������(����) - Base class , ��������(��) - Derived class

//				�Ļ�(Derivation)				���(Inheritance)			????
//	�Ϲ�ȭ			base class						Parent class			super class
//	Ư��ȭ			Derived class					Child class				sub class

class �Ļ�Ŭ���� : [virtual] [����������] ���Ŭ����, ���Ŭ����2

class Animal
{
private:
	int mAge;		// Ŭ���� ����
public:
	int mWeight;	// Ŭ���� ����, �ܺ�, �Ļ�
protected:
	int mValue;		// Ŭ���� ����, �Ļ�

};

class Dog : Animal // Dog = child, Animal = parent
{
	// Animal ���� �Ļ� �Ǿ��� ������ mAge�� mWeight�� ������ �ִ�
public:
	void Bark();
};

class Cat : Animal
{
	// �ɽ��� ��������
public:
	void Meow();
};