#include <iostream>
#include <vector>



int main()
{
	//std::vector<int> v1{ 1, 2, 3, 4, 5 };
	//std::vector<std::string> v2{ "doggy" , "kitty" };
	//std::vector<int> v3(5);

	/*for (int i = 0; i < v1.size(); ++i)
	{
		std::cout << v1[i] << std::endl;
	}*/
	// ���� ��� �ݺ���
	//for (int x : v1) // [ 0 : size() )	// ������ ó������ ������ ��� ���� ������ �ε��� ���� �Ұ�
	//{
	//	std::cout << x << std::endl;
	//}

	//std::vector<int> v;
	//int value;
	//int count{ 0 };
	//int average{ 0 };
	//int total{ 0 };
	//std::cout << "Please type your grade : ";
	//while (std::cin >> value)	// value�� Ÿ���� int�� �ƴҰ�� false�� �ݺ�����.
	//{
	//	
	//	v.push_back(value);
	//	++count;
	//}
	//
	//for (auto e : v)
	//{
	//	total = total + e;
	//}
	//average = total / count;
	//std::cout << "Total : " << total << " , " << " Average : " << average << std::endl;


	std::vector <int> v{ 1, 2, 3 };
	std::vector<int>::iterator itr = v.begin();

	while (itr != v.end())
	{
		std::cout << *itr;
		itr++;
	}

	//for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)	// ���� while���� ����
	//{

	//}
	for (auto itr = v.begin(); itr != v.end(); itr++)
	{

	}
}