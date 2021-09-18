#pragma once
class DynamicQueue
{
private:
	enum Type
	{
		ENQUEUE = 1,
		DEQUEUE = 2,
		STOP = 3
	};
	struct Element
	{
		int mValue;
		Element* mpNext;
		Element() : mValue{ 0 }, mpNext{ nullptr }{}

	};

	int mCount;
	Element* mFirst;
	Element* mLast;
public:
	DynamicQueue() : mCount{}, mFirst{},mLast{}
	{
		
	}
	~DynamicQueue()
	{
		Element* element = mFirst;
		while (element != nullptr)
		{
			Element* pNext = element->mpNext;
			delete element;
			element = pNext;
		}
	}

public:
	int GetType(DynamicQueue& queue, int type);
	void Enqeue(DynamicQueue& queue, int value);
	bool Deqeue(DynamicQueue& queue);
	void Print(DynamicQueue& queue) const;
	
};

