#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"


void PrintInformation()
{
	std::cout << "-----Welcome to Information for List, Stack and Queue Function-----" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "[1] - Create(Push, Enqueue) " << std::endl;
	std::cout << "[2] - Delete(Pop, Dequeue) " << std::endl;
	std::cout << "[3] - STOP " << std::endl;
	std::cout << "-----------------------------------" << std::endl;

}


int main()
{
	PrintInformation();
	LinkedList list;
	//list.UserInput(list);
	//Stack stack;
	//stack.UserInput(list);
	Queue queue;
	queue.UserInput(list);
}