#include <iostream>
#include <list>

int main()
{
	std::list<int> list1{ 2,1,3,4 };
	std::list<int> list2{ 5,7,6,8,1 };

	list1.sort();
	list2.sort();

	//list1.splice(list1.end(), list2); //iterator�� ����ؼ� �߰��� ������ ������ ����
	list1.merge(list2);					//�߰��� �����ִ� �׵��� ���� �׳� �ǵڿ� ����.	 // merge�� �ϱ����ؼ� list �ΰ� ��� sort �������

	for (auto e : list1)
	{
		std::cout << e << " ";
	}

	std::cout << std::endl;
}