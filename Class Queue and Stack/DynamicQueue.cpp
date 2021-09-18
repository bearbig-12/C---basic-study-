#include "DynamicQueue.h"
#include <iostream>

int DynamicQueue::GetType(DynamicQueue& queue, int type)
{
	if (type == 1)
	{
		return queue.ENQUEUE;
	}
	else if (type == 2)
	{
		return queue.DEQUEUE;
	}
	else if (type == 3)
	{
		return queue.STOP;
	}
}

void DynamicQueue::Enqeue(DynamicQueue& queue, int value)
{
	Element* element = new Element;
	element->mValue = value;
	element->mpNext = nullptr;
	if (queue.mCount == 0)
	{
		queue.mFirst = queue.mLast = element;
	}
	else
	{
		queue.mLast->mpNext = element;
		queue.mLast = element;
	}
	queue.mCount++;
}

bool DynamicQueue::Deqeue(DynamicQueue& queue)
{
	if (queue.mCount == 0)
	{
		std::cout << "Queue is Empty" << std::endl;
		return false;
	}
	Element* element = queue.mFirst;
	std::cout << "Dequeue : " << element->mValue << std::endl;

	queue.mFirst = element->mpNext;
	delete element;

	queue.mCount--;
	if (queue.mCount == 0)
	{
		queue.mFirst = queue.mLast = nullptr;
	}
	return true;
}

void DynamicQueue::Print(DynamicQueue& queue) const
{
	Element* element = queue.mFirst;

	while (element != nullptr)
	{
		std::cout << element->mValue << std::endl;
		element = element->mpNext;
	}
}
