#pragma once



class Stack
{
private:
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
	int mCount;
	Element* mTop;

	enum TYPE
	{
		mPUSH = 1,
		mPOP = 2,
		mSTOP = 3
	};
public:

	Stack()		// »ý¼ºÀÚ
	{
		mCount = 0;
		mTop = nullptr;
	}
	~Stack()
	{
		Element* element = mTop;
		Element* pNext{};
		while (element != nullptr)
		{
			pNext = element->mpNext;
			delete element;

			element = pNext;
		}
		mTop = nullptr;
	}
public:
	
	void UserInput(Stack& stack);
	void Push(Stack& stack, int value);
	void Pop(Stack& stack);
	void Print(const Stack& stack);

};

