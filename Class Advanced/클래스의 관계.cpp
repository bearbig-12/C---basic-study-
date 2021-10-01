

//  A is part of B	(강한 연결 관계 - 멤버 변수 사용)
//		A는 B의 일부 구성요소
//		A는 한번에 하나의 객체에만 존재
//		A는 B에 의해 관리 (케릭터가 없어지면 스테이터스도 없어진다.)
//		A는 B의 존재를 몰라도 됨

class Status 
{
	int hp;
	int mp;
};
class Character	
{
	Status mStatus;
};

//	A has a B  (약한 연결 관계 - 포인터)
//		B는 A의 구성요소
//		B는 한번에 여러 오브젝트에 소속
//		B는 A에 의해 관리되지 않음 (옥션이 없어서도 플레이어는 없어지지 않음)
//		B는 A의 존재를 몰라도 됨

class Player 
{
};

class Auction 
{
	Player* mPlayers;
};


//	A use a B
//		B는 A와 관련이 없음
//		B는 한번에 여러 오브젝트에 소속
//		B는 A에 의해 관리되지 않음
//		B는 A의 존재를 모를수도 있고 알 수도 있다.

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
//		특수화 객체 -> 일반적인 개념
//		일반화, 특수화
//		상속(Inheritance), 파생(derivation)

//		상위개념(동물) - Base class , 하위개념(개) - Derived class

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

// 일반화 
// mAge, mWeight

//	A is a B
//		개는 동물의 일종이다.
//		아이스크림은 음식의 일종이다.
//		개와 아이스크림은 다르다.

//		상위개념(동물) - Base class , 하위개념(개) - Derived class

//				파생(Derivation)				상속(Inheritance)			????
//	일반화			base class						Parent class			super class
//	특수화			Derived class					Child class				sub class

class 파생클래스 : [virtual] [접근제한자] 기반클래스, 기반클래스2

class Animal
{
private:
	int mAge;		// 클래스 내부
public:
	int mWeight;	// 클래스 내부, 외부, 파생
protected:
	int mValue;		// 클래스 내부, 파생

};

class Dog : Animal // Dog = child, Animal = parent
{
	// Animal 에서 파생 되었기 때문에 mAge와 mWeight를 가지고 있다
public:
	void Bark();
};

class Cat : Animal
{
	// 냥쉑도 마찬가지
public:
	void Meow();
};