#pragma once

enum TYPE
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};

struct Element
{
	int value;
	Element* pNext;
};

struct Queue
{
	int count{};
	Element* pFirst;
	Element* pLast;

};

void Initialize(Queue& queue);
void Release(Queue& queue);
void Enqueue(Queue& queue, int value);
bool Dequeue(Queue& queue);
void Print(Queue& queue);