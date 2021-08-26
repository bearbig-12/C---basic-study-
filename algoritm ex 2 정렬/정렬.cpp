#include <iostream>

void PrintArray(int input[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << input[i] << std::endl;
	}
}

void Swap(int& x, int& y)
{
	int temp{ 0 };

	temp = x;
	x = y;
	y = temp;
}

//순차정렬 (Sequential Sort)
void Sequential_Sort(int input[], int count)
{
	for (int i = 0; i < count - 1; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if (input[i] < input[j])	// 오름차순
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

//버블 정렬 (Bubble Sort)
void Bubble_Sort(int input[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		for (int j = 0; j < count - (i + 1); ++j)
		{
			if (input[j] > input[j + 1])
			{
				Swap(input[j+1], input[j]);
			}
		}
	}
}

// 선택 정렬 (Selection_Sort)
void Selection_Sort(int input[], int count)
{
	
	for (int i = 0; i < count; ++i)
	{
		int min_value{ i };
		
		for (int j = i; j < count; ++j)
		{
			if (input[min_value] > input[j])
			{
				min_value = j;
			}
		
		}
		Swap(input[min_value], input[i]);
	}
}


int main()
{
	const int Array_Size{ 5 };
	int array[Array_Size]{ 8, 7, 2, 3, 1};

	//Sequential_Sort(array, Array_Size);

	Bubble_Sort(array, Array_Size);

	//Selection_Sort(array, Array_Size);

	PrintArray(array, Array_Size);


}