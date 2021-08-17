#include <iostream>

using Comparison = bool (*)(int x, int y);


//Ascending (오름차순)
bool Ascending(int x, int y)
{
	return x > y;
}
// 내림차순
bool Descending(int x, int y)
{
	return x < y;
}


void Sort(int number[], int count, Comparison f)
{
	int temp{};

	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if ( f(number[i], number[j]) )
			{
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;

			}
		}
	}
}

int main()
{
	const int size = 5;
	int scores[size]{ 20, 10, 40, 15, 30 };



	Sort(scores, size, Ascending);

	for (int i = 0; i < size; ++i)
	{
		std::cout << scores[i] << ", ";
	}
	std::cout << std::endl;

	

}