#include "String.h"
#include <string>
#include <iostream>

String::String(const char* string)
{
	int length{ 0 };

	while (string[length] != '\0')
	{
		length++;
	}

	mString = new char[length + 1];

	for (int i = 0; i < length; ++i)
	{
		mString[i] = string[i];
	}
	mString[length] = '\0';
}

String::String(const String& from)
{
	int length{ 0 };
	length = getLength(from.mString);
	mString = new char[length + 1];

	strcpy_s(mString, length+1, from.mString);
}

String::String(int length)
{
	mString = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		mString[i] = ' ';
	}
	mString[length] = '\0';
}

String::~String()
{
	delete[] mString;
}

String String::operator+(const String& string)
{
	int mLength{ 0 };
	int strLength{ 0 };

	mLength = getLength(mString);

	strLength = getLength(string.mString);

	String result(mLength + strLength + 1);

	mLength = strLength = 0;
	int i = 0;

	while (mString[mLength] != '\0')
	{
		result.mString[i++] = mString[mLength++];

	}
	while (string.mString[strLength] != '\0')
	{
		result.mString[i++] = string.mString[strLength++];
		
	}
	result.mString[mLength + strLength] = '\0';

	return result;
}

String String::operator=(const String& string)
{
	int mLength, strLength = 0;

	mLength = getLength(mString);
	strLength = getLength(string.mString);

	if (mLength < strLength) // �̰�� �޸𸮰� �ʰ��Ǳ⿡ ũ�⿡ �°� �迭 ������(?)�� �ʿ�
	{
		delete mString;
		mString = new char[strLength + 1];
	}

	for (int i = 0; i < mLength; ++i)
	{
		mString[i] = ' ';
	}

	int j = 0;

	while (string.mString[j] != '\0')
	{
		mString[j] = string.mString[j];
		++j;
	}
	mString[strLength] = '\0';

	return *this;
}

String String::operator+=(const String& string)
{
	(*this) = (*this) + string;
	return (*this);
}

char& String::operator[](int index)
{
	// TODO: ���⿡ return ���� �����մϴ�.
	return mString[index];
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
	os << "/" << string.mString << "/" << std::endl;
	return os;
}

int String::getLength(const char* string)	// ���� ���ϱ�
{
	int mLength = 0;
	while (string[mLength] != '\0')
	{
		mLength++;
	}
	return mLength;
}

void String::Print(const String& string)
{
	std::cout << mString << std::endl;

}
