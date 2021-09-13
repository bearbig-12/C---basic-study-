#include "Warrior.h"

enum Grade2
{

};

int main()
{
    Warrior war1, war2;
    war1.SetStatus(100, 10);
    war2.SetStatus(50, 30);

    war1.Attack();
    war2.Attack();

    Warrior::Skill skill;
    Warrior::Inventory ivy;
    Warrior::Grade grade = Warrior::Grade::Beginner;

  
}