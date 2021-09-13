#include <iostream>

// 클래스 이름 : 파스칼(첫글자 대문자)
// 멤버 변수 : 처음에 m을 붙이고 나머지는 파스칼
// 멤버함수 : 파스칼

class Dog
{

private:
	int mX;	// 인스턴스에서 접근 불가능

public:
	int mY;
	int mZ;
	
public:
	void Bark(); //선언  
	
protected:
	int mColor;

};

class Chihuahua : Dog
{
	// mAge 사용 불가능
	// mColor 사용 가능
};

//정의
// :: 범위 지정 연산자
void Dog::Bark()
{
	std::string x;
}

int main()
{
	Dog happy;



}