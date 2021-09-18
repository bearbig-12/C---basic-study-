#include <iostream>
#include "DynamicStack.h"
#include "DynamicQueue.h"

//void PrintInformation()
//{
//	std::cout << "-----Welcome to Stack Function-----" << std::endl;
//	std::cout << "-----------------------------------" << std::endl;
//	std::cout << "[1] - PUSH " << std::endl;
//	std::cout << "[2] - POP " << std::endl;
//	std::cout << "[3] - STOP " << std::endl;
//	std::cout << "-----------------------------------" << std::endl;
//
//}

void PrintInformation()
{
	std::cout << "-----Welcome to QUEUE Function-----" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "[1] - ENQUEUE " << std::endl;
	std::cout << "[2] - DEQUEUE " << std::endl;
	std::cout << "[3] - STOP " << std::endl;
	std::cout << "-----------------------------------" << std::endl;

}

void UserInput(DynamicQueue& queue)
{
	int type{ 0 };
	int temp;

	while (true)
	{
		queue.Print(queue);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> type;
		temp = queue.GetType(queue, type);
		if (temp == 1)
		{
			int value;
			std::cout << " Push value : ";
			std::cin >> value;
			queue.Enqeue(queue, value);

		}
		else if (temp == 2)
		{
			queue.Deqeue(queue);

		}
		else if (temp == 3)
		{
			std::cout << "Stop the function" << std::endl;
			break;
		}
		else
		{
			std::cout << "Thas's not invalid type of number," << " please read information carfully" << std::endl;

		}
	}
}

int main()
{

	PrintInformation();
	DynamicQueue queue;

	UserInput(queue);
	//Stack st1;

	//st1.UserInput(st1);
}