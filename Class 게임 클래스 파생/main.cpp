#include <iostream>
#include "Warrior.h"
class BaseClass {  };
class Myclass : public BaseClass {};



int main()
{
	
	//BaseClass* p = new Myclass();
	//Myclass* c = static_cast<Myclass*>(p);
	// ��Ÿ�ӿ� �Ұ� ����(������ virtual) ������ ����ƽ���� ����


	//Character* pHero = new Warrior;

	//Warrior *w = dynamic_cast<Warrior*>(pHero);
	// ���̳��� �ɽ�Ʈ�� ������ üũ �� ��Ÿ�ӿ� �߷��� �ʿ��Ҷ� ����ؾ���
	//if(w != nullptr) // ��ȯ ���н� nullptr�� ������
	//{
	//	w->Attack();
	//	w->DoubleSwing();
	//}
	//else
	//{
		//�ٸ� ������
	//}
	//pHero->Attack();
	//((Warrior*)pHero)->DoubleSwing(); // C��Ÿ���� ����� ����ȯ
	//delete pHero;


	//Character c1; -> ���� �����Լ��� �ֱ� ������ �ν��Ͻ�ȭ �Ұ���

	//Character* w1 = new Warrior;

	//w1->Attack();
	//w1->Move();

	//delete w1;


}