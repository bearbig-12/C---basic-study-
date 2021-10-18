#include <iostream>

//std::shared_ptr

//		객체를 소유 x, 참조 o
//		reference count로 추적

//		하나의 객체를 여러개가 공유해야 할 경우 사용

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