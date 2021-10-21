#include <string>



// �����̳�(Container)
//
// �ݺ���(iterator)
// ������::���Ҹ� ����Ű�� ������
// ��ȸ : ++, --
// begin(), end()

//	std::array
//	std::vector				array�� ��������
//	std::list				Double linked list		
//	std::forward_list		Single linked list
//	std::deque				����� ť

//	std::stack
//	std::queue
//	std::priority_queue		�켱���� ť �߿������� ���� ó��

//	std::set
//	std::multiset
//	std::map
//	std::multimap


// �˰���(Algorithm)






//	���ڿ� string


//		std::string

// ���Ұ� char�� �����̳�

// std::to_string(type val) // �⺻Ÿ�� -> ���ڿ�

// std::stoi(const string str, size_t* idx or pos = 0, int base = 10)	// ���ڿ� -> �⺻Ÿ�� // base = ���� size_t*, pos ���� ó���� char���� ����


// std::stod
// std::stof
//etc..


// std::wstring //�ѱ��̳� �߱��� ���� ���ڵ��� ���� Ȯ�� ��Ʈ��

		//wchar_t ch = L'��';
		//
		//std::wstring str3 = L"������";
		//
		//std::wcout << str3.length() << " : " << str3 << std::endl;
		//
		//std::cout << std::endl;

// ��������
//	std::dec		10����
//	std::hex		16����
//	std::oct		8����
//	std::boolalpha		true, false
//	std::fixed		���� �Ҽ��� 0.0001
//	std::scientific		3.14159e+00

//	std::left
//	std::right

//	ios_base::precision()	���е� �Ҽ��� �ڿ� ��° �ڸ����� ��Ÿ���ų�
//	ios_base::width()		��� �ʺ�
//	ios::fill()				������ ä�� ���ڿ�

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








//	���� vector

//	std::vector
//	������ Ÿ���� �����ؼ� Ư��ȭ
//	��ü�� ������ ũ��� ���ҵ��� �������� ���� ������
//	�������� �ε���(index)�� ���� : 0���� ����
//	�ε��� ���� [] ( subscript operator )



// ���� ��� �ݺ���
	//for (int x : v1) // [ 0 : size() )	// ������ ó������ ������ ��� ���� ������ �ε��� ���� �Ұ�
	//{
	//	std::cout << x << std::endl;
	//}

	//for (int x : v1) 
	//{
	//	x  = 0; ���� �ʱ�ȭ �Ҽ� ���� �ֳ��ϸ�  x�� v1�� �ִ� ���Ҹ� �����ϱ� �����̴� ���� ���� �����ϱ� ���ؼ��� int& x : v1�� �ʿ��ϴ�
	//}

	//for (int& x : v1) // [ 0 : size() )	// ������ ó������ ������ ��� ���� ������ �ε��� ���� �Ұ�
	//{
	//	x = 0; ����.
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
		
//		v.begin() , v.end()�� iterator Ÿ��

//		for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)	// ���� while���� ����
//		{
//
//		}

//		for (auto itr = v.begin(); itr != v.end(); itr++)
//		{
//
//		}

//	data()
//		data�� ��� ���Ҹ� �����ͷ� ������

// ---- �߿� ----
// ���ٽ�(Lambda Expression)
//	 Ư�� �Լ��� �͸� �Լ��� ���� ���							// x = 1 + 2;     1 + 2�� �͸� ��ü (Rvalue)

//		[] (int a) {};
//		[] (int x, int y) - > { return x; }


//	std::array
//		
//		���� ũ���� ���� �����̳�
//		�迭�� ���� - STL ����, ��üȭ
//			���� �����̳�
//			Ramdom Access
//			Fixed


//	std::vector

//		���� ũ���� ���� �����̳�
//			���� �����̳�
//			Random Access - ���� �������� �߰�/���Ű� ȿ����
//			Dynamic


//	std::forward_list
//		
//		���� ũ���� ���� �����̳�
//		������
//		Sequential Access (Single Linked List)


//	std::deque
//		
//		���� ũ���� ���� �����̳�
//		������
//	


//	std::stack


//	std::queue

//	std::priority_queue


//	std::set
//
//		Ư�� ������ ���� ������ ���Ҹ� ����
//		(���Ҹ� �߰��ϸ� �ڵ������� ����)
//			������(associative)
//			unique key
//			��������(ordered set)
//			Dynamic



//---------------------------------------------------------

//		std::vector
//
//			�迭 ����
//			�߰�/���� �ڿ����� �Ͼ ���

//		std::list
//
//			�߰����� ������ �Ͼ�°�� (ex: ź�����ӿ��� �Ѿ��� ���� �����̳ʷ� ����)

//		std::map

//			<key, value>
//			���� �����Ϳ� ���� �˻��� �����




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

//			[] : ĸ����
//				[] : �ܺ� ���� ��� �Ұ�
//				[=] : Call by Value;
//				[&] : Call by Reference
//				() : �Ű����� ���
//				mutable : ����
//				throw() : ����
// 
//				-> int : ��ȯŸ��
// 
//				auto expr = [](int a, int b)			//[] ĸó�� �ش� ��Ͽ� �ִ� ������ ĸó����, �ܺ� ���� ��� �Ұ� // [=] : Call by Value // [&] : Call by Reference
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
//				[](int a) -> float		// ��ȯŸ�� float
//				{
//					return 1.0f;
//				};

//			������ ����
//
//				void funtionforRef(int&& a)
//				{
//
//				}
//				int main()
//				{
//						int x;
//						funtionforRef(x);	// �������� �����ϱ⿡ �Ұ�
//						funtionforRef(1);	// �������� ���� ������ �Ұ��� ���� (���ͷ�) void funtionforRef(int&& a) �̰��� ������ ������ ���� ������ ����
// 
//				}

//				������ ������ ���� std::move() �Լ� �� a�� �������� temp�� �絵�ϴ� �뵵 // ���ο��� �Ͼ�� ���� ������ ������ �����
// 

/*					template<typename T>
					void Swap(T&& a, T&& B)	// ������ ������ ���� &&
					{
						T temp;
						temp = a;
						a = b;
						b = temp;
					}
					template<typename T>
					void Swap1(T& a, T& B)	// ������ ������ ���� std::move() �Լ� �� a�� �������� temp�� �絵�ϴ� �뵵 // ���ο��� �Ͼ�� ���� ������ ������ �����
					{
						T temp;
						temp = std::move(a);
						a = std::move(b);
						b = std::move(temp);
				
						//temp = a;
						// 1. temp ����
						// 2. a�� ���� ����ü
						// 3. ����ü�� �̸��� temp
				
						// int temp = std::move(a);
						// 3
					}
					void funtionforRef(int&& a)
					{
				
					}
					template<typename T>
					void TemplateFunction(T&& A)
					{
						funtionforRef(std::forward<T>(A));		// A�� x+x�� �Ѿ�°� �ƴ� 2�� �Ѿ�� ������ �����Ҷ� �ǹ� �״�� x+x�� �Ѱ���� �ϱ⿡ 
					}
				
					int main()
					{
						int x{ 1 };
						//funtionforRef(x);
						funtionforRef(1);	// �������� ���� ������ �Ұ��� ���� (���ͷ�) void funtionforRef(int&& a) �̰��� ������ ������ ���� ������ ����
						funtionforRef(x + x);
						TemplateFunction(x + x);
					}
*/

//			constexpr
//				const + expression

//				const										constexpr
//				������/��Ÿ�ӿ�����							������



//			Exception (����)

//------------C++ Ŭ���� ��ȭ-----------------

//		�⺻ �̵� ������ / ���� ������
//		MyClass(const MyClass&)					���� ������
//		MyClass& operator=(const MyClass&)		���� ���� ������

//		MyClass(MyClass&&)						�̵� ������ (������ ����)
//		MyClass& operatr=(MyClass&&)			�̵� ���� ������


//		Ŭ���� ���ο��� ��� �ʱ�ȭ
// 
//		class	MyClass
//		{
//			int mHp{0};
//		public:
//			MyClass() :mHp{1} {};
//		};
//
//		���� ���� ��� �������� �ʱ�ȭ�� �켱�̴�.
// 

//		Override
// 
//		�θ𿡼� virtual �ڽĿ��� override
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
//			void func1() {}	// override x - ���� virtual �Լ��� const�� �پ� �ֱ� ������ ���� �Լ��� �ƴ� void func1() {} const  �̷��� ���ָ� ����
//			void func2()	// override x
//		};

//		final
//
//		Ŭ������ �Լ��� �ڿ� final�� ���Ͻ� ����� �Ұ��� �ϰ� ���ƹ�����
//		class MyClass final
//		virtual void func1() const final {}

//		=default, =delete
//
//		class MyClass
//		{
//		public:
//			MyClass(const MyClass&) = default; - ���� �����ڸ� �⺻�����ڷ� ����ϰڴ�. / default - �⺻ ������ ������
//			MyClass(MyClass&&) = delete;	   -  �� �����ڸ� �����.
//		};

//		enum class
//
//			�̸��� ����, �ߺ� ���輺 ����
//			�⺻ 4 ����Ʈ ���� - ���� ����
//			���� �������� ������ ������ ����� ����

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

//		��ȯ Ÿ�� ���̻� 
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


//		-----����Ʈ ������------
// 
//		������
//			: ���
//		�޸� ���� ����
//			: �Ⱦ��� �˾Ƽ� ����
//		����
//			*�� �����
//		����
//			<> ���ø�

//		std::unique_ptr
//			�����͸� �����ϰ� �ִ� ��ü�� ����
//			���� ������ x, ���� ���� x
//			�̵� ������ o, �̵� ���� o
//
//			unique_ptr::reset()		������ ����, �ʱ�ȭ
//			unique_ptr::get()		c��Ÿ�� �����͸� ��ȯ
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
			//delete pOld // ����Ʈ ������ ���� ����Ʈ �������� ����
		}
*/



//		std::shared_ptr

//			��ü�� ���� x, ���� o
//			reference count�� ����
//			�ϳ��� ��ü�� �������� �����ؾ� �� ��� ���

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

//				�Լ��� ������ -> ������ �����ε�()
//				std::function	: ���� ����
//				std::bind		: ���� & �Ű����� �и�


//			���� ǥ����(Regular Expression)


//			��Ƽ �½�ŷ - ��ü�� ������	( ������ �нż� )
//			��Ƽ ������	- ��ü�� 1������ ���� ���������� ( ��ġ ���� )



//			Byte Order

//			Big-Endian
//			MSB(Most Significant Byte)
//			�������

//			Little-Endian
//			LSB(Least Significat Byte)
//			������ ���
//			0x1				00 00 00 01		10 00 00 00
//			0x1234			00 00 12 34		34 12 00 00
//			0x12345678		12 34 56 78		78 56 34 12

//			ostream::write(char* s, streamsize n);
//			ostream::read(char* s, streamsize n);


//			��Ÿ������(meta - data)

//			length, string

//