#include <iostream>

int main()
{
	

	std::string previous{ " " };
	std::string current{};
	int count{ 0 };

	while (std::cin >> current)
	{
		count++;
		if (previous == current)
		{
			std::cout << current << "�� �ߺ� �ԷµǾ����ϴ�.\n";
			std::cout << count << "��° �ܾ �ߺ��Ǿ����ϴ�.\n";
			count = 0;
		}
		previous = current;
		
	}
}