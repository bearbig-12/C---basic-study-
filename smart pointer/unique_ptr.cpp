#include <iostream>


//		소유권
//			: 명시
//		메모리 해제 시점
//			: 안쓰면 알아서 해제
//		장점
//			*이 없어요
//		단점
//			<> 템플릿

//		std::unique_ptr
//			포인터를 지정하고 있는 객체를 소유
//			복사 생성자 x, 복사 배정 x
//			이동 생성자 o, 이동 배정 o
//
//			unique_ptr::reset()		포인터 해제, 초기화
//			unique_ptr::get()		c스타일 포인터를 반환
//			unique_ptr::release()



class MyClass
{
public:
	int mValue;
};
class MySong
{
public:
	int			mTrackNo;
	std::string mName;

	MySong(int no, std::string name) : mTrackNo{ no }, mName{ name }
	{

	}
};
int main()
{
	//std::unique_ptr<MyClass> p{ new MyClass };
	/*std::unique_ptr<MyClass> p{ std::make_unique<MyClass> () };


	std::cout << p->mValue << std::endl;

	MyClass* pOld;
	pOld = p.get();*/
	//delete pOld // 스마트 포인터 쓸땐 딜리트 쓰지말기 제발

	auto spSong = std::make_unique<MySong>(1, "BattleBGM");
	std::cout << spSong->mTrackNo << " : " << spSong->mName << std::endl;
	spSong.release();
}