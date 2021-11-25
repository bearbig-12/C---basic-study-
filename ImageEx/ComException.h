#pragma once
#include <exception>
#include <Windows.h>
#include <stdio.h>
#include <string>

class com_exception : public std::exception
{
private:
	HRESULT result;
	std::string description;
public:
	com_exception(HRESULT hr) : result{ hr }, description{} {}
	com_exception(HRESULT hr, std::string msg) : result{ hr }, description{ msg }{}
	virtual const char* what() const override
	{
		static char buf[512];

		if (description.length() == 0)
		{
			sprintf_s(buf, 128, "Failure with HRESULT of 0X%08X", result);

		}
		else
		{
			sprintf_s(buf, 128, "Failure with HRESULT of 0X%08X\n\n%s", 
				result ,description.c_str());

		}

		return buf;
	}

};
// inline 
//		장점: 호출스택을 사용하지 않아서 빠름
//		단점: 코드 길어짐

// 선언/정의
//	inline void f()
//	{
//	}
// 
//	선언과 정의
//	void f();
//  inline void f();

// 클래스의 경우 .h에 정의
inline void ThrowIfFailed(HRESULT hr, std::string msg = "")
{
	if (FAILED(hr))
	{
		throw com_exception(hr, msg);
	}
}