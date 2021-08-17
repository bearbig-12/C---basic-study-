#include <iostream>

int main()
{
	//int input_size;
	size_t input_size{};	// 메모리의 크기와 관련된 타입


	std::cout << "Please insert the size for the array : ";
	std::cin >> input_size;

	/*int* array = new int[input_size];

	for (int i = 0; i < input_size; ++i)
	{
		array[i] = 0;
	}*/
	int* array{ new int[input_size] {} };

	
	delete[] array;
	array = 0;
}