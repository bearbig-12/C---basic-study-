#include <iostream>


class MyFunction
{
public:
	static int NormalFunction(int x)	// 인스턴스가 아닌 클래스의 함수에 접근하기 위해서 static을 붙인다
	{
		return x;
	}
	int SquareFunction(int x)
	{
		return x * x;
	}
};

using FunctionPtr = int (*)(int);


int Sigma(FunctionPtr f, int m, int n)
{
	int sum{};
	for (int k = m; k <= n; ++k)
	{
		sum += f(k);
	}
	return sum;
}

using FunctionPtr2 = int (MyFunction::*)(int);

int Sigma2(MyFunction& instance, FunctionPtr2 f, int m, int n)
{
	int sum{};
	for (int k = m; k <= n; ++k)
	{
		sum += (instance.*f)(k);
	}
	return sum;
}

int main()
{
	MyFunction mf;

	std::cout << Sigma(&MyFunction::NormalFunction, 1, 10) << std::endl;
	std::cout << Sigma2(mf, &MyFunction::SquareFunction, 1, 10) << std::endl;

}

