#pragma once
 
enum TYPE
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

struct Element
{
	int value{};
	Element* pNext;
};

struct Stack
{
	int count;
	Element* top;
};

void Initialize(Stack& stack);
void Release(Stack& stack);

void Push(Stack& stack, int value);
bool Pop(Stack& stack);
void Print(Stack& stack);
