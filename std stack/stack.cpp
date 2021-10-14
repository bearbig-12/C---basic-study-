#include <iostream>
#include <stack>

int main()
{
	std::stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);


	std::stack<int> temp(stack);

	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;
		temp.pop();
	}
}