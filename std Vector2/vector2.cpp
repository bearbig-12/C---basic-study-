#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v;

	// ������ ���� �Ǵ� ����.
	v.push_back(3);
	v.push_back(30);
	v.push_back(20);
	std::cout << std::endl;

	for (auto e : v)
	{
		std::cout << e << " ";

	}
	std::cout << std::endl;

	
	std::cout << "pop : " << *(v.end() - 1) << std::endl;		// v.end()�� �Ǹ������� �ִ� \0 �ι��ڸ� ������ �ֱ� ������ end�� ������ 0�� ����
	//std::cout << "pop : " << v[v.size() - 1] << std::endl;
	v.pop_back();

	//v.resize(5, 1); // ũ�⸦ 5�� ���� ��� ���Ҹ� 1�� �ʱ�ȭ
	//v.resize(5);	// ũ�⸦ 5��

}