#include "SingleList.h"
#include <string>
#include <iostream>

Element* SingleList::CreateElement(SingleList& list, std::string name, int hp)
{
    Element* element = new Element;

    element->mName = name;
    element->mHP = hp;
    if (list.mpTail == nullptr)
    {
        list.mpTail = list.mpHead = element;
    }
    else
    {
        list.mpTail->mpNext = element;
        list.mpTail = element;
    }
    return element;
}

void SingleList::PrintElement(SingleList& list) const
{
    Element* element = list.mpHead;
    while (element != nullptr)
    {
        std::cout << element->mName << " , " << element->mHP << std::endl;
        element = element->mpNext;
    }
}

int SingleList::Count(SingleList& list) const
{
    int count{ 0 };
    Element* element = list.mpHead;
    while (element != nullptr)
    {
        count++;
        element = element->mpNext;
    }
    std::cout << " Number of total elements : " << count << std::endl;
    return count;
}

bool SingleList::Find(const SingleList& list, std::string name)
{
    Element* element = list.mpHead;
    while (element != nullptr)
    {
        if (element->mName == name)
        {
            std::cout << "Found : " << element->mName << " , " << element->mHP << std::endl;
            return true;
        }
        else
        {
            std::cout << "404 Not Found " << std::endl;
            return false;
        }
    }
    return false;
}



bool SingleList::Delete(SingleList& list, std::string name)
{
    Element* element{ list.mpHead };
    Element* previous{ nullptr };

    while (element != nullptr)
    {
        if (element->mName == name)
        {
            break;
        }
        previous = element;
        element = element->mpNext;
    }

    if (element == nullptr)
    {
        return false;
    }

    if (list.mpHead == element)
    {
        //previous == nullptr
        list.mpHead = element->mpNext;
    }

    else if (list.mpTail == element)
    {
        //mpNext == nullptr
        list.mpTail = previous;
        previous->mpNext = nullptr;
    }
    else
    {
        previous->mpNext = element->mpNext;
    }
    if (list.mpHead == element && list.mpHead == list.mpTail)
    {
        list.mpHead = list.mpTail = nullptr;
    }
    delete element;
    return true;
}

void SingleList::Insert(SingleList& list, std::string target, std::string name, int hp)
{
    Element* element = list.mpHead;
    Element* previous = nullptr;

    while (element != nullptr)
    {
        if (target == element->mName)
        {
            break;
        }
        previous = element;
        element = element->mpNext;
    }

    Element* New_element = new Element;
    New_element->mHP = hp;
    New_element->mName = name;
    New_element->mpNext = nullptr;

    if (previous == nullptr)
    {
        // before head
        previous = New_element;
        New_element->mpNext = list.mpHead;
        list.mpHead = New_element;
    }
    else
    {
        previous->mpNext = New_element;
        New_element->mpNext = element;
    }
}
