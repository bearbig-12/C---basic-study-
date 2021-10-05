#include <iostream>

// using namespace 는 헤더파일에서는 앵간하면 쓰지말기
namespace Game
{
	namespace Character
	{
		namespace Warrior
		{
			void Print()
			{

			}
		}
	}
	class Game
	{
	public:
		
	};

	void Print()
	{
		std::cout << "Print whitch is in Game nacespace" << std::endl;
	}
}

int main()
{
	Game::Print();
	Game::Game g1;
	Game::Character::Warrior::Print();
}