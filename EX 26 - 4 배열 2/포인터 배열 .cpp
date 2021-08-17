#include<iostream>

// 2차 배열 
	// 2차 배열을 포인터로 명시하기 위해서는 열의 갯수가 필요하다
	//	int array[2][3];
	//	int (*p)[3] == array;

	// 1. 식별자(Identifier : 함수명, 변수명)를 찾는다.
	// 2. 오른쪽으로 읽기
	//	괄호 ')'가 나오면 우선순위에 따라 왼쪽으로 읽기
	//	오른쪽으로 다 읽으면 끝
	// 3. 왼쪽으로 읽기
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

	//int** p = array;		== 2차배열을 찍기 위한 포인터(X)
	// int (*p)[3] == array;	== 2차 배열을 찍기 위한 포인터(O)	배열을 통째로 하나 찍음
}