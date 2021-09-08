#include <iostream>
#include "DynamicQueue.h"


void Printinfo()
{
	std::cout << "<Queue>" << std::endl;
	std::cout << " 1 - ENQUEUE " << std::endl;
	std::cout << " 2 - DEQUEUE " << std::endl;
	std::cout << " 3 - EXIT " << std::endl;
	std::cout << "- - - - - - - - - - - - -" << std::endl;
}

void ProcessUserInput(Queue& queue)
{
	int command{ 0 };

	while (true)
	{
		Print(queue);

		std::cout << std::endl;
		std::cout << " > ";
		std::cin >> command;

		switch (command)
		{
		case ENQUEUE:
		{
			int value;
			std::cout << "		Push value : ";
			std::cin >> value;
			Enqueue(queue, value);
			break;
		}
		case DEQUEUE:
		{
			Dequeue(queue);
			break;
		}
		case EXIT:
		{
			return;
			break;
		}
		default:
			std::cout << "잘못된 명령 입니다!!" << std::endl;
			break;
		}
	}
}

int main()
{
	Queue myQueue;
	Initialize(myQueue);

	Printinfo();
	ProcessUserInput(myQueue);

	Release(myQueue);



}