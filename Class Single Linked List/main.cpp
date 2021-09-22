#include <iostream>
#include <string>
#include "SingleList.h"


int main()
{
	SingleList list;

	list.CreateElement(list, "Gnar", 10);
	list.CreateElement(list, "Science(yasuo)", 1);
	list.CreateElement(list, "Math(YONE)", 2);
	list.CreateElement(list, "Faker", 99);

	list.PrintElement(list);

	list.Delete(list, "Gnar");

	list.PrintElement(list);

}