#include <iostream>

//�迭 �Ű�����

	//�迭 : int params[], int count




//int Sum(int input[][3], int row_size, int col_size)	// �����ϰ� �ڵ��ϱ� ���ؼ� ����� �Ѱ��ش�
//{
//	int sum{};
//	
//	for (int i = 0; i < row_size; ++i)
//	{
//
//		for (int j = 0; j < col_size; ++j)
//		{
//			sum += input[i][j];
//		}
//	}
//	return sum;
//}

//int Sum(int* p, int row_size, int col_size)	// �����ϰ� �ڵ��ϱ� ���ؼ� ����� �Ѱ��ش�
//{
//	int sum{};
//
//	for (int i = 0; i < row_size; ++i)
//	{
//
//		for (int j = 0; j < col_size; ++j)
//		{
//			sum += *p++;
//		}
//	}
//	return sum;
//}

//int Sum(int (*number)[3], int row_size, int col_size)	// �����ϰ� �ڵ��ϱ� ���ؼ� ����� �Ѱ��ش�
//{
//	int sum{};
//
//	for (int i = 0; i < row_size; ++i)
//	{
//
//		for (int j = 0; j < col_size; ++j)
//		{
//			sum += *((*number) + j);
//		}
//		++number;
//	}
//	return sum;
//}

int Sum(int *number, int count)	// �����ϰ� �ڵ��ϱ� ���ؼ� ����� �Ѱ��ش�
{
	int sum{};

	for (int i = 0; i < count; ++i)
	{
		sum += *number++;
	}
	return sum;
}


int main()
{
	int number[2][3]{
		{1, 2, 3},
		{4, 5, 6 }
	};

	

	//std::cout << Sum(number, 2, 3) << std::endl;
	std::cout << Sum(&number[0][0], 2 * 3) << std::endl;

}