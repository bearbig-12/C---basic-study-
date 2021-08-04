#pragma once
#include <iostream>

//void Factorial(int n)
//{
//	
//	int result{ n };
//	std::cout << n << "! : ";
//
//	for (int i = 1; i < n; ++i)
//	{
//		
//		result = result * i;
//		
//	}
//	std::cout << result;
//	
//}

int Factorial(int n)
{
	//base case
	if (n == 0)
	{
		return 1;
	}
	//recursive case
	return n * Factorial(n - 1);
	
}