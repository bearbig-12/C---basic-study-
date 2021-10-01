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

	virtual Animal* Clone();	// 복사 생성자 사용시 가상 생성자를 사용 할수 없기 때문에 함수로 만들어준다.
public:
	Animal() = default;
	
	Animal(int age, int weight);
	virtual ~Animal()	// (중요) 상속받는 클래스가 있다면 Base 클래스의 소멸자는 꼭 가상 소멸자로
	{

	}



};

