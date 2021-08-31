#include <iostream>

enum Type
{
	PUSH = 1,
	POP = 2,
	STOP = 3
};

struct Queue
{
	const static int SIZE{ 10 };
	int array[SIZE]{};
	int head{ 0 };
	int tail{ 0 };
};

void PrintArray(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		std::cout << "Queue IS EMPTY" << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << "--------------QUEUE--------------" << std::endl;

	int temp = queue.head;
	while (temp != queue.tail)
	{
		temp = (temp + 1) % queue.SIZE;
		std::cout << queue.array[temp] << std::endl;
	}

	/*while (queue.head != queue.tail)	// 반복문으로 인해 head에 1의 값이 계속 더해진다 따라서 헤드의 위치가 계속 움직여서 시작 인덱스가 계속 
	{									// 증가 하기 때문에 head와 tail의 값이 1차이 밖에 나지 않기 때문에 큐가 쌓이지 않는다.
		queue.head = (queue.head + 1) % queue.SIZE;
		std::cout << queue.array[queue.head] << std::endl;
	}*/

	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl;
}

void Push(Queue& queue, int value)
{
	if ((queue.tail + 1) % queue.SIZE == queue.head)
	{
		std::cout << "Queue is Full" << std::endl;
		return;
	}
	queue.tail = (queue.tail+1) % queue.SIZE;

	queue.array[queue.tail] = value;
}

void Pop(Queue& queue)
{
	if (queue.head == queue.tail)
	{
		return;
	}
	queue.head = (queue.head + 1) % queue.SIZE;
	std::cout << "Pop : " << queue.array[queue.head] << std::endl;
}

void Queue_Input(Queue& queue)
{
	int type{ -1 };

	while (true)
	{

		PrintArray(queue);

		int value{};

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
			Push(queue, value);
		}
		else if (type == POP)
		{
			Pop(queue);
		}
		else if (type != 1 && type != 2)
		{
			std::cout << " Please type valid number (1 or 2) " << std::endl;
		}

	}


}

int main()
{
	std::cout << "Queue Info" << std::endl;
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << " 1 : Push " << std::endl;
	std::cout << " 2 : Pop " << std::endl;
	std::cout << " 3 : Stop " << std::endl;

	std::cout << "------------------------------------" << std::endl;

	Queue queue;

	Queue_Input(queue);
}

