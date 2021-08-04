#include <iostream>

int main()
{
	
	int Score[5]{ 10, 20, 15, 40, 90 };
	int Score_List[5]{ 0 };
	int Max_Grade{ 0 };
	int Min_Grade{ 0 };
	int temp;
	int Count1{ 0 };
	int Count2{ 1 };
	
	/*for (int i = 0; i < 5; ++i)
	{
		std::cout << " 점수 입력 : ";
		std::cin >> Score[i];
	}
	
	for (int i = 0; i < 5; ++i)
	{
		std::cout << " { " << Score[i] << " } ";
	}
	
	for (int i = 0; i < 5; ++i)
	{
		
		if (Score[i] > Max_Grade)
		{
			Max_Grade = Score[i];
		}
	}

	Min_Grade = Score[0];
	for (int i = 1; i < 5; ++i)
	{
		
		if (Min_Grade > Score[i])
		{
			Min_Grade = Score[i];
		}
	}


	std::cout << "최대값 : " << Max_Grade << std::endl;
	std::cout << "최솟값 : " << Min_Grade << std::endl;*/

	//2
	for (int i = 0; i < 5; ++i)
	{
		Count1 = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (Score[i] < Score[j])
			{
				++Count1;
			}
		}
		Score_List[i] = Count1 + 1;
	}
	for (int i = 0; i < 5; ++i)
	{
		std::cout << " { " << Score_List[i] << " } ";
	}


	//3
	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 5; ++j)
		{
			if (Score[i] < Score[j])
			{
				temp = Score[j];
				Score[j] = Score[i];
				Score[i] = temp;
			}
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		std::cout << " { " << Score[i] << " } ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		Score[i] = Count;
		++Count;
	}
	for (int i = 0; i < 5; ++i)
	{
		std::cout << " { " << Score[i] << " } ";
	}*/
}