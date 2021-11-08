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

	//���Ͽ���
	std::ifstream ifs(filename, std::ifstream::binary);

	//���� ǥ���� ���� ����
	std::regex pattern("\"([^\"]*)\"");

	// ���� ������
	while (!ifs.eof())
	{
		std::string line{};

		//����
		std::getline(ifs, line);

		auto result = line.find("<sprite"); // ���� ��ã�� ��� ���� ������(�ε���?)�� ���� 
		//std::string::npos;			// ��ã�� ��� �� �ε����� ����

		if (result != std::string::npos)
		{
			//		���� �˻�
			std::sregex_iterator current(line.begin(), line.end(), pattern);
			std::sregex_iterator end;

			Sprite sprite;

			int index = 0;

			while (current != end)
			{
				// Sprite�� �Ӽ�(�������) ����
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
			//		��ġ�ϴ� ��������

			//		sprite�� �Ӽ�(��Ӻ���) ����
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