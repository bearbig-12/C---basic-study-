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
		
	}
public:
	void PrintInformation();
	void UserInput(Stack& stack);

	void Initialize(Stack& stack)
	{
		stack.mCount = 0;
		stack.mTop = nullptr;
	}

	void Release(Stack& stack)
	{
		Element* element = stack.mTop;
	}
	void Push(Stack& stack, int value);
	void Pop(Stack& stack);
	void Print(const Stack& stack);

};

