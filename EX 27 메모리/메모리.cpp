#include<iostream>

// C++ 메모리 관리

// 1. 자동 메모리(Automatic Memory Allocation)
	// 자동으로 관리
	// 지역 변수 (Local Variable)
	// 매개 변수 (Parameter)

// 2. 정적 메모리(Static Memory Allocation)
	// 한번 만들면 끝까지 살아남음
	// 전역, 정적 변수
	// 만들 때 초기화 1번
// 3. 동적 메모리(Dynamic Memory Allocation)
	// 프로그래머가 만들고 없앰



//int main()
//{
//	// contiguous allocation
//	// 원소의 갯수, 원소의 크기
//	
//	//void* ptr = calloc(10, sizeof(int)); 인티저 10개를 연속으로 만든 배열
//
//	void* ptr = calloc(1, sizeof(int));
//
//	// memory allocation
//	void* ptr2 = malloc(sizeof(int));
//
//	//동적으로 만들시 무조건 없애줘야한다
//	free(ptr);
//	free(ptr2);
//
//}

int main()
{

	int array[100];

	int* buffer1, * buffer2;

	buffer1 = (int*)calloc(100, sizeof(int));

	// 게임 프로그래머 선호 - 속도 // 초기화 안해줌
	buffer2 = (int*)malloc(100 * sizeof(int));

	if (buffer1 == nullptr || buffer2 == nullptr)
	{
		return 0;
	}

	std::cout << buffer1[0] << " , " << buffer2[0] << std::endl;

	free(buffer1);
	free(buffer2);
}