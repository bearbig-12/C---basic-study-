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
