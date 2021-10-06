#include <iostream>


template<typename T>

T Function(T arg1, T arg2)
{
	T result = arg1 + arg2;
	return result;
}
class Dog
{
public:
	Dog operator+(Dog& d)
	{
		return Dog();
	}
};

//int main()
//{
//	std::cout << Function(1, 4) << std::endl;
//	std::cout << Function(1.5f, 3.7f) << std::endl;
//
//	Dog d1, d2;
//	Function(d1, d2);
//}