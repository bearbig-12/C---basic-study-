#include <iostream>

int main()
{	
	// 2���� �迭 ���� �Ҵ�
	//int row{ 2 }, col{ 3 };

	//int** array = new int* [row];
	//for (int i = 0; i < row; ++i)
	//{
	//	array[i] = new int[col];

	//}

	//for (int i = 0; i < row; ++i)
	//{
	//	delete[] array[i];
	//}

	//delete[] array;
	
	//1���� �迭�� 2�����迭 ǥ��(�����Ҵ�)
	// �� x ��
	//
	int* array = new int[6]{ 1 };
	for (int i = 0; i < 6; ++i)
	{
		std::cout << array[i] << " , ";
		if ((i + 1) % 3 == 0) // i + 1 % ��
		{
			std::cout << std::endl;
		}
	}
	
}