#include<iostream>

// 2�� �迭 
	// 2�� �迭�� �����ͷ� ����ϱ� ���ؼ��� ���� ������ �ʿ��ϴ�
	//	int array[2][3];
	//	int (*p)[3] == array;

	// 1. �ĺ���(Identifier : �Լ���, ������)�� ã�´�.
	// 2. ���������� �б�
	//	��ȣ ')'�� ������ �켱������ ���� �������� �б�
	//	���������� �� ������ ��
	// 3. �������� �б�
		// * : pointer to
		// [] : array of
		// () : function returning
int main()
{
	int array[2][3]
	{
		{1, 2, 3},
		{4, 5, 6}
	};
	//int(*p)[3] = array;
	int* p = &array[0][0];
	for (int i = 0; i < 2; ++i)
	{
		std::cout << " { ";
		for (int j = 0; j < 3; ++j)
		{
			//std::cout << *((*p) + j) << ", ";
			std::cout << *p++ << ", ";
			
		}
		std::cout << " } ";
		std::cout << std::endl;
		//++p;
	}
	

	




	//for (int i = 0; i < 2; ++i)
	//{
	//	for (int j = 0; j < 3; ++j)
	//	{
	//		std::cout << &array[i][j] << ", ";
	//	}
	//	std::cout << std::endl;
	//}

	int array2[2][3][4];

	int(*p2)[3][4] = array2;

	//int** p = array;		== 2���迭�� ��� ���� ������(X)
	// int (*p)[3] == array;	== 2�� �迭�� ��� ���� ������(O)	�迭�� ��°�� �ϳ� ����
}