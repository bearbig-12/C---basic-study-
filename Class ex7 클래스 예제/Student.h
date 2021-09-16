#pragma once
#include <iostream>
#include <string>

class Student
{
private:
	std::string mName;
	int mScore;

public:
	Student(std::string name, int score) : mName{ name }, mScore{ score }
	{

	}
	void Print();
};

