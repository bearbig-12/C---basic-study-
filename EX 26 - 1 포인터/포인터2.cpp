#include <iostream>
// 배열과 함수의 이름은 코드의 첫번째 주소를 가르키는 용도로 쓰인다. (배열은 첫번째 인덱스)
// 변수와 함수는 친척관계

// 함수 포인터
// int Sigma(int (*f)(int x), int m, int n)	함수를 가르키는 포인터
// 
// 선언
// 타입 (*이름)(매개변수);
// int (*funcPtr)(float);
//
// 대입
// funcPtr = MyFunction;
//
// 역참조 ( 호출 )
// (*funcPtr)(1.0f)




int sum(int x, int y)
{
	return x + y;
}

int NormalFun(int x)
{
	return x;
}

int SquareFunction(int x)
{
	return x * x;
}

int Sigma(int (*f)(int x), int m, int n)
{
	int sum{};
	for (int k = m; k <= n; ++k)
	{
		sum += f(k);
	}
	return sum;
}

int MyFunctiom(float f)
{
	return 0;
}

//typedef int (*FunctionPtr)(float); // C 스타일
using FunctionPtr = int (*)(float); // C++ 스타일

int main()
{
	/*int x{ 1 }, y{ 2 };

	std::cout << &x << " , " << &y << std::endl;
	std::cout << &sum << " , " << &main << std::endl;
	std::cout << sum << " , " << main << std::endl;

	std::cout << sum(x, y) << std::endl;*/

	/*int array[10];	
	std::cout << &array << " , " << array << std::endl;*/

	//std::cout << Sigma(SquareFunction, 1, 10) << std::endl;

	

	//int (*pFunc)(float);
	FunctionPtr pFunc;

	pFunc = MyFunctiom;	// 포인터에 대입(Reference)

	(*pFunc)(1.0f);		// 함수 포인터의 역참조 호출 (Dereference)
	// = pFunc(1.0f);

}