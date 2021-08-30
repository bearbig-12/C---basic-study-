#include <iostream>

enum Type
{
	PUSH = 1,
	POP = 2,
	STOP = 3

};

struct Stack
{
	static const int SIZE = 10;
	int top = -1;
	int array[SIZE]{};
};

void Push(Stack& info, int value)
{
	if (info.top >= info.SIZE - 1)
	{
		std::cout << "Stack is Full" << std::endl;
		return;
	}
	info.array[++info.top] = value;
}

void Pop(Stack& info)
{
	if (info.top < 0)
	{
		std::cout << "The Stack is Empty" << std::endl;
		return;
	}
	std::cout << info.array[--info.top] << " : " << "pop" << std::endl;

}
void PrintArray(Stack& info)
{
	if (info.top < 0)
	{
		std::cout << "STACK IS EMPTY" << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	for (int i = info.top; i >= 0; --i)
	{
		std::cout << info.array[i] << std::endl;
	}
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
}
void Input(Stack& info)
{
	int type{ 0 };

	while (true)
	{

		PrintArray(info);

		int value;

		std::cout << "Type : ";
		std::cin >> type;
		std::cout << std::endl;
		if (type == 3)
		{
			break;
		}
		if (type == PUSH)
		{
			int value;
			std::cout << '\t' << "Value : ";
			std::cin >> value;
			Push(info, value);
		}
		else if (type == POP)
		{
			Pop(info);
		}
		else if (type != 1 && type != 2)
		{
			std::cout << " Please type valid number (1 or 2) " << std::endl;
		}

	}
	

}


int main()
{
	std::cout << "Stack Info" << std::endl;
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << " 1 : Push " << std::endl;
	std::cout << " 2 : Pop " << std::endl;
	std::cout << " 3 : Stop " << std::endl;

	std::cout << "------------------------------------" << std::endl;

	Stack info;

	Input(info);
}



