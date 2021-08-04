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
			std::cout << current << "가 중복 입력되었습니다.\n";
			std::cout << count << "번째 단어가 중복되었습니다.\n";
			count = 0;
		}
		previous = current;
		
	}
}