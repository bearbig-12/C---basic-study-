#include <iostream>

int* Duplicate(int array[], int count)	// 배열을 반환하기 위해서는 동적으로 배열을 만들면 Heap 메모리에 배열이 올라가기 때문에 return(반환가능)
{
	int* pNew{ new int[count] };

	return pNew;
}

void CountDown(int n)
{
	//Base case
	if (n == 0)
	{
		std::cout << "FIRE !!!" << std::endl;
		return;
	}
	std::cout << n << std::endl;

	//Recursive case
	CountDown(n - 1);
}
void Myfunc(int x)
{
	while (x >= 1)
	{
		std::cout << x << std::endl;
		x /= 2;
	}
}

void Myfunc2(int x)
{
	if (x < 1)
	{
		return;
	}
	std::cout << x << std::endl;
	Myfunc2(x / 2);
}

void RecursiveExp(int n)
{
	std::cout << n << std::endl;
	if (n == 0)
	{
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		
		RecursiveExp(n - 1);
	}

	//RecursiveExp(n - 1);

}

int main()
{
	//const int COUNT{ 5 };
	//int numbers[COUNT]{ 1, 2, 3, 4, 5 };

	////int* pNewArray = Duplicate(numbers, COUNT);
	//delete[] pNewArray;

	//CountDown(10);

	//Myfunc2(30);
	RecursiveExp(3);


}