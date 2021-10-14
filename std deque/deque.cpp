#include <iostream>
#include <deque>

int main()
{
	std::deque<int> deque{ 3,4,5 };

	deque.push_back(5);
	deque.push_front(1);

	for (auto e : deque)
	{
		std::cout << e << std::endl;
	}
}