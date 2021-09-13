#pragma once
#include <iostream>

class Point2D
{
private:
	int mX{ 0 };
	int mY{ 0 };
	int Distance;
	

public:
	void SetCoordinate(int x, int y);
	void PrintResult();
	int CalDistance(int x, int y);
};

