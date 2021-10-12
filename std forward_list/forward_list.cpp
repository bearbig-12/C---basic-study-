#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> list{ 10, 11, 20, 21 };
	std::forward_list<int> list2{ 100,200, 10, 30, 11 };

	auto itr = std::find(list.begin(), list.end(), 21);
	
	list.splice_after(itr , list2);	//리스트 이어붙이기

	for (auto e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	for (auto e : list2)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	list.sort(std::greater<int>()); // 크면 앞으로 내림차순
	list.sort(std::less<int>());	// 작으면 앞으로 오름차순

	list.unique(); // 중복된 친구들 없애줌 하지만 선 정렬 필수

	//list.remove(11);

	//for (auto e : list)
	//{
	//	std::cout << e << std::endl;
	//}

	//auto iter = std::find(list.begin(), list.end(), 20);
	
	//list.insert_after(iter, 30);

	//for (auto e : list)
	//{
	//	std::cout << e << std::endl;
	//}
}