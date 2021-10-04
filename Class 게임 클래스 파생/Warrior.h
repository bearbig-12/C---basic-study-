#pragma once
#include "Character.h"
class Warrior : public Character
{
public:
	Warrior();
	~Warrior();

public:
	void Attack() const override;
	void Defense() override;
};

