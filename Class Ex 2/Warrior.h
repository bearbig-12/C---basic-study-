#pragma once
class Warrior
{
public:
    class Skill
    {

    };

    enum Grade
    {
        Beginner,
        Expert
    };
    
    struct Inventory
    {

    };
private:
    int hp;
    int dmg;
    int value;
public:
    void Attack();
    void SetStatus(int hp, int dmg);
    int SetValue() const; // 상수 멤버 함수
    
};

