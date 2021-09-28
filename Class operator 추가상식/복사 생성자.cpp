#include <iostream>


class MyClass
{
	int mValue;
public:
	MyClass(int value) : mValue{ value } 
	{
		std::cout << "일반 생성자" << std::endl;
	}

	//복사 생성자 - default = 얕은 복사
	MyClass(const MyClass& from)
	{
		std::cout << " 복사 생성자 " << std::endl;
	}
};
class DogOwner
{
public:
	int age;
	int weight;
	int color;
	
};
class DogHouse
{
	DogOwner* Owner;

public:
	DogHouse()
	{
		Owner = new DogOwner();
	}

	DogHouse(const DogHouse& house)
	{
		// 얕은 복사(swallow copy) - default
		Owner = house.Owner;		// 복사된 인스턴스의 포인터가 예전 복사 되기전 인스턴트를 가르키게 되는 문제가 발생

		// 깊은 복사(deep copy)
		Owner = new DogOwner();
		Owner->age = house.Owner->age;
		Owner->weight = house.Owner->weight;
		Owner->color = house.Owner->color;

	}

};



DogHouse::DogHouse()
{
}

DogHouse::~DogHouse()
{
}

int main()
{
	MyClass c1 = 5; // 형변환을 통해 5를 클래스로 만듬
	MyClass c2(c1);	// 복사 초기화

	MyClass c3{ MyClass{1} }; // 이 경우는 일반 생성자만 호출된다.
}