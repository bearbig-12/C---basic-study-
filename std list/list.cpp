#include <iostream>
#include <list>

int main()
{
	std::list<int> list1{ 2,1,3,4 };
	std::list<int> list2{ 5,7,6,8,1 };

	list1.sort();
	list2.sort();

	//list1.splice(list1.end(), list2); //iterator를 사용해서 중간에 끼워서 넣을수 있음
	list1.merge(list2);					//중간에 끼워넣는 그딴거 없이 그냥 맨뒤에 붙임.	 // merge를 하기위해선 list 두개 모두 sort 해줘야함

	for (auto e : list1)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;
}