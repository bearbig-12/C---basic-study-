#include <iostream>

enum Type
{
	INT, FLOAT,DOUBLE,CHAR
};

void PrintArray(int input[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << input[i] << std::endl;
	}
}

void PrintArray(float input[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << input[i] << std::endl;
	}
}

void Swap(int &x, int &y)
{
	int temp{ 0 };

	temp = x;
	x = y;
	y = temp;
}

void Swap(float &x, float& y)
{
	float temp{ 0 };

	temp = x;
	x = y;
	y = temp;
}

void SequentionalSort(void* input, Type type, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			switch (type)
			{
			case INT:
			{
				int* p = static_cast<int*>(input);
				if (p[i] > p[j])
				{
					Swap(p[i], p[j]);
				}
				break;
				
			}
			case FLOAT:
			{
				float* f = static_cast<float*>(input);
				if (f[i] > f[j])
				{
					Swap(f[i], f[j]);
				}
				break;
			}

			default:
				break;
			}
		}
	}
}

int main()
{
	const int arraysize = 5;
	int array[arraysize]{ 8,7,2,3,1 };
	float array2[arraysize]{ 8.5, 7.5, 2.5, 3.5, 1.5 };

	SequentionalSort(array2, FLOAT, arraysize);
	PrintArray(array2, arraysize);
}