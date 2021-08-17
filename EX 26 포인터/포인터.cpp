#include <iostream>

// & ampersand  : �ּ� ������
//				: ���� ������ �ּҸ� ��ȯ

// * star/ asterisk : ������ ������
//					: ���� ������ �ּҸ� ����Ű�� ������ ����
//					: ������ ������

// �������� �⺻
// int* p; - ������ ������ p�� ����
// p = &a; - ��������p�� b�� �ּҸ� ����
// p �� b�� �����Ѵ�(reference)

//*p = 3; p�� ����Ű�� �ִ� ���� ���� ���� p�� ������(dereference).

//����
// ������ ������ +, -�� Ÿ�԰� 

//void* p;	// ���̵� �����ʹ� ����ȯ�� Ȱ���ҽ� ������ ����.
			// � Ÿ���̵� ����ų �� �ִ�. (reference)
			// ������ Ȥ�� ������ ���ؼ��� ����ȯ�� �ʼ�. //ex) std::cout << *(char*)p << std::endl

//Pointer to Pointer
// 
//int		x{ 10 };
//int* p{ &x };
//
//int** pp{ &p };
//
//std::cout << x << std::endl;
//std::cout << *p << std::endl;
//std::cout << **pp << std::endl;

//Pointer to Struct
//
//	struct status
	//{
	//int HP;
	//int MP;
	//};
	//status myStatus{ 100, 10 };
	//status* pStatus{ &myStatus };

	//std::cout << pStatus->HP << " : " << pStatus->MP << std::endl; // ȭ��ǥ ������

// Const Pointer
// 
// const int x{ 10 }; 
//	const int* p = &x;
	
// �����ʿ��� �������� �о�� �ش��� ����
// 

// 1. �ĺ���(Identifier : �Լ���, ������)�� ã�´�.
	// 2. ���������� �б�
	//	��ȣ ')'�� ������ �켱������ ���� �������� �б�
	//	���������� �� ������ ��
	// 3. �������� �б�
		// * : pointer to
		// [] : array of
		// () : fnction returning
//		
// ex) int *num[3]; == num is 3-array of pointer to int		, int *num[3] { &x, &y, &z }
// ex) int (*num)[3]; == num is pointer to 3-array of int	, int (*num)[3] = num;
// ex) int* (*(*array[5])())(); array is 5-array of pointer to function returning pointer to function returning pointer to int
// 
// ������ �д� �� right -> left
//	int x{ 10 }, y{ 10 };			const int* p1 = ����� ������ ����Ű�� ������	//����� ����Ű�� ������
//	const int* p1;
//	p1 = &y;						�ּҰ� ���� ����
//	*p1 = 2;						������ �Ұ���
//
//	int* const p2{ &x };		= ��� ������
//	p2 = &y;					�ּҰ� ���� �Ұ���
//	*p2 = 2;					������ ����

// const int* const p3{ &x }; 
//p3 = &y;

//void swap(int* x, int* y)	// call by reference
//{
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//
//}

//Call by Value VS Call by Reference

// Call by Reference = ���ڷ� �Ѱ��� ����(����)�� ���� ������ �� ����

// ���� Ÿ��(Reference type)
// 1. ����� ���ÿ� �ʱ�ȭ �ʿ�
// 2. �ʱ�ȭ ���Ŀ��� �ٸ� ������ �����ϵ��� ���� �Ұ���
// 3. �Լ��� �Ű������� �������� ���� ��.

// ���� Ÿ�� VS ������ Ÿ��

// ���� Ÿ��
//	int x{ 1 };
//	int& ref{ x };	- �ʱ�ȭ �Ҷ��� ������ �Ͼ, �������� ���� ������ ��
//	ref = 3;

// ������ Ÿ��
//	int x1 = 1;
//	int* p{ &x1 };
//	*p = 3;

// ������ ���
	// ���� ��� : ���� x, ���� ��ü�� ����� �ǹ�

// �˾Ƶθ� ���� ���
	// const int& ref = 10 + 20; // ������ ���� R-VALUE Reference
	// �������� ��ü�� �ƴ϶�, �ӽð�ü(����ü)�� ��Ƽ� ������ ���


void PrintValue(const int& x)
{
	std::cout << x << std::endl;
}
int main()
{
	int x{ 10 };
	PrintValue(x);

	const int y{ 20 };
	PrintValue(y);

	PrintValue(30); // ����ü
	PrintValue(20 + 30);
	PrintValue(x + y);

}

