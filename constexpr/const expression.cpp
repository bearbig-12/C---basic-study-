#include <iostream>

enum Flags
{
	none = 0,
	slow = 1,
	paralyse = 2,
	sleep = 3
};

constexpr int operator|(Flags f1, Flags f2)	// ������ �ð��� ����� �Ǵ� �͵��� ��ȯ
{
	return Flags((int)f1 | (int)f2);
}

int main()
{
	/*int n{ 1 };
	constexpr int c1{ n };

	int array[c1];
	
	std::cout << n << " : " << c1 << std::endl;*/

	Flags myStatus{ none };
	switch (myStatus)
	{
	case none:
		break;
	case slow | sleep:
			break;
	default:
		break;
	}
}