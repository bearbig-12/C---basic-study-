#include <iostream>
#include <queue>

int main()
{
	/*std::queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);

	std::queue<int> temp(queue);

	while (!queue.empty())
	{
		std::cout << queue.front() << std::endl;
		queue.pop();
	}*/

	std::priority_queue<int> queue;

	queue.push(10);
	queue.push(5);
	queue.push(40);
	queue.push(1);

	std::priority_queue<int> temp(queue);
	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;

		temp.pop();
	}
}