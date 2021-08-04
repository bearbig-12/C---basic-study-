#pragma once
#include <iostream>



void ODD_MBJ()
{
	int MBJ[5][5]{ 0 };
	int size{ 5 };
	int row{ 0 }, col{ 2 }, count{ 0 };
	int number{ 1 }; // 0번 행 가운데 열의 값은 1로 고정.
	
	
	
	for (int i = 0; i < size*size; ++i)
	{
		

		if (row < 0)	//행이 -가 돼 버릴시 마지막(4번째행)에 다음숫자 삽입
		{
			row = size - 1;
		}
		if (col == 5)	//열이 4(인덱스의 마지막값)을 넘어갈시
		{
			col -= size;
		}
		MBJ[row][col] = number;
		
		
		if (number % 5 == 0)
		{
			++row;	//	만약 숫자가 size의 배수라면 행을 하나 추가한다 이렇게 하지않으면 6이 1을 덮어 쓰듯이 먼저와있던 값들이 덮어쓰여진다.
			++row;	// 바로 아래행에 다음 숫자를 넣어야 하기에 밑에서 row와 행을 1씩 더하고 뺄걸 생각해서 row는 2를 더해주고 col은 1을 뺴준다.
			--col;
		}
		++number;
		--row;	//마방진은 자신보다 윗행 다음열의 값이 하나씩 커지므로 행은 -1씩 열은 +1씩
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