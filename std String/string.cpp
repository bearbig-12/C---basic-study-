#include <iostream>
#include <string>
#include <sstream>	// 문자열 스트림

void TestPrint(const std::string& str)
{
	const char* pStr{ str.c_str() };
	std::cout << strlen(pStr) << " : " << str.length() << " : " << str << std::endl;
}

int main()
{
	//int number{ 123 };
	//std::string str;

	////int -> string
	//str = std::to_string(number);
	////string -> int
	//number = std::stoi(str);

	//std::cout << str << " : " << number << std::endl;



	//C 스타일
	//char output[256];
	//sprintf_s(output, "Hello World &d &f", 10, 10.1f);
	//printf(output);



	/*std::ostringstream oss;

	oss << "Hello" << "World" << 10 << 10.1f << std::endl;
	std::cout << oss.str() << std::endl;*/


	int myInt{ 123 };
	float myFloat{ 3.141592f };
	bool myBool{ true };

	std::cout << myBool << std::endl;
	std::cout << std::boolalpha << myBool << std::endl;

	std::cout << std::dec << myInt << std::endl;
	std::cout << std::hex << myInt << std::endl;
	std::cout << std::oct << myInt << std::endl;

	std::cout.precision(3);
	std::cout << myFloat << std::endl;

	std::cout.fill('0');
	std::cout.width(10);
	std::cout << std::dec << myInt << std::endl;
}



//int main()
//{
	//std::string empty;
	//TestPrint(empty);

	//std::string sized(10, '\0');

	//TestPrint(sized);

	//std::string s1("Test");

	//std::cout << s1[0] << s1[1] << s1[2] << s1[3] << std::endl;

	//s1[0] = 't';

	//std::cout << s1 << std::endl;

	//std::string s2(s1); // 복사 생성자
	//std::string s3 = s1 + s2;		// operator
	//TestPrint(s3);
//}