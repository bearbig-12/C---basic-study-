#include <iostream>	

// ���ڿ��� ������
// ���ڿ� ���ͷ��� const char* 
// const char* pc = "boy"; == x ���ͷ��� ���ԺҰ�.


// ����
	// char* strcpy(char* dest, const char* src);
	// char* strcpy_s(char* dest, size_t size, const char* src);
	// dest[10], src[100] �Ͻ� overflow�� �߻� �� �� ����
	// �迭�� �迭�� �ְ� ������ �迭�� �����ؼ� �־�� �Ѵ�.

// ��
	// int strcmp(const char* str1, const char* str2);	// �ƽ�Ű�ڵ��( ���ĺ� ������� ��) ���ڿ��� ���̷� ���ϴ°� �ƴ�
	// ���ϱ� ���� �Ѵ� const
	// 

//int main()
//{
	//char c[6];
	//c[0] = 'd';
	//c[1] = 'o';
	//c[2] = 'g';
	//c[3] = 'g';
	//c[4] = 'y';
	//c[5] = '\0';

	//const char* pc = "doggy"; // == const char array�� ����
	//pc = &c[0];

	//std::cout << c << std::endl;
	//std::cout << pc << std::endl;
//}

int GetLength(char input[])
{
	int length = 0;

	for (int i = 0; i < 1000; ++i)
	{
		if (input[i] == '\0')
		{
			break;
		}
		++length;
	}
	return length;
}

int GetLength1(char* input)
{
	int count = 0;

	while (*input != '\0')
	{
		input++;
		count++;

	}
	return count;

}

int main()
{
	

	/*char input[1000];


	std::cin >> input;

	strcpy_s(input, 1000, input);

	std::cout << GetLength(input) << std::endl;*/

	char myString[5]{ "test" };
	std::cout << "���� : " << strlen(myString) << std::endl;
	std::cout << "������ : " << sizeof(myString) << std::endl;

	char compareStr[5]{};

	
	strcpy_s(compareStr, 5 ,"zoo");

	std::cout << " TEST VS BOY : " << strcmp(myString, compareStr) << std::endl;

}