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
	// 범위 기반 반복문
	//for (int x : v1) // [ 0 : size() )	// 무조건 처음부터 끝까지 모든 값을 가져옴 인덱스 접근 불가
	//{
	//	std::cout << x << std::endl;
	//}

	//std::vector<int> v;
	//int value;
	//int count{ 0 };
	//int average{ 0 };
	//int total{ 0 };
	//std::cout << "Please type your grade : ";
	//while (std::cin >> value)	// value의 타입이 int가 아닐경우 false로 반복멈춤.
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

	//for (std::vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)	// 위에 while문과 동일
	//{

	//}
	for (auto itr = v.begin(); itr != v.end(); itr++)
	{

	}
}