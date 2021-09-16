#include <iostream>
struct Point2D
{
	int x;
	int y;
};
class Dog
{
private:
	int x;
};
class Cat
{
private:
	int mAge;
public:
	Cat() = default; // 암시적 생성자
	
	Cat(int value1 = 0)
	{
		mAge = value1;
	}
};
int main()
{
	std::cout << std::is_trivial<int>::value << std::is_pod<int>::value << std::endl;
	std::cout << std::is_trivial<Point2D>::value << std::is_pod<Point2D>::value << std::endl;
	std::cout << std::is_trivial<Dog>::value << std::is_pod<Dog>::value << std::endl;
	std::cout << std::is_trivial<Cat>::value << std::is_pod<Cat>::value << std::endl;

}
