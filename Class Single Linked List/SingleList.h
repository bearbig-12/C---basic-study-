#pragma once
#include <string>
struct Element
{
	std::string mName;
	int mHP;
	Element* mpNext;

	Element() : mName{""}, mHP{0}, mpNext{}
	{
	}
};
class SingleList
{
private:
	Element* mpHead;
	Element* mpTail;
public:
	

	SingleList() : mpHead{nullptr}, mpTail{nullptr} {}
	~SingleList()
	{
		Element* element{ mpHead };

		while (element != nullptr)
		{
			Element* pNext = element->mpNext;
			delete element;
			element = pNext;
		}
		mpHead = mpTail = nullptr;
	}

public:
	Element* CreateElement(SingleList& list,  std::string name, int hp);
	void PrintElement(SingleList& list) const;
	int Count(SingleList& list) const;
	bool Find(const SingleList& list, std::string name);
	bool Delete(SingleList& list, std::string name);
	void Insert(SingleList& list, std::string target, std::string name, int hp);


};

