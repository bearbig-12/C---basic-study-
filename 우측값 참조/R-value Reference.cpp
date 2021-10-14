#include <iostream>


template<typename T>
void Swap(T&& a, T&& B)	// ������ ������ ���� &&
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<typename T>
void Swap1(T& a, T& B)	// ������ ������ ���� std::move() �Լ� �� a�� �������� temp�� �絵�ϴ� �뵵 // ���ο��� �Ͼ�� ���� ������ ������ �����
{
	T temp;
	temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);

	//temp = a;
	// 1. temp ����
	// 2. a�� ���� ����ü
	// 3. ����ü�� �̸��� temp

	// int temp = std::move(a);
	// 3
}
void funtionforRef(int&& a)
{

}
template<typename T>
void TemplateFunction(T&& A)
{
	funtionforRef(std::forward<T>(A));		// A�� x+x�� �Ѿ�°� �ƴ� 2�� �Ѿ�� ������ �����Ҷ� �ǹ� �״�� x+x�� �Ѱ���� �ϱ⿡ 
}

int main()
{
	int x{ 1 };
	//funtionforRef(x);
	funtionforRef(1);	// �������� ���� ������ �Ұ��� ���� (���ͷ�) void funtionforRef(int&& a) �̰��� ������ ������ ���� ������ ����
	funtionforRef(x + x);
	TemplateFunction(x + x);
}