#include<iostream>
#include"Quest.h"


int main()
{
	Quest q1 = Quest(100, 100);	// 복사 생성자 r value 임시 메모리에서 100 100을 복사해서 옴
	Quest q2{};
	q1.Print();
}