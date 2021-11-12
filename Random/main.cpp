#include <iostream>
#include <random>
#include <vector>
int main()
{
	//srand(static_cast<unsigned int>(time(nullptr)));
	//// 유사난수( pseudo-random )

	//for (int i = 0; i < 40; ++i)
	//{
	//	// 0 ~ 32767
	//	//0~9
	//	std::cout << rand() % 10 << " ";
	//}

	//std::cout << std::endl << std::endl;

	//std::random_device rd;
	//std::mt19937 gen(rd());	// 여기서 rd()는 functor이다 함수 + 객체

	//for (int i = 0; i < 40; ++i)
	//{
	//	std::cout << gen() % 10 << " ";

	//}
	//std::cout << std::endl << std::endl;

	//std::uniform_int_distribution<> dist(0, 9);	// 균등한(균등분포) 랜덤을 만들어준다.
	//for (int i = 0; i < 40; ++i)
	//{
	//	std::cout << dist(gen) << " ";
	//}

	//TODO : SHUFFLE
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, 11);

	std::vector<int> deck{ 1,2,3,4,5,6,7,8,9,10,11,12};
	
	//for (int i = 0; i < 5; ++i)
	//{
	//	std::swap(deck[dist(gen)], deck[dist(gen)]);
	//}

	std::shuffle(deck.begin(), deck.end(), gen);

	for (auto e : deck)
	{
		
		std::cout << e << " ";
	}
}