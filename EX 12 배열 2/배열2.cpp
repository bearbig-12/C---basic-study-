#include <iostream>

int main()
{
	int Array[15] = {
		0, 0, 1, 0, 0,
		0, 1, 1, 1, 0,
		1, 1, 1, 1, 1,
	};
	int m{ 0 };
	int n{ 0 };

	std::cin >> m, n;
	if (m == 1)
	{
		m = 0;
	}
	else if (m == 2)
	{
		m = 5;
	}
	else if (m == 3)
	{
		m = 10;
	}
	std::cout << Array[m + (n - 1)];
}