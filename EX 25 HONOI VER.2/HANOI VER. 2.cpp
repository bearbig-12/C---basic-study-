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
	// ���� ���
	PrintInfo();
	//�ݺ�
	while (true)
	{
		//Ÿ�����
		printTowers();
		//�Է�
		std::cin >> from >> to;
		//�̵�
		if (!moveDisc(from, to))
		{
			std::cout << "�߸��� �̵��Դϴ�." << std::endl;
		}
		//Ŭ����
		if (isFinished())
		{
			std::cout << "�����մϴ� " << std::endl;
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
	std::cout << "��𿡼� ���� �ű���? : ";
}

//'a', 'b', 'c'
bool moveDisc(char from, char to)
{
	int fromIndex{ from - 'a' };
	int toIndex{ to - 'a' };
	//���� (�̵��Ҽ� ���� ���)
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
	//����
	//from�� 0���� ������ �������
	int from_disc_index = hanoiTower[fromIndex].top_index;
	if (from_disc_index == 3)
	{
		return false;
	}
	int currentDisc{hanoiTower[fromIndex].discs[from_disc_index]};

	//to�� 3���� ������ �������
	int to_disc_index = hanoiTower[toIndex].top_index;
	if (to_disc_index == 0)
	{
		return false;
	}

	//to�� ������ �� ������ ����
	if (to_disc_index != 3 && currentDisc > hanoiTower[toIndex].discs[to_disc_index])
	{
		return false;
	}

	//from���� ����
	hanoiTower[fromIndex].discs[from_disc_index] = 0;
	hanoiTower[fromIndex].top_index++;
	//to�� �߰�
	hanoiTower[toIndex].discs[to_disc_index - 1] = currentDisc;
	hanoiTower[toIndex].top_index--;

	return true;
}
bool isFinished()
{
	return (hanoiTower[2].discs[0] == 1);
}