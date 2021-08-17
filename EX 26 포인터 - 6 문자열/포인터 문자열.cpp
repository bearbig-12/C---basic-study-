#include <iostream>	

// 문자열과 포인터
// 문자열 리터럴은 const char* 
// const char* pc = "boy"; == x 리터럴은 대입불가.


// 복사
	// char* strcpy(char* dest, const char* src);
	// char* strcpy_s(char* dest, size_t size, const char* src);
	// dest[10], src[100] 일시 overflow가 발생 할 수 있음
	// 배열에 배열을 넣고 싶을시 배열을 복사해서 넣어야 한다.

// 비교
	// int strcmp(const char* str1, const char* str2);	// 아스키코드로( 알파벳 순서대로 비교) 문자열의 길이로 비교하는거 아님
	// 비교하기 위해 둘다 const
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

	//const char* pc = "doggy"; // == const char array와 같다
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
	std::cout << "길이 : " << strlen(myString) << std::endl;
	std::cout << "사이즈 : " << sizeof(myString) << std::endl;

	char compareStr[5]{};

	
	strcpy_s(compareStr, 5 ,"zoo");

	std::cout << " TEST VS BOY : " << strcmp(myString, compareStr) << std::endl;

}