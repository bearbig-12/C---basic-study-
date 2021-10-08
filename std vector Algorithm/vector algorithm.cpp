#include <iostream>
#include <vector>
#include <algorithm>

//// ��������
//int IntCompare(const void* a, const void* b)
//{
//	int left = *static_cast<const int*> (a);
//	int right = *static_cast<const int*> (b);
//	//-1 : a>b
//	// 0 : a=b
//	// 1 : a<b
//	if (left > right)
//	{
//		return -1;
//	}
//	else if (left < right)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

int IntCompare(const void* a, const void* b)
{
	int left = *static_cast<const int*> (a);
	int right = *static_cast<const int*> (b);

	return right - left;
}

////��������
//int IntCompare2(const void* a, const void* b)
//{
//	int left = *static_cast<const int*> (a);
//	int right = *static_cast<const int*> (b);
//	//-1 : a<b
//	// 0 : a=b
//	// 1 : a>b
//	if (left > right)
//	{
//		return 1;
//	}
//	else if (left < right)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}

int IntCompare2(const void* a, const void* b)
{
	int left = *static_cast<const int*> (a);
	int right = *static_cast<const int*> (b);

	return left - right;
}


int main()
{
	std::vector<int> v{ 1,2,3,4 };
	int array[10]{ 10, 30, 20, 5, 100, 5, 9,20,90,100 };
	//qsort(v.data(), v.size(), sizeof(int), IntCompare);
	//qsort(array, 10, sizeof(int), IntCompare2);

	/*qsort(array, 10, sizeof(int), [](const void* a, const void* b) { return *((int*)b) - *((int*)a); });
	for (auto e : array)
	{
		std::cout << e << std::endl;
	}*/

	std::for_each(v.begin(), v.end(), [](int value)	// �ؿ� ���� ��� �ݺ����� ��������� ���� ������
		{
			std::cout << value << std::endl;
		}
	);

	// ���� 2��° �ε����� ��� �������
	auto itr = v.begin();
	itr++;

	std::for_each(itr, v.end(), [](int value)	// �ؿ� ���� ��� �ݺ����� ��������� ���� ������
		{
			std::cout << value << std::endl;
		}
	);

	// �̰͵� 2��° �ε��� ���� ��� �� ����
	std::for_each(v.begin()+1, v.end(), [](int value)	// �ؿ� ���� ��� �ݺ����� ��������� ���� ������
		{
			std::cout << value << std::endl;
		}
	);

	for (const auto& e : v)
	{
		std::cout << e << std::endl;
	}
}