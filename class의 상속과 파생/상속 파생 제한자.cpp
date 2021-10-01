#include <iostream>
#include <string>

class Delveloper
{
	int mAge;
public:
	std::string name;

};

class Programmer : public Delveloper
{
public:
	void coding()
	{
		
	}
	void debuging()
	{

	}
};

class Designer : public Delveloper
{
public:
	void Draw()
	{

	}
};

class ChiefProgrammer :  public Programmer
{

};