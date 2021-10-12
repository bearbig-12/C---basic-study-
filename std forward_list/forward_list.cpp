#include <iostream>
#include <forward_list>

int main()
{
	std::forward_list<int> list{ 10, 11, 20, 21 };
	std::forward_list<int> list2{ 100,200, 10, 30, 11 };

	auto itr = std::find(list.begin(), list.end(), 21);
	
	list.splice_after(itr , list2);	//����Ʈ �̾���̱�

	for (auto e : list)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	for (auto e : list2)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	list.sort(std::greater<int>()); // ũ�� ������ ��������
	list.sort(std::less<int>());	// ������ ������ ��������

	list.unique(); // �ߺ��� ģ���� ������ ������ �� ���� �ʼ�

	//list.remove(11);

	//for (auto e : list)
	//{
	//	std::cout << e << std::endl;
	//}

	//auto iter = std::find(list.begin(), list.end(), 20);
	
	//list.insert_after(iter, 30);

	//for (auto e : list)
	//{
	//	std::cout << e << std::endl;
	//}
}