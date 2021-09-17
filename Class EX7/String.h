#pragma once
#include <string>
class String
{
private:
	char* mString;
public:
	String(const char* string);	// 리터럴을 넘겨 줄때는 상수로 넘겨줘야 한다.
	~String();
	void Print();
};

