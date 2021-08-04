#pragma once
#include <iostream>

void Snail()
{
	int Snail_array[5][5]{ 0 };
	int value{ 0 };
	
	int row1 = 0;
	int col1 = -1;
	int i = 1;
	int size{ 5 };
	int count{ 0 };

	for (int j = 0; j < 3; ++j)
	{
		
		for (int col = count; col < size; ++col)
		{
			col1 += i;
			Snail_array[row1][col1] = ++value;
			if (value == 25)
			{
				break;
			}
		}
		++count;
		for (int row = count; row < size; ++row)
		{
			row1 += i;
			Snail_array[row1][col1] = ++value;
		}
		for (int col = size; col > count; --col)
		{
			col1 -= i;
			Snail_array[row1][col1] = ++value;
		}
		++count;
		for (int row = size; row > count; --row)
		{
			row1 -= i;
			Snail_array[row1][col1] = ++value;
		}
		
	}
	
	
	
	
	for (int row = 0; row < 5; ++row)
	{
		for (int col = 0; col < 5; ++col)
		{

			std::cout << " { " <<Snail_array[row][col] << " } ";
		}
		std::cout << std::endl;
	}
}