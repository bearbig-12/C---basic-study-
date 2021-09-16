#pragma once
#include <iostream>

class Point2D
{
private:
	int mX;
	int mY;
	double Distance;
	
public:
	// 持失切
	Point2D()
	{
		mX = mY = Distance = 0;
		std::cout << "持失切" << std::endl;
	}
	~Point2D()
	{
		std::cout << "社瑚切" << std::endl;
	}

public:
	void SetCoordinate(int x, int y);
	void PrintResult();
	double CalDistance(int x, int y);
};

