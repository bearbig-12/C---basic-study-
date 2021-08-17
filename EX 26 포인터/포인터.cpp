#include <iostream>

// & ampersand  : 주소 연산자
//				: 우측 변수의 주소를 반환

// * star/ asterisk : 포인터 연산자
//					: 우측 변수가 주소를 가리키는 포인터 변수
//					: 역참조 연산자

// 포인터의 기본
// int* p; - 정수형 포인터 p를 선언
// p = &a; - 포인터의p에 b의 주소를 대입
// p 는 b를 참조한다(reference)

//*p = 3; p가 가리키고 있는 곳에 값을 대입 p의 역참조(dereference).

//연산
// 포인터 변수의 +, -는 타입과 

//void* p;	// 보이드 포인터는 형변환을 활용할시 역참조 가능.
			// 어떤 타입이든 가르킬 수 있다. (reference)
			// 역참조 혹은 연산을 위해서는 형변환이 필수. //ex) std::cout << *(char*)p << std::endl

//Pointer to Pointer
// 
//int		x{ 10 };
//int* p{ &x };
//
//int** pp{ &p };
//
//std::cout << x << std::endl;
//std::cout << *p << std::endl;
//std::cout << **pp << std::endl;

//Pointer to Struct
//
//	struct status
	//{
	//int HP;
	//int MP;
	//};
	//status myStatus{ 100, 10 };
	//status* pStatus{ &myStatus };

	//std::cout << pStatus->HP << " : " << pStatus->MP << std::endl; // 화살표 연산자

// Const Pointer
// 
// const int x{ 10 }; 
//	const int* p = &x;
	
// 오른쪽에서 왼쪽으로 읽어보면 해답이 보임
// 

// 1. 식별자(Identifier : 함수명, 변수명)를 찾는다.
	// 2. 오른쪽으로 읽기
	//	괄호 ')'가 나오면 우선순위에 따라 왼쪽으로 읽기
	//	오른쪽으로 다 읽으면 끝
	// 3. 왼쪽으로 읽기
		// * : pointer to
		// [] : array of
		// () : fnction returning
//		
// ex) int *num[3]; == num is 3-array of pointer to int		, int *num[3] { &x, &y, &z }
// ex) int (*num)[3]; == num is pointer to 3-array of int	, int (*num)[3] = num;
// ex) int* (*(*array[5])())(); array is 5-array of pointer to function returning pointer to function returning pointer to int
// 
// 포인터 읽는 법 right -> left
//	int x{ 10 }, y{ 10 };			const int* p1 = 상수형 정수를 가르키는 포인터	//상수를 가르키는 포인터
//	const int* p1;
//	p1 = &y;						주소값 변경 가능
//	*p1 = 2;						역참조 불가능
//
//	int* const p2{ &x };		= 상수 포인터
//	p2 = &y;					주소값 변경 불가능
//	*p2 = 2;					역참조 가능

// const int* const p3{ &x }; 
//p3 = &y;

//void swap(int* x, int* y)	// call by reference
//{
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//
//}

//Call by Value VS Call by Reference

// Call by Reference = 인자로 넘겨준 참조(변수)의 값을 수정할 수 있음

// 참조 타입(Reference type)
// 1. 선언과 동시에 초기화 필요
// 2. 초기화 이후에는 다른 변수를 참조하도록 변경 불가능
// 3. 함수의 매개변수에 참조형을 많이 씀.

// 참조 타입 VS 포인터 타입

// 참조 타입
//	int x{ 1 };
//	int& ref{ x };	- 초기화 할때만 참조가 일어남, 나머지는 전부 역참조 식
//	ref = 3;

// 포인터 타입
//	int x1 = 1;
//	int* p{ &x1 };
//	*p = 3;

// 참조와 상수
	// 참조 상수 : 개념 x, 참조 자체가 상수의 의미

// 알아두면 좋은 상식
	// const int& ref = 10 + 20; // 우측값 참조 R-VALUE Reference
	// 우측값은 객체가 아니라서, 임시객체(무명객체)에 담아서 참조를 사용


void PrintValue(const int& x)
{
	std::cout << x << std::endl;
}
int main()
{
	int x{ 10 };
	PrintValue(x);

	const int y{ 20 };
	PrintValue(y);

	PrintValue(30); // 무명객체
	PrintValue(20 + 30);
	PrintValue(x + y);

}

