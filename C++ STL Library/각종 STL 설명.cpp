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


//	std::deque
//		
//		동적 크기의 순차 컨테이너
//		순차적
//	


//	std::stack


//	std::queue

//	std::priority_queue


//	std::set
//
//		특정 순서에 따라 고유한 원소를 저장
//		(원소를 추가하면 자동적으로 정렬)
//			연관적(associative)
//			unique key
//			순서집합(ordered set)
//			Dynamic



//---------------------------------------------------------

//		std::vector
//
//			배열 접근
//			추가/삭제 뒤에서만 일어날 경우

//		std::list
//
//			중간에서 삭제가 일어나는경우 (ex: 탄막게임에서 총알을 담을 컨테이너로 적합)

//		std::map

//			<key, value>
//			많은 데이터에 대한 검색이 빨라요




//		C++11
//----------------------------------------------------

//			nullptr
//			auto
//			uniform initialization
//			range-base for
//			Lambda Expression
//				Anonymous Function
//
//				[=] () mutable throw() -> int
//				{
//					return x;
//				}

//			[] : 캡쳐절
//				[] : 외부 변수 사용 불가
//				[=] : Call by Value;
//				[&] : Call by Reference
//				() : 매개변수 목록
//				mutable : 무시
//				throw() : 무시
// 
//				-> int : 반환타입
// 
//				auto expr = [](int a, int b)			//[] 캡처절 해당 블록에 있는 변수를 캡처해줌, 외부 변수 사용 불가 // [=] : Call by Value // [&] : Call by Reference
//				{
//
//				};
//
//				int a, b;
//				auto expr1 = [&](int x, int y)
//				{
//					a = x;
//					b = y;
//				};
//				[](int a) -> float		// 반환타입 float
//				{
//					return 1.0f;
//				};

//			우측값 참조
//
//				void funtionforRef(int&& a)
//				{
//
//				}
//				int main()
//				{
//						int x;
//						funtionforRef(x);	// 우측값을 참조하기에 불가
//						funtionforRef(1);	// 우측값에 대한 참조가 불가능 해짐 (리터럴) void funtionforRef(int&& a) 이경우는 우측값 참조를 쓰기 때문에 가능
// 
//				}

//				우측값 참조를 위한 std::move() 함수 즉 a의 소유권을 temp에 양도하는 용도 // 내부에서 일어나는 깊은 복사의 과정이 사라짐
// 

/*					template<typename T>
					void Swap(T&& a, T&& B)	// 우측값 참조를 위한 &&
					{
						T temp;
						temp = a;
						a = b;
						b = temp;
					}
					template<typename T>
					void Swap1(T& a, T& B)	// 우측값 참조를 위한 std::move() 함수 즉 a의 소유권을 temp에 양도하는 용도 // 내부에서 일어나는 깊은 복사의 과정이 사라짐
					{
						T temp;
						temp = std::move(a);
						a = std::move(b);
						b = std::move(temp);
				
						//temp = a;
						// 1. temp 해제
						// 2. a의 복사 무명객체
						// 3. 무명객체의 이름이 temp
				
						// int temp = std::move(a);
						// 3
					}
					void funtionforRef(int&& a)
					{
				
					}
					template<typename T>
					void TemplateFunction(T&& A)
					{
						funtionforRef(std::forward<T>(A));		// A가 x+x가 넘어가는게 아닌 2가 넘어가기 때문에 전달할때 의미 그대로 x+x를 넘겨줘야 하기에 
					}
				
					int main()
					{
						int x{ 1 };
						//funtionforRef(x);
						funtionforRef(1);	// 우측값에 대한 참조가 불가능 해짐 (리터럴) void funtionforRef(int&& a) 이경우는 우측값 참조를 쓰기 때문에 가능
						funtionforRef(x + x);
						TemplateFunction(x + x);
					}
*/

//			constexpr
//				const + expression

//				const										constexpr
//				컴파일/런타임에결정							컴파일



//			Exception (예외)

//------------C++ 클래스 변화-----------------

//		기본 이동 생성자 / 복사 생성자
//		MyClass(const MyClass&)					복사 생성자
//		MyClass& operator=(const MyClass&)		복사 대입 연산자

//		MyClass(MyClass&&)						이동 생성자 (우측값 참조)
//		MyClass& operatr=(MyClass&&)			이동 대입 연산자


//		클래스 내부에서 멤버 초기화
// 
//		class	MyClass
//		{
//			int mHp{0};
//		public:
//			MyClass() :mHp{1} {};
//		};
//
//		위와 같은 경우 생성자의 초기화가 우선이다.
// 

//		Override
// 
//		부모에서 virtual 자식에서 override
// 
//		class Base
//		{
//		public:
//			virtual void func1() const {}
//			void func2() {}
//		};

//		class Derived : public Base
//		{
//		public:
//			void func1() {}	// override x - 위에 virtual 함수에 const가 붙어 있기 때문에 같은 함수가 아님 void func1() {} const  이렇게 해주면 가능
//			void func2()	// override x
//		};

//		final
//
//		클래스나 함수에 뒤에 final을 붙일시 상속이 불가능 하게 막아버린다
//		class MyClass final
//		virtual void func1() const final {}

//		=default, =delete
//
//		class MyClass
//		{
//		public:
//			MyClass(const MyClass&) = default; - 복사 생성자를 기본생성자로 사용하겠다. / default - 기본 생성자 지정자
//			MyClass(MyClass&&) = delete;	   -  이 생성자를 지운다.
//		};

//		enum class
//
//			이름이 전역, 중복 위험성 높음
//			기본 4 바이트 정수 - 공간 낭비
//			정수 연산으로 집합의 범위를 벗어나는 위험

//			enum class Dog : char
//			{
//				white,
//				black
//			};

//			enum class Cat
//			{
//				white,
//				black
//			};

//		반환 타입 접미사 
//	
//		auto function-name ( argument-list ) -> return-type

//		Raw String literal
//
//		std::cout << R"(		)" << std::endl;

//		Variadic
//
//		void function(int count, ...)


//		Variadic Template
//
//		template<class T, class... Types>
//		T* Make(Types&& ... args)
//		{
//			return new T(std::forward<Types>(args)...);
//		}

//		Warrior* Make()
//		{
//		}

//		Archer* Make(int bow)
//		{
//		}

//		Wizard* Make(float staff, float orb)
//		{
//		}


//		-----스마트 포인터------
// 
//		소유권
//			: 명시
//		메모리 해제 시점
//			: 안쓰면 알아서 해제
//		장점
//			*이 없어요
//		단점
//			<> 템플릿

//		std::unique_ptr
//			포인터를 지정하고 있는 객체를 소유
//			복사 생성자 x, 복사 배정 x
//			이동 생성자 o, 이동 배정 o
//
//			unique_ptr::reset()		포인터 해제, 초기화
//			unique_ptr::get()		c스타일 포인터를 반환
//			unique_ptr::release()
	

/*		class MyClass
		{
		public:
			int mValue;
		};
		
		int main()
		{
			//std::unique_ptr<MyClass> p{ new MyClass };
			std::unique_ptr<MyClass> p{ std::make_unique<MyClass>() };
		
		
			std::cout << p->mValue << std::endl;
		
			MyClass* pOld;
			pOld = p.get();
			//delete pOld // 스마트 포인터 쓸땐 딜리트 쓰지말기 제발
		}
*/



//		std::shared_ptr

//			객체를 소유 x, 참조 o
//			reference count로 추적
//			하나의 객체를 여러개가 공유해야 할 경우 사용

/*			class Image
			{

			};

			class Demon
			{
				std::shared_ptr<Image> mspImage;

			public:
				Demon(std::shared_ptr<Image> img) : mspImage{ img }
				{

				}
			};

			int main()
			{
				std::shared_ptr<Image> spImage{ std::make_shared<Image>() };

				{
					auto demon1 = std::make_shared<Demon>(spImage);
					{
						auto demon2 = std::make_shared<Demon>(spImage);
						{
							auto demon3 = std::make_shared<Demon>(spImage);

						}
					}
				}
			}
*/


//			Functor (Function Object)

//				함수와 포인터 -> 연산자 오버로딩()
//				std::function	: 펑터 생성
//				std::bind		: 펑터 & 매개변서 분리


//			정규 표현식(Regular Expression)


//			멀티 태스킹 - 본체가 여러개	( 나루토 분신술 )
//			멀티 스레드	- 본체가 1개지만 빨리 여러일을함 ( 블리치 순보 )



//			Byte Order

//			Big-Endian
//			MSB(Most Significant Byte)
//			순서대로

//			Little-Endian
//			LSB(Least Significat Byte)
//			역으로 기록
//			0x1				00 00 00 01		10 00 00 00
//			0x1234			00 00 12 34		34 12 00 00
//			0x12345678		12 34 56 78		78 56 34 12

//			ostream::write(char* s, streamsize n);
//			ostream::read(char* s, streamsize n);


//			메타데이터(meta - data)

//			length, string

//