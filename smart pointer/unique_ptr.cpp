#include <iostream>


//		������
//			: ���
//		�޸� ���� ����
//			: �Ⱦ��� �˾Ƽ� ����
//		����
//			*�� �����
//		����
//			<> ���ø�

//		std::unique_ptr
//			�����͸� �����ϰ� �ִ� ��ü�� ����
//			���� ������ x, ���� ���� x
//			�̵� ������ o, �̵� ���� o
//
//			unique_ptr::reset()		������ ����, �ʱ�ȭ
//			unique_ptr::get()		c��Ÿ�� �����͸� ��ȯ
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
	//delete pOld // ����Ʈ ������ ���� ����Ʈ �������� ����

	auto spSong = std::make_unique<MySong>(1, "BattleBGM");
	std::cout << spSong->mTrackNo << " : " << spSong->mName << std::endl;
	spSong.release();
}