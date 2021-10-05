#include <iostream>
#include "Warrior.h"
class BaseClass {  };
class Myclass : public BaseClass {};



int main()
{
	
	//BaseClass* p = new Myclass();
	//Myclass* c = static_cast<Myclass*>(p);
	// 런타임에 할게 없기(다형성 virtual) 때문에 스태틱으로 가능


	//Character* pHero = new Warrior;

	//Warrior *w = dynamic_cast<Warrior*>(pHero);
	// 다이나믹 케스트는 다형성 체크 즉 런타임에 추론이 필요할때 사용해야함
	//if(w != nullptr) // 변환 실패시 nullptr이 들어가있음
	//{
	//	w->Attack();
	//	w->DoubleSwing();
	//}
	//else
	//{
		//다른 직업군
	//}
	//pHero->Attack();
	//((Warrior*)pHero)->DoubleSwing(); // C스타일의 명시적 형변환
	//delete pHero;


	//Character c1; -> 순수 가상함수가 있기 떄문에 인스턴스화 불가능

	//Character* w1 = new Warrior;

	//w1->Attack();
	//w1->Move();

	//delete w1;


}