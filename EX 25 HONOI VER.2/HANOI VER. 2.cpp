#include <iostream>


struct  tower
{
	int discs[3];
	int top_index;
};

tower hanoiTower[3]
{
	{{1, 2, 3}, 0},
	{{0 ,0 ,0}, 3},
	{{0, 0, 0}, 3}
};

void PrintInfo();
void printTowers();
bool moveDisc(char from, char to);
bool isFinished();

int main()
{
	char from{ 'a' }, to{ 'a' };
	// 정보 출력
	PrintInfo();
	//반복
	while (true)
	{
		//타워출력
		printTowers();
		//입력
		std::cin >> from >> to;
		//이동
		if (!moveDisc(from, to))
		{
			std::cout << "잘못된 이동입니다." << std::endl;
		}
		//클리어
		if (isFinished())
		{
			std::cout << "축하합니다 " << std::endl;
			break;
		}
	}
		
}

void PrintInfo()
{
	std::cout << " Tower of Hanoi " << std::endl;
	std::cout << "Rule 1 : Player can move only one disc at a time " << std::endl;
	std::cout << "Rule 2 : Larger disc cannot be placed on a samll disc " << std::endl;
}
void printTowers()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << hanoiTower[j].discs[i] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "어디에서 어디로 옮길까요? : ";
}

//'a', 'b', 'c'
bool moveDisc(char from, char to)
{
	int fromIndex{ from - 'a' };
	int toIndex{ to - 'a' };
	//예외 (이동할수 없는 경우)
	//from == to
	if (fromIndex == toIndex)
	{
		return false;
	}
	// from, to : a, b, c
	if (fromIndex < 0 || fromIndex >= 3 || toIndex < 0 || toIndex >= 3)
	{
		return false;
	}
	//조건
	//from에 0개의 원판이 있을경우
	int from_disc_index = hanoiTower[fromIndex].top_index;
	if (from_disc_index == 3)
	{
		return false;
	}
	int currentDisc{hanoiTower[fromIndex].discs[from_disc_index]};

	//to에 3개의 원판이 있을경우
	int to_disc_index = hanoiTower[toIndex].top_index;
	if (to_disc_index == 0)
	{
		return false;
	}

	//to의 원판이 더 작으면 실패
	if (to_disc_index != 3 && currentDisc > hanoiTower[toIndex].discs[to_disc_index])
	{
		return false;
	}

	//from에서 제거
	hanoiTower[fromIndex].discs[from_disc_index] = 0;
	hanoiTower[fromIndex].top_index++;
	//to로 추가
	hanoiTower[toIndex].discs[to_disc_index - 1] = currentDisc;
	hanoiTower[toIndex].top_index--;

	return true;
}
bool isFinished()
{
	return (hanoiTower[2].discs[0] == 1);
}