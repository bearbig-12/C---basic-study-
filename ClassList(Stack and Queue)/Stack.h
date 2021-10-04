#pragma once
#include "LinkedList.h"
class Stack : LinkedList
{
	enum TYPE
	{
		mPUSH = 1,
		mPOP = 2,
		mSTOP = 3
	};
public:
	Stack()
	{
		mCount = 0;
		mpLast = nullptr;
	}
	~Stack()
	{
		Element* element = mpLast;
		Element* pNext{};

		while (element != nullptr)
		{
			pNext = element->mpNext;
			delete element;

			element = pNext;
		}
		mpLast = nullptr;
	}
public:
	void UserInput(LinkedList& list) override;
	void Create(LinkedList& list, int value) override;
	bool Delete(LinkedList& list) override;
	void Print(LinkedList& list) override;

};

