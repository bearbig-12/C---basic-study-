#include <iostream>
// �迭�� �Լ��� �̸��� �ڵ��� ù��° �ּҸ� ����Ű�� �뵵�� ���δ�. (�迭�� ù��° �ε���)
// ������ �Լ��� ģô����

// �Լ� ������
// int Sigma(int (*f)(int x), int m, int n)	�Լ��� ����Ű�� ������
// 
// ����
// Ÿ�� (*�̸�)(�Ű�����);
// int (*funcPtr)(float);
//
// ����
// funcPtr = MyFunction;
//
// ������ ( ȣ�� )
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

//typedef int (*FunctionPtr)(float); // C ��Ÿ��
using FunctionPtr = int (*)(float); // C++ ��Ÿ��

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

	pFunc = MyFunctiom;	// �����Ϳ� ����(Reference)

	(*pFunc)(1.0f);		// �Լ� �������� ������ ȣ�� (Dereference)
	// = pFunc(1.0f);

}