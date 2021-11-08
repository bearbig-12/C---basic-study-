#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

class Sprite
{
public:
	std::string n;
	int x;
	int y;
	int w;
	int h;
};

void LoadXML(const char* filename, std::vector<Sprite>& sprites)
{
	sprites.clear();

	//파일열기
	std::ifstream ifs(filename, std::ifstream::binary);

	//정규 표현식 패턴 생성
	std::regex pattern("\"([^\"]*)\"");

	// 파일 끝가지
	while (!ifs.eof())
	{
		std::string line{};

		//한줄
		std::getline(ifs, line);

		auto result = line.find("<sprite"); // 값을 못찾은 경우 가장 마지막(인덱스?)가 들어옴 
		//std::string::npos;			// 못찾은 경우 이 인덱스가 들어옴

		if (result != std::string::npos)
		{
			//		패턴 검색
			std::sregex_iterator current(line.begin(), line.end(), pattern);
			std::sregex_iterator end;

			Sprite sprite;

			int index = 0;

			while (current != end)
			{
				// Sprite의 속성(멤버변수) 대입
				std::string token = (*current)[1];



				switch (index)
				{
				case 0:
					sprite.n = token;
					break;
				case 1:
					sprite.x = std::stoi(token);
					break;
				case 2:
					sprite.y = std::stoi(token);
					break;
				case 3:
					sprite.w = std::stoi(token);
					break;
				case 4:
					sprite.h = std::stoi(token);
					break;
				}

				current++;
				index++;
			}
			if (index > 4)
			{
				sprites.push_back(sprite);
			}
			//		일치하는 다음패턴

			//		sprite의 속성(멤머변수) 대입
		}
	}



}

int main()
{
	std::vector<Sprite> sprites;

	LoadXML("D:\\Git hub\\SimpleData\\mydata.xml", sprites);

	for (auto e : sprites)
	{
		std::cout << e.n << " : " << e.x << "," << e.y << "," <<
			e.w << "," << e.h << std::endl;
	}
}