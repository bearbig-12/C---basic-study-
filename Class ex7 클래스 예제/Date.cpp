#include "Date.h"
#include <iostream>
void Date::Print()
{
	std::cout << "The Date is : " << this->mDay << " , " << this->mMonth << " , " << this->mYear << std::endl;
}
