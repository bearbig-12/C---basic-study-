#include<iostream>

// C++ �޸� ����

// 1. �ڵ� �޸�(Automatic Memory Allocation)
	// �ڵ����� ����
	// ���� ���� (Local Variable)
	// �Ű� ���� (Parameter)

// 2. ���� �޸�(Static Memory Allocation)
	// �ѹ� ����� ������ ��Ƴ���
	// ����, ���� ����
	// ���� �� �ʱ�ȭ 1��
// 3. ���� �޸�(Dynamic Memory Allocation)
	// ���α׷��Ӱ� ����� ����



//int main()
//{
//	// contiguous allocation
//	// ������ ����, ������ ũ��
//	
//	//void* ptr = calloc(10, sizeof(int)); ��Ƽ�� 10���� �������� ���� �迭
//
//	void* ptr = calloc(1, sizeof(int));
//
//	// memory allocation
//	void* ptr2 = malloc(sizeof(int));
//
//	//�������� ����� ������ ��������Ѵ�
//	free(ptr);
//	free(ptr2);
//
//}

int main()
{

	int array[100];

	int* buffer1, * buffer2;

	buffer1 = (int*)calloc(100, sizeof(int));

	// ���� ���α׷��� ��ȣ - �ӵ� // �ʱ�ȭ ������
	buffer2 = (int*)malloc(100 * sizeof(int));

	if (buffer1 == nullptr || buffer2 == nullptr)
	{
		return 0;
	}

	std::cout << buffer1[0] << " , " << buffer2[0] << std::endl;

	free(buffer1);
	free(buffer2);
}