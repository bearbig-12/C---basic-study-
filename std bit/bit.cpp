#include <iostream>
#include <bitset>
int main()
{
	std::bitset<4> flag;
	//	1 : 0001
	//	3 : 0100

	//flag |= 0b0001;
	//flag |= 0b0100;

	//flag.set(0, 1);
	//flag.set(2, 1);

	flag[0] = 1;
	flag[2] = 1;
	if (flag[0] && flag[2])
	{

	}

	std::cout << flag << std::endl;
}