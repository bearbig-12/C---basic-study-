#include <iostream>

// p	 == &array[0]
// p + 1 == &array[1]
// p + 2 == &array[2]
// p + 3 == &array[3]

// 배열 = 포인터
// 배열의 이름 = 0번째 원소의 주소
// array == &array[0]
void My_Func(int* array)
{
	int sum{};
	
	//for (int i = 0; i < 5; ++i)
	//{
	//	//sum += array[i];
	//	sum += *(array + i);
	//}
	for (int i = 0; i < 5; ++i, ++array)
	{
		sum += *array;
	}
	std::cout << sum << std::endl;
}

void My_Function(int array[5])
{
	for (int i = 0; i < 5; ++i)
	{
		array[i] = 0;
	}
}

int main()
{
	/*int array[5]{ 0 };

	int* p = &array[0];

	std::cout << p << ", " << array << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << &array[i] << std::endl;

		std::cout << p << std::endl;

		++p;
	}*/

	int number[5]{ 1, 2, 3, 4, 5 };

	My_Func(number);

	My_Function(number);

	for (int i = 0; i < 5; ++i)
	{
		std::cout << number[i] << std::endl;
	}
}