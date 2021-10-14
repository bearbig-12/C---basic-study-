#include <iostream>
#include <set>

int main()
{
	std::set<int> set;

	set.insert(1);
	set.insert(2);
	set.insert(6);
	set.insert(5);
	set.insert(1);

	for (auto e : set)
	{
		std::cout << e << std::endl;
	}
}