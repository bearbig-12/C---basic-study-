#include <iostream>

//std::shared_ptr

//		��ü�� ���� x, ���� o
//		reference count�� ����

//		�ϳ��� ��ü�� �������� �����ؾ� �� ��� ���

class Image
{

};

class Demon
{
	std::shared_ptr<Image> mspImage;

public:
	Demon(std::shared_ptr<Image> img) : mspImage{ img }
	{

	}
};

int main()
{
	std::shared_ptr<Image> spImage{ std::make_shared<Image>() };

	{
		auto demon1 = std::make_shared<Demon>(spImage);
		{
			auto demon2 = std::make_shared<Demon>(spImage);
			{
				auto demon3 = std::make_shared<Demon>(spImage);

			}
		}
	}
}