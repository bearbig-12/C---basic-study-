#include <iostream>
#include <string>

int main()
{
	// uniform 초기화
	int alpha{ 255 };
	int red{ 128 };
	int green{ 64 };
	int blue{ 32 };

	unsigned int color;
	// 합치기
	alpha = alpha << 24;
	red = red << 16;
	green = green << 8;
	blue;
	color = alpha | red | green | blue;

	std::cout << color << std::endl;

	// 분리
	std::cout << ((color >> 24) & 0xff) << std::endl;

	std::cout << ((color >> 16) & 0xff) << std::endl;

	std::cout << ((color >> 8) & 0xff) << std::endl;

	std::cout << (color & 0xff) << std::endl;



	
	return 0;
}