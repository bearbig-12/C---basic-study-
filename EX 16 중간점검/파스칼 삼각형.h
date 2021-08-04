#pragma once
#include <iostream>
void Pascal_Triangle()
{
	//5¿­Â¥¸®
	int Triangle[10][10]{ 0 };
	int size = 5;
	Triangle[0][4] = 1;
	for (int row = 1; row < size; ++row)
	{
		for (int col = 1; col <= 10; ++col)
		{
			Triangle[row][col] = Triangle[row - 1][col - 1] + Triangle[row - 1][col + 1];
		}
	}

	for (int row = 0; row < 9; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
		
			std::cout << Triangle[row][col];
		}
		std::cout << std::endl;
	}
	for (int row = 0; row < 9; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
			if (Triangle[row][col] == 0)
			{
				std::cout << "   ";
			}
			else if(Triangle[row][col] > 0)
			std::cout << "{" << Triangle[row][col] << "}";
		}
		std::cout << std::endl;
	}
}