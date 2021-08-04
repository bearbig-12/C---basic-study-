#pragma once
#include <iostream>
void Move(int n, char from, char to);
int input_user();



int input_user()
{
	int input{ 0 };
	std::cout << " Tower of Hanoi " << std::endl;
	std::cout << "Rule 1 : Player can move only one disc at a time " << std::endl;
	std::cout << "Rule 2 : Larger disc cannot be placed on a samll disc " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Please Insert the number of discs which you want : ";

	std::cin >> input;

	return input;
}
void Hanoi(int n, char from, char temp, char to)
{
	
	//base case
	if (n == 1)
	{
		
		Move(n ,from, to);	//A -> C
		
	}
	//recursive case
	else if (n > 0)
	{
		Hanoi(n - 1, from, to, temp);	//A->B
		
		Move(n, from, to);
		
		Hanoi(n - 1, temp, from, to);	//B->C

	}
	
}
void Move(int n,char from, char to)
{
	static int counter{ 1 };
	std::cout << counter << " : " << " Move disc " << n << " from " << from << " to " << to << std::endl;
	++counter;
	
}
