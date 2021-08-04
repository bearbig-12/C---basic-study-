#include <iostream>
#include <sstream>

int main()
{
	//char array[6]{ 'd', 'o', 'g', 'g', 'y', '\0' };
	//char array1[6]{ "doggy" }; //Null-terminated String.

	//array[0] = 'd';
	//array[1] = 'o';
	//array[2] = 'g';
	//array[3] = 'g';
	//array[4] = 'y';
	//array[5] = '\0'; // Null 문자 escape 시퀀스

	
	/*char MyString[10];
	std::cout << "Input String : ";
	std::cin >> MyString;

	std::cout << " Your string is  \"" << MyString << "\"" << std::endl;*/


	/*struct  Student
	{
		char name[20];
		int number;
		int score;
	};
	Student tom;

	std::cout << "Input name, number, score : ";
	std::cin >> tom.name >> tom.number >> tom.score;
	return 0;*/

	int number{ 1 };
	char name[]{ "doggy" };
	float average{ 90.1f };

	std::ostringstream oss;

	std::cout << number << "번 학생 " << name << "는 평균 " << average << " 입니다. ";

	std::cout << oss.str() << std::endl;
}