#include <iostream>
#include <initializer_list>
void function(std::initializer_list<int>)
{

}
void f()
{

}

int main()
{
	//function({ 1,2,3 });

	//for (auto e : { 1,2,3,4,5 })	// array로 인식
	//{

	//}


	//int x;

	//auto expr = [](int a, int b)			//[] 캡처절 해당 블록에 있는 변수를 캡처해줌, 외부 변수 사용 불가 // [=] : Call by Value // [&] : Call by Reference
	//{
	//
	//};

	//int a, b;
	//auto expr1 = [&](int x, int y)
	//{
	//	a = x;
	//	b = y;
	//};
	//[](int a) -> float
	//{
	//	return 1.0f;
	//};

	
}