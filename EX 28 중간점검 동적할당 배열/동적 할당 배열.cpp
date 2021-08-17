#include <iostream>

void Dynamic_array()
{
	int* pNumbers = new int[5]{ 4, 8, 5, 3, 1 };

	int* p = new int[3];	// {4, 8, 5}를 넣을 배열

	for (int i = 0; i < 3; ++i)
	{
		p[i] = pNumbers[i];	// 4 8 5 삽입

	}

	delete[] pNumbers;	// 원래 배열 삭제 //삭제 안하고 대입시 포인터 오류남

	pNumbers = p;

	for (int i = 0; i < 3; ++i)
	{
		std::cout << pNumbers[i] << " , ";
	}
	delete[] p;
}

void Longest_Name()
{
	int Num_of_friends;
	std::cout << "Please insert the number of friends you have : ";
	std::cin >> Num_of_friends;

	if (Num_of_friends <= 0)
	{
		std::cout << " It could not be less that 0, please try again " << std::endl;
		return Longest_Name();
	}

	std::string* Names = new std::string[Num_of_friends];
	std::string longest_name;

	for (int i = 0; i < Num_of_friends; ++i)
	{
		std::cout << "Please insert the name of your friend : ";
		std::cin >> Names[i];
		

		if (Names[i].size() > longest_name.size() )
		{
			longest_name = Names[i];
		}
	}

	std::cout << " Friend who has longest name is : " << longest_name << std::endl;



}

int main()
{
	//Dynamic_array();
	Longest_Name();
}