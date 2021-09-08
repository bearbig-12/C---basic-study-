#include <iostream>
#include "DynamicQueue.h"

void Initialize(Queue& queue)
{
	queue.count = 0;
	queue.pFirst = queue.pLast = nullptr;
}

void Release(Queue& queue)
{
	Element* element = queue.pFirst;
	while (element != nullptr)
	{
		Element* next{ element->pNext };
		delete element;
		element = next;
	}
}

void Enqueue(Queue& queue, int value)
{
	Element* element = new Element;
	element->value = value;
	element->pNext = nullptr;
	if (queue.count == 0)
	{
		queue.pFirst = element;
		queue.pLast = element;
	}
	else
	{
		queue.pLast->pNext = element;
		queue.pLast = element;
	}
	queue.count++;


}

bool Dequeue(Queue& queue)
{
	if (queue.count == 0)
	{
		std::cout << "Queue is Empty" << std::endl;
		return false;
	}
	Element* element = queue.pFirst;
	std::cout << "Dequeue : " << element->value << std::endl;

	queue.pFirst = element->pNext;
	delete element;
	queue.count--;
	if (queue.count == 0)
	{
		Initialize(queue);
	}
	return true;
}

void Print(Queue& queue)
{
	Element* element = queue.pFirst;

	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->pNext;
	}
}




