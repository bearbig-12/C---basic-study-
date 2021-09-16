#include "Student.h"
#include <iostream>
void Student::Print()
{
	std::cout << "Student info : " << std::endl;
	std::cout << "Nmae : " << this->mName << std::endl;
	std::cout << "Score : " << this->mScore << std::endl;
}
