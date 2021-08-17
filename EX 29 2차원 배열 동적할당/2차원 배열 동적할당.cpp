#include <iostream>

int main()
{	
	// 2차원 배열 동적 할당
	//int row{ 2 }, col{ 3 };

	//int** array = new int* [row];
	//for (int i = 0; i < row; ++i)
	//{
	//	array[i] = new int[col];

	//}

	//for (int i = 0; i < row; ++i)
	//{
	//	delete[] array[i];
	//}

	//delete[] array;
	
	//1차원 배열로 2차원배열 표현(동적할당)
	// 행 x 열
	//
	int* array = new int[6]{ 1 };
	for (int i = 0; i < 6; ++i)
	{
		std::cout << array[i] << " , ";
		if ((i + 1) % 3 == 0) // i + 1 % 열
		{
			std::cout << std::endl;
		}
	}
	
}