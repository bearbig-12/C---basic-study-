#include<iostream>
#include"Quest.h"


int main()
{
	Quest q1 = Quest(100, 100);	// ���� ������ r value �ӽ� �޸𸮿��� 100 100�� �����ؼ� ��
	Quest q2{};
	q1.Print();
}