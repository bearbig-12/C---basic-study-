#pragma once
#include <iostream>
class String
{
private:
	char* mString;

public:
	String() = default;

	String(const char* string);
	String(const String& string);
	String(int length);
	~String();

	String operator +(const String& string);
	String operator =(const String& string);
	String operator +=(const String& string);
	char& operator [](int index);
	friend std::ostream& operator<<(std::ostream& os, const String& string);
	int getLength(const char* string);

	void Print(const String& string);
};

