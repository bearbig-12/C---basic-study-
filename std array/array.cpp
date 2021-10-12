#include <iostream>
#include <array>

int main()
{
	std::array<int, 4> intArray{ 0, 1, 2, 3 };

	//for (auto e : intArray)
	//{
	//	std::cout << e << std::endl;
	//}

	//std::array<int, 4>::iterator iter = intArray.begin();

	for (auto iter = intArray.begin(); iter != intArray.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << *(intArray.data()) << std::endl;
}