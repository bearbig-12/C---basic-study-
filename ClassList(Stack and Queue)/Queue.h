#pragma once
#include "LinkedList.h"
class Queue :
    public LinkedList
{
	enum Type
	{
		mENQUEUE = 1,
		mDEQUEUE = 2,
		mSTOP = 3
	};
public:
	Queue()
	{
		mCount = 0;
		mpFirst = nullptr;
		mpLast = nullptr;
	}
	~Queue()
	{
		Element* element = mpFirst;
		while (element != nullptr)
		{
			Element* pNext = element->mpNext;
			delete element;
			element = pNext;
		}
	}
public:
	void UserInput(LinkedList& list) override;
	void Create(LinkedList& list, int value) override;
	bool Delete(LinkedList& list) override;
	void Print(LinkedList& list) override;
};

