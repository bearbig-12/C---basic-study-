#pragma once
#include <string>
class String
{
private:
	char* mString;
public:
	String(const char* string);	// ���ͷ��� �Ѱ� �ٶ��� ����� �Ѱ���� �Ѵ�.
	~String();
	void Print();
};

