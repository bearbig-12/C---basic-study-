#include <iostream>
#include <chrono>

using Comparison = bool (*)(int, int);

bool Asceding(int x, int y)
{
	return x < y;
}

bool Descending(int x, int y)
{
	return x > y;
}

void Sort(int numbers[], int count, Comparison f)
{
	for (int i = 0; i < count; ++i)
	{
		for (int j = i + 1; j < count; ++j)
		{
			if (f(numbers[i], numbers[j]))
			{
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}


int main()
{
	const int NumAarray{ 10 };
	int scores[NumAarray]{ 10, 30, 20, 50, 70, 65, 72, 63, 90, 11 };

	auto startTime = std::chrono::system_clock::now();
	Sort(scores, NumAarray, Asceding);
	auto endTime = std::chrono::system_clock::now();

	auto Duration = endTime - startTime;
	std::cout << "Sort() : " << Duration.count() << "ms" << std::endl;

	/*for (int i = 0; i < NumAarray; ++i)
	{
		std::cout << scores[i] << " , ";
	}*/
}
// 27 27 24 25 23