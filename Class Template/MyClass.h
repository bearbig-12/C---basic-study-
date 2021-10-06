#pragma once

template <typename T>
class MyClass
{
	T mValue;
public:
	void Function(T arg);
};

template<typename T>
inline void MyClass<T>::Function(T arg)
{
}
