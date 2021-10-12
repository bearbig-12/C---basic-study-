#include <string>



// 컨테이너(Container)
//
// 반복자(iterator)
// 포인터::원소를 가르키는 포인터
// 순회 : ++, --
// begin(), end()

//	std::array
//	std::vector				array의 동적버젼
//	std::list				Double linked list		
//	std::forward_list		Single linked list
//	std::deque				양방향 큐

//	std::stack
//	std::queue
//	std::priority_queue		우선순위 큐 중요한일을 먼저 처리

//	std::set
//	std::multiset
//	std::map
//	std::multimap


// 알고리즘(Algorithm)






//	문자열 string


//		std::string

// 원소가 char인 컨테이너

// std::to_string(type val) // 기본타입 -> 문자열

// std::stoi(const string str, size_t* idx or pos = 0, int base = 10)	// 문자열 -> 기본타입 // base = 진법 size_t*, pos 진법 처리된 char들의 갯수


// std::stod
// std::stof
//etc..


// std::wstring //한글이나 중국어 같은 글자들을 위한 확장 스트링

		//wchar_t ch = L'가';
		//
		//std::wstring str3 = L"가나다";
		//
		//std::wcout << str3.length() << " : " << str3 << std::endl;
		//
		//std::cout << std::endl;

// 포멧제어
//	std::dec		10진법
//	std::hex		16진법
//	std::oct		8진법
//	std::boolalpha		true, false
//	std::fixed		고정 소수점 0.0001
//	std::scientific		3.14159e+00

//	std::left
//	std::right

//	ios_base::precision()	정밀도 소수점 뒤에 몇째 자리까지 나타낼거냐
//	ios_base::width()		출력 너비
//	ios::fill()				공백을 채울 문자열

// example
//	int myInt{ 123 };
//	float myFloat{ 3.141592f };
//	bool myBool{ true };
//
//	std::cout << myBool << std::endl;
//	std::cout << std::boolalpha << myBool << std::endl;
//
//	std::cout << std::dec << myInt << std::endl;
//	std::cout << std::hex << myInt << std::endl;
//	std::cout << std::oct << myInt << std::endl;
//
//	std::cout.precision(3);
//	std::cout << myFloat << std::endl;
//
//	std::cout.fill('0');
//	std::cout.width(10);
//	std::cout << std::dec << myInt << std::endl;








//	벡터 vector

//	std::vector
//	원소의 타입을 지정해서 특수화
//	객체는 원소의 크기와 원소들의 시퀀스에 대한 포인터
//	시퀀스는 인덱스(index)로 접근 : 0부터 시작
//	인덱스 접근 [] ( subscript operator )



// 범위 기반 반복문
	//for (int x : v1) // [ 0 : size() )	// 무조건 처음부터 끝까지 모든 값을 가져옴 인덱스 접근 불가
	//{
	//	std::cout << x << std::endl;
	//}

	//for (int x : v1) 
	//{
	//	x  = 0; 으로 초기화 할수 없다 왜냐하면  x에 v1에 있는 원소를 복사하기 떄문이다 따라서 값을 대입하기 위해서는 int& x : v1이 필요하다
	//}

	//for (int& x : v1) // [ 0 : size() )	// 무조건 처음부터 끝까지 모든 값을 가져옴 인덱스 접근 불가
	//{
	//	x = 0; 가능.
	//}


//	iterator
//		std::vector <int> v{ 1, 2, 3 };
//		std::vector<int>::iterator itr = v.begin();
//
//		while (itr != v.end())
//		{
//			std::cout << *itr;
//			itr++;
//		}
		
//		v.begin() , v.end()도 iterator 타입

//		for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)	// 위에 while문과 동일
//		{
//
//		}

//		for (auto itr = v.begin(); itr != v.end(); itr++)
//		{
//
//		}

//	data()
//		data는 모든 원소를 포인터로 가져옴

// ---- 중요 ----
// 람다식(Lambda Expression)
//	 특정 함수를 익명 함수로 만들어서 사용							// x = 1 + 2;     1 + 2는 익명 객체 (Rvalue)

//		[] (int a) {};
//		[] (int x, int y) - > { return x; }


//	std::array
//		
//		고정 크기의 순차 컨테이너
//		배열과 동일 - STL 지원, 객체화
//			순차 컨테이너
//			Ramdom Access
//			Fixed


//	std::vector

//		동적 크기의 순차 컨테이너
//			순차 컨테이너
//			Random Access - 가장 마지막에 추가/제거가 효율적
//			Dynamic


//	std::forward_list
//		
//		동적 크기의 순차 컨테이너
//		순차적
//		Sequential Access (Single Linked List)
