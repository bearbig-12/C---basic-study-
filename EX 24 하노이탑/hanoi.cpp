#include <iostream>
#include "Hanoi.h"

int main()
{
	
	int input = input_user();

	Hanoi(input, 'a', 'b', 'c');

}
