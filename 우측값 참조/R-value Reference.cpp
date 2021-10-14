#include <iostream>


template<typename T>
void Swap(T&& a, T&& B)	// 우측값 참조를 위한 &&
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<typename T>
void Swap1(T& a, T& B)	// 우측값 참조를 위한 std::move() 함수 즉 a의 소유권을 temp에 양도하는 용도 // 내부에서 일어나는 깊은 복사의 과정이 사라짐
{
	T temp;
	temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);

	//temp = a;
	// 1. temp 해제
	// 2. a의 복사 무명객체
	// 3. 무명객체의 이름이 temp

	// int temp = std::move(a);
	// 3
}
void funtionforRef(int&& a)
{

}
template<typename T>
void TemplateFunction(T&& A)
{
	funtionforRef(std::forward<T>(A));		// A가 x+x가 넘어가는게 아닌 2가 넘어가기 때문에 전달할때 의미 그대로 x+x를 넘겨줘야 하기에 
}

int main()
{
	int x{ 1 };
	//funtionforRef(x);
	funtionforRef(1);	// 우측값에 대한 참조가 불가능 해짐 (리터럴) void funtionforRef(int&& a) 이경우는 우측값 참조를 쓰기 때문에 가능
	funtionforRef(x + x);
	TemplateFunction(x + x);
}