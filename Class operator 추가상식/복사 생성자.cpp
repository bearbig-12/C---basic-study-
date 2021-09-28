#include <iostream>


class MyClass
{
	int mValue;
public:
	MyClass(int value) : mValue{ value } 
	{
		std::cout << "�Ϲ� ������" << std::endl;
	}

	//���� ������ - default = ���� ����
	MyClass(const MyClass& from)
	{
		std::cout << " ���� ������ " << std::endl;
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
		// ���� ����(swallow copy) - default
		Owner = house.Owner;		// ����� �ν��Ͻ��� �����Ͱ� ���� ���� �Ǳ��� �ν���Ʈ�� ����Ű�� �Ǵ� ������ �߻�

		// ���� ����(deep copy)
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
	MyClass c1 = 5; // ����ȯ�� ���� 5�� Ŭ������ ����
	MyClass c2(c1);	// ���� �ʱ�ȭ

	MyClass c3{ MyClass{1} }; // �� ���� �Ϲ� �����ڸ� ȣ��ȴ�.
}