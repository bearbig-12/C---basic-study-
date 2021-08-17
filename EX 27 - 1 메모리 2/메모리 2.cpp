#include <iostream>

// C++ 스타일 동적 할당
	// 포인터 변수 = new 타입;
	// delete 포인터 변수
	// new 와 delete 는 단항 연산자

// 프로그램 메모리 구조
	// 1. Code or Text
	// 실제 코드
	// 
	// *2. Data
	// 프로그램 시작시에 할당, 종료시에 해체
	// 전역변수
	//
	// *3. Heap or Free
	// 실행시에 동적으로 할당
	// 동적 할당
	//
	// 4. Register
	// 함수주소
	//
	// *5. Stack
	// 함수 호출 시 생성되는 매개변수 및 지역변수, 함수 반환과 함께 제거 
	// 지역변수, 매개변수

void MyFunction1();
void MyFunction2();

char gString[]{ "Memory LayOut" };
int gInteger;

int main()
{
	//int* p{ new int{4} };

	//int* p;
	//p = new int;
	//*p = 4;

	//std::cout << *p << std::endl;

	//delete p;

	std::cout << (void*)gString << std::endl;
	std::cout << &gInteger << std::endl;

	int* p = new int;

	std::cout << "main::p - " << p << std::endl;

	MyFunction1();

	delete p;
}

void MyFunction1()
{
	int local;
	std::cout << "MyFunction1::local - " << &local << std::endl;

	MyFunction2();
}
void MyFunction2()
{
	int local;
	std::cout << "MyFunction2::local - " << &local << std::endl;

}