#include "String.h"
#include <iostream>


int main()
{
	String s1{ "Hello" };
	String s2{ "Test" };
	String s3(10);

	std::cout << s1;
	s1 += s2;
	std::cout << s1;

	//String s4 = s1 + s2;
	//std::cout << s4;

	/*s1 = s2;
	std::cout << s1;*/

	//char x;
	// x = s1[2];
	//std::cout << x;

}