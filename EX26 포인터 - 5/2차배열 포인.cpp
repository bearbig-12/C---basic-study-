#include <iostream>

//배열 매개변수

	//배열 : int params[], int count




//int Sum(int input[][3], int row_size, int col_size)	// 안전하게 코딩하기 위해서 사이즈를 넘겨준다
//{
//	int sum{};
//	
//	for (int i = 0; i < row_size; ++i)
//	{
//
//		for (int j = 0; j < col_size; ++j)
//		{
//			sum += input[i][j];
//		}
//	}
//	return sum;
//}

//int Sum(int* p, int row_size, int col_size)	// 안전하게 코딩하기 위해서 사이즈를 넘겨준다
//{
//	int sum{};
//
//	for (int i = 0; i < row_size; ++i)
//	{
//
//		for (int j = 0; j < col_size; ++j)
//		{
//			sum += *p++;
//		}
//	}
//	return sum;
//}

//int Sum(int (*number)[3], int row_size, int col_size)	// 안전하게 코딩하기 위해서 사이즈를 넘겨준다
//{
//	int sum{};
//
//	for (int i = 0; i < row_size; ++i)
//	{
//
//		for (int j = 0; j < col_size; ++j)
//		{
//			sum += *((*number) + j);
//		}
//		++number;
//	}
//	return sum;
//}

int Sum(int *number, int count)	// 안전하게 코딩하기 위해서 사이즈를 넘겨준다
{
	int sum{};

	for (int i = 0; i < count; ++i)
	{
		sum += *number++;
	}
	return sum;
}


int main()
{
	int number[2][3]{
		{1, 2, 3},
		{4, 5, 6 }
	};

	

	//std::cout << Sum(number, 2, 3) << std::endl;
	std::cout << Sum(&number[0][0], 2 * 3) << std::endl;

}