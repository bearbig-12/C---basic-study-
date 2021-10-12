#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v;

	// 끝에서 삽입 또는 삭제.
	v.push_back(3);
	v.push_back(30);
	v.push_back(20);
	std::cout << std::endl;

	for (auto e : v)
	{
		std::cout << e << " ";

	}
	std::cout << std::endl;

	
	std::cout << "pop : " << *(v.end() - 1) << std::endl;		// v.end()는 맨마지막에 있는 \0 널문자를 가지고 있기 때문에 end를 찍으면 0이 나옴
	//std::cout << "pop : " << v[v.size() - 1] << std::endl;
	v.pop_back();

	//v.resize(5, 1); // 크기를 5로 한후 모든 원소를 1로 초기화
	//v.resize(5);	// 크기를 5로

}