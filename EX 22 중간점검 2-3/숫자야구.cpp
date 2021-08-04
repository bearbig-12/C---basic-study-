#include <iostream>
#include <random>

// Random을 이용하여 임의의 정답 구하기 동일한 숫자는 반복 x (111, 100, 999) 
// 유저의 답을 입력받을 함수 만들기
// 난수와 유저의 답을 비교할 함수 만들기

int MakeRanDomAnswer()
{
	int size{ 3 };

	int array[3]{0};

	

	std::random_device answer;
	std::mt19937 gen(answer());
	std::uniform_int_distribution<int> dis(100, 999);

	int answer1 = dis(gen);
	int answer2 = answer1;

	std::cout << std::endl;

	std::cout << "Random number is generated !! " << std::endl;

	std::cout << std::endl;


	for (int i = 2; i >= 0; --i)	//각 자리수가 중북되는지 안되는지 확일을 위한 각자리 숫자 추출
	{
		array[i] = answer1 % 10;
		answer1 /= 10;
	}
	/*for (int i = 0; i < 3; ++i)
	{
		std::cout << array[i];
	}*/

	if(array[0] == array[1] || array[1] == array [2] || array[0] == array[2])
	{
		return MakeRanDomAnswer();
	}

	
	
	return answer2;
}

void User_Input(int answer)
{
	int Input{ 0 };

	int array_answer[3]{  };
	int array_input[3]{ 0 };

	int strike{ 0 };
	int ball{ 0 };
	int out{ 0 };
	int count{ 0 }; // count가 3일씨 아웃카운트 하나 추가 -> 정답의 인덱스의 값이 인풋 인덱스의 모든값과 다르다. 
					//만약 count가 2일경우 스트라이크나 볼이 무조건 하나 있기에 아웃은 나올수없다.
	
	for (int i = 2; i >= 0; --i)	// 정답값 배열에 삽입
	{
		array_answer[i] = answer % 10;
		answer /= 10;
	}
	
	while (1)
	{
		
		strike = 0;
		ball = 0;
		out = 0;	// 매 회마다, 인풋, 배열, 스트라이크 볼 아웃 초기화

		std::cout << "There is no duplicated number such as (770, 111, or 202.)" << std::endl;
		std::cout << "Please Insert the 3 numbers u want( Each number does not duplicate ) : ";
		std::cin >> Input;

		

		for (int i = 2; i >= 0; --i)	//인풋값 배열에 삽입
		{
			array_input[i] = Input % 10;
			Input /= 10;
		}

		for (int i = 0; i < 3; ++i)
		{
			count = 0; //카운터 초기화
			for (int j = 0; j < 3; ++j)
			{
				
				if (array_answer[i] == array_input[j] && i == j)
				{
					++strike;
				}
				else if (array_answer[i] == array_input[j] && i != j)
				{
					++ball;
				}
				else if (array_answer[i] != array_input[j])
				{
					++count;
					if (count == 3)
					{
						++out;
					}
					
				}
					
			}
		}
		std::cout << "STRIKE : " << strike << " / " << " Ball : " << ball << " / " << " Out : " << out << std::endl;


		if (strike == 3)
		{
			std::cout << "User win!!!, the answer is : " << answer;
			break;
		}

	}
	
}

int main()
{
	std::cout << "\t" << " Number Baseball Game " << "\t" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Welcome to the Number Baseball Game! Please read and follow the rules below " << std::endl;
	std::cout << std::endl;
	std::cout << "Rule 1 : There is random number which has 3 place values(units, tens, hundreds) and each digit has its own number " << std::endl;
	std::cout << "Rule 2 : You need to write 3 digits number which you want (ex 128 740 or something likt that)" << std::endl;
	std::cout << "Rule 3 : If the number is same and the place value is same, it is Strike " << std::endl;
	std::cout << "Rule 4 : If the number is same but the place value is different, it is Ball " << std::endl;
	std::cout << "Rule 5 : If the number is different and0 the place value is also different, it is Out " << std::endl;
	std::cout << "Rule 6 : If you hit the 3 Strike, you win the game. " << std::endl;



	int RanDom_Answer{ 0 };
	RanDom_Answer = MakeRanDomAnswer();

	User_Input(RanDom_Answer);

}