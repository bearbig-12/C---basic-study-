#include <iostream>
#include <functional>

//함수
void MyFunction(int age1){}

void MyFunction2(int arg1, char arg2)
{
	std::cout << arg1 << " " << arg2 << std::endl;
}

// 객체 - 함수 연산자 () 오버로딩
class MyClass
{
public:
	void operator()() {};
};

int main()
{
	//std::function<void(int)> functor1 = MyFunction;
	//std::function<void()> functor2 = MyClass();
	//std::function<void()> functor3 = []() {};

	auto functor1 = std::bind(MyFunction2, std::placeholders::_1, std::placeholders::_2);
	functor1(1, 'a');

	auto functor2 = std::bind(MyFunction2, std::placeholders::_2, std::placeholders::_1);
	functor2('a', 1);

	auto functor3 = std::bind(MyFunction2, 10, std::placeholders::_1);
	functor3('a');

}