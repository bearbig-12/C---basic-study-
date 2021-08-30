#include <iostream>

void merge(int input[], int start, int half, int end);

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

//�������� (Sequential Sort)
void Sequential_Sort(int input[], int count)
{
	for (int i = 0; i < count - 1; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if (input[i] < input[j])	// ��������
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

//���� ���� (Bubble Sort)
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

// ���� ���� (Selection_Sort)
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
//���� ����
void Insertion_Sort(int input[], int count)
{
	for (int i = 1; i < count; ++i)
	{
		int Target_Value = input[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (Target_Value < input[j])
				Swap(input[j], input[j + 1]);
		}
	}
}

void Merge_Sort(int input[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int half = (start + end) / 2;

	Merge_Sort(input, start, half);
	Merge_Sort(input, half + 1, end);

	merge(input, start, half, end);
}

void merge(int input[], int start, int half, int end)
{
	int	 Left{ start };
	int	 Right{ half + 1 };

	int* pTemp = new int[end +1]{ 0 };

	//int temp[end + 1];

	int  pIndex{ 0 };

	while (Left <= half && Right <= end)
	{
		if (input[Left] < input[Right])
		{
			pTemp[pIndex] = input[Left++];
			//++Left;
			++pIndex;
		}
		else
		{
			pTemp[pIndex] = input[Right++];
			//++Right;
			++pIndex;
		}
		//++pIndex;
	}
	while (Left <= half)
	{
		pTemp[pIndex++] = input[Left++];
	
	}
	while (Right <= end)
	{
		pTemp[pIndex++] = input[Right++];
	}
	
	pIndex = 0;

	for (int i = start; i <= end; ++i)
	{
		input[i] = pTemp[pIndex++];
		//++pIndex;
	}
	delete[] pTemp;
}
void Quick_Sort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[ (left + right) / 2 ];
	
	do // ���Ұ� 1���϶� i��j�� ���� ������ ������ �ѹ� �������� ������ i �� j�� �����ϴ��� üũ
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}
		if (i <= j)	// i��j�� ũ�ν��� �Ͼ�� ���� ��쿡�� ����
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
		if (left < j)
		{
			Quick_Sort(input, left, j);

		}
		if (i < right)
		{
			Quick_Sort(input, i, right);

		}
	} while (i <= j);
}

int main()
{
	const int Array_Size{ 5 };
	int array[Array_Size]{ 8, 7, 2, 3, 1};

	//Sequential_Sort(array, Array_Size);

	//Bubble_Sort(array, Array_Size);

	//Selection_Sort(array, Array_Size);

	//Insertion_Sort(array, Array_Size);

	//Merge_Sort(array, 0, Array_Size - 1);

	Quick_Sort(array, 0, Array_Size - 1);

	PrintArray(array, Array_Size);


}