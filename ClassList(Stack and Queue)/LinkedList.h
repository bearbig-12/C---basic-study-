#pragma once
#include <iostream>	
#include <string>
class LinkedList
{
protected:
	struct Element
	{
		int mValue;
		Element* mpNext;
		Element()
		{
			mValue = 0;
			mpNext = nullptr;
		}
	};
	enum TYPE
	{
		mCreate = 1,
		mDelete = 2,
		mSTOP = 3
	};


public:
	int mCount;

	Element* mpFirst;
	Element* mpLast;
public:

	LinkedList() : mpFirst{} , mpLast{}, mCount{}
	{
	}
	virtual ~LinkedList()
	{
		Element* element{ mpFirst };

		while (element != nullptr)
		{
			Element* pNext = element->mpNext;
			delete element;
			element = pNext;
		}
		mpFirst = mpLast = nullptr;
	}
	virtual void UserInput(LinkedList& list);
	virtual void Create(LinkedList& list, int value);
	virtual bool Delete(LinkedList& list);
	bool Delete2(LinkedList& list, int value);
	virtual void Print(LinkedList& list);
};

