#pragma once
#include <iostream>



void ODD_MBJ()
{
	int MBJ[5][5]{ 0 };
	int size{ 5 };
	int row{ 0 }, col{ 2 }, count{ 0 };
	int number{ 1 }; // 0�� �� ��� ���� ���� 1�� ����.
	
	
	
	for (int i = 0; i < size*size; ++i)
	{
		

		if (row < 0)	//���� -�� �� ������ ������(4��°��)�� �������� ����
		{
			row = size - 1;
		}
		if (col == 5)	//���� 4(�ε����� ��������)�� �Ѿ��
		{
			col -= size;
		}
		MBJ[row][col] = number;
		
		
		if (number % 5 == 0)
		{
			++row;	//	���� ���ڰ� size�� ������ ���� �ϳ� �߰��Ѵ� �̷��� ���������� 6�� 1�� ���� ������ �������ִ� ������ ���������.
			++row;	// �ٷ� �Ʒ��࿡ ���� ���ڸ� �־�� �ϱ⿡ �ؿ��� row�� ���� 1�� ���ϰ� ���� �����ؼ� row�� 2�� �����ְ� col�� 1�� ���ش�.
			--col;
		}
		++number;
		--row;	//�������� �ڽź��� ���� �������� ���� �ϳ��� Ŀ���Ƿ� ���� -1�� ���� +1��
		++col;
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			std::cout << MBJ[i][j] << "   ";
		}
		std::cout << std::endl;
	}

}